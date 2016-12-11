#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
// some macros to make the code more understandable
//  regarding which pipe to use to a read/write operation
//
//  Parent: reads from P1_READ, writes on P1_WRITE
//  Child:  reads from P2_READ, writes on P2_WRITE
#define P1_READ     0
#define P2_WRITE    1
#define P2_READ     2
#define P1_WRITE    3

#define BUFF_SIZE 1024
// the total number of pipe *pairs* we need
#define NUM_PIPES   2

int main(int argc, char const *argv[])
{
	int fd[2*NUM_PIPES];

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
	
    switch(fork()) {
    	case -1: {
    		printf("Error fork()\n");
            return 1;
    	} break;
    	case 0: {	// Child process
    		char buff_child[BUFF_SIZE];

    		while(1) {
    			int recv = read(fd[0], &buff_child, BUFF_SIZE);
	    		if(recv==-1) {

	    		}else if(recv==0){

	    		} else {
	    			printf("Child 1 received: %s\n", buff_child);
	    		}
    		}
    		
    	} break;
    	default : { // parent process

    		switch(fork()) {
                case -1: { // error
                    printf("Error fork()\n");
                    return 1;
                } break;
                case 0: { // child process
                	char buff_child[BUFF_SIZE];
                    while(1) {
		    			int recv = read(fd[2], &buff_child, BUFF_SIZE);
			    		if(recv==-1) {

			    		}else if(recv==0){

			    		} else {
			    			printf("Child 2 received: %s\n", buff_child);
			    		}
		    		}
                } break;
                default: { // parent process
                    
		    		char *str = (char *)"Hello child 1";
		    		char *str2 = (char *)"Hello child 2";
		    		while(1) {
		    			printf("Parent send to Child 1: %s\n", str);
		    			if (write(fd[1], str, strlen(str)) != strlen(str)) {
					        perror("Parent: Failed to send value to child 1");
					        wait(NULL);
					        exit(EXIT_FAILURE);
						}
						printf("Parent send to Child 2: %s\n", str2);
		    			if (write(fd[3], str2, strlen(str2)) != strlen(str2)) {
					        perror("Parent: Failed to send value to child 2");
					        wait(NULL);
					        exit(EXIT_FAILURE);
						}
						sleep(2);
		    		}

                    wait(NULL); // really important. Wait to child process terminate before parent process terminate
                }
            }
    	}
    }

	return 0;
}