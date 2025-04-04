#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
    pid_t pid = fork();

    if(pid > 0) {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());
        sleep(10);  // Sleep for 10 seconds to allow the child to exit
    } else if(pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(5);  // Simulate some work in the child process
    } 
}