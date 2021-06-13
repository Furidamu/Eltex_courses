#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

size_t temp = 0;

void* func(void* thread_data)
{
  for(size_t i = 0; i < 100; i++)
  {
   thread_data = temp + 1;
   printf("%ld\n", thread_data);
   temp++;
   pthread_exit(0); 
   }
} 

int main()
{
  void* thread_data = NULL;
  pthread_t* threads;
 
  if(!(threads = (pthread_t*)malloc(100 * sizeof(pthread_t))))
  {
    perror("Malloc");
    exit(1);
  }

  for(size_t i = 0; i < 100; i++)
  {
    if(pthread_create(&(threads[i]), NULL, func, thread_data) != 0)
    {
      perror("Thread create");
      exit(2);
    }
  } 

  for(size_t i = 0; i < 100; i++)
  {
    if(pthread_join(threads[i], NULL) != 0)
    {
      perror("Thread join");
      exit(3);
    }
  }

  free(threads);

  return 0;
}
