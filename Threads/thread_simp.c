#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* func(void* temp)
{
  printf("Thread\n");
  pthread_exit(0);
}

int main()
{ 
  void* thread_data = NULL;

  pthread_t thread;

  if(pthread_create(&thread, NULL, func, thread_data) != 0)
  {
    perror("Thread create");
    exit(1);
  }

  if(pthread_join(thread, NULL) != 0)
  {
    perror("Thread create");
    exit(2);
  }

  return 0;
}
