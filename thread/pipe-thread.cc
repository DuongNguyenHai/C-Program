#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  // pipe
#include <string.h>  // strlen

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;

void *functionCount1(void *);
void *functionCount2(void *);
void *functionCount3(void *);

#define BUFF_SIZE 1024
// the total number of pipe *pairs* we need
#define NUM_PIPES   2

int fd[2*NUM_PIPES];

int main() {

   pthread_t thread1, thread2, thread3;

   // Create a pair of pipe
   for (int i = 0; i < NUM_PIPES; ++i)
   {
      if (pipe(fd+i*2) < 0) {
           perror("Failed to allocate pipes");
           exit(EXIT_FAILURE);
       }
       printf("fd[%d]=%d\n", i*2, fd[i*2]);
       printf("fd[%d]=%d\n", i*2+1, fd[i*2+1]);
   }


   pthread_create( &thread1, NULL, &functionCount1, NULL);
   pthread_create( &thread2, NULL, &functionCount2, NULL);
   pthread_create( &thread3, NULL, &functionCount3, NULL);

   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);
   pthread_join( thread3, NULL);

   return 0;
}

// Write numbers 1-3 and 8-10 as permitted by functionCount2()

void *functionCount1(void *)
{
   char buff_child[BUFF_SIZE];

   while(1) {
      int recv = read(fd[0], &buff_child, BUFF_SIZE);
      if(recv==-1) {

      }else if(recv==0){

      } else {
         printf("Child 1 received: %s\n", buff_child);
      }
   }
}

void *functionCount2(void *)
{
   char buff_child[BUFF_SIZE];

   while(1) {
      int recv = read(fd[2], &buff_child, BUFF_SIZE);
      if(recv==-1) {

      }else if(recv==0){

      } else {
         printf("Child 2 received: %s\n", buff_child);
      }
   }
}
// Write numbers 4-7

void *functionCount3(void *)
{
   char *str = (char *)"Hello child 1";
   char *str2 = (char *)"Hello child 2";
   while(1) {
      printf("Parent send to Child 1: %s\n", str);
      if (write(fd[1], str, strlen(str)) != strlen(str)) {
           perror("Parent: Failed to send value to child 1");
           exit(EXIT_FAILURE);
      }
      printf("Parent send to Child 2: %s\n", str2);
      if (write(fd[3], str2, strlen(str2)) != strlen(str2)) {
           perror("Parent: Failed to send value to child 2");
           exit(EXIT_FAILURE);
      }
      sleep(2);
   }
}