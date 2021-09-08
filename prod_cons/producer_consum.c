#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000

pthread_mutex_t mutex;
pthread_cond_t condcons;
pthread_cond_t condprod;

int materials = 0;
int total_material;

void *prod()
{
  int counter = 1;
  for(int i = 0; i < SIZE; i++)
  {
    pthread_mutex_lock(&mutex);
    if(materials != 0)
    {
      pthread_cond_wait(&condprod, &mutex);
    }
      materials = counter;
      counter++;
      fprintf(stdout, "Producer = %d\n", materials);
      pthread_cond_signal(&condcons);
      pthread_mutex_unlock(&mutex);
  }
  pthread_exit(0);
}

void *cons()
{
  for(int i = 0; i < SIZE; i++)
  {
    pthread_mutex_lock(&mutex);
    if(materials == 0)
    {
      pthread_cond_wait(&condcons, &mutex);
    }
      total_material += materials;
      materials = 0;
      pthread_cond_signal(&condprod);
      pthread_mutex_unlock(&mutex);
  }
  pthread_exit(0);
}

int main(void)
{
  pthread_t pro;
  pthread_t con;
  pthread_mutex_init(&mutex, 0);
  pthread_cond_init(&condprod, 0);
  pthread_cond_init(&condcons, 0);
  pthread_create(&pro, 0, prod, 0);
  pthread_create(&con, 0, cons, 0);
  pthread_join(pro, 0);
  pthread_join(con, 0);
  pthread_cond_destroy(&condcons);
  pthread_cond_destroy(&condprod);
  pthread_mutex_destroy(&mutex);
  fprintf(stdout, "TOTAL = %d\n", total_material);
  return 0;
}
