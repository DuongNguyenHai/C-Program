#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    printf("--beginning of program\n");

    switch(fork()) {
        case -1: {  // error
            printf("Error fork()\n");
            return 1;
        } break;
        case 0: { // child process
            while(1) {
                printf("Child 1: Hello\n");
                sleep(2);
            }
        } break;
        default: { // parent process
            switch(fork()) {
                case -1: { // error
                    printf("Error fork()\n");
                    return 1;
                } break;
                case 0: { // child process
                    while(1) {
                        printf("Child 2: Hello\n");
                        sleep(2);
                    }
                } break;
                default: { // parent process
                    while(1) {
                        printf("Parent: Hello\n");
                        sleep(2);
                    }
                    wait(NULL); // really important. Wait to child process terminate before parent process terminate
                }
            }
        }

    }

    return 0;
}
