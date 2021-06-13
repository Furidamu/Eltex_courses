#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

size_t temp = 0;
pthread_mutex_t mutex;

void* func(void* thread_data)
{
  if(pthread_mutex_lock(&mutex) != 0)
  {
    perror("Mutex lock");
    exit(5);
  }
  for(size_t i = 0; i < 1; i++)
  {
   thread_data = temp + 1;
   printf("%ld\n", thread_data);
   temp++; 
   if(pthread_mutex_unlock(&mutex) != 0)
   {
    perror("Mutex unlock");
    exit(6);
   }
  }
}

int main()
{
  void* thread_data = NULL;
  pthread_t* threads;

  if(!(threads = (pthread_t*)malloc(100 * sizeof(pthread_t))))
  {
    perror("Malloc");
    exit(7);
  }

  if((pthread_mutex_init(&mutex, NULL)) != 0)
  {
    perror("Mutex init");
    exit(2);
  }

  for(size_t i = 0; i < 100; i++)
  {
    if(pthread_create(&(threads[i]), NULL, func, thread_data) != 0)
    {
      perror("Thread create");
      exit(3);
    }
  }

  for(size_t i = 0; i < 100; i++)
  {
    if(pthread_join(threads[i], NULL) != 0)
    {
      perror("Thread join");
      exit(4);
    }
  }

  pthread_mutex_destroy(&mutex);
  free(threads);

  printf("%ld\n", temp);

  return 0;
}
