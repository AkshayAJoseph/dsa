#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if(fork == 0) {
        exit(0);
    }
    else if (pid > 0) {
        pid = wait(NULL);
    }
    printf("Parent Process: PID = %d\n", getpid());
    printf("Child Process: PID = %d", pid);
    return 0;
}