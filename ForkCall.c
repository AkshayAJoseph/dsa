#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>  // Include for pid_t

int main() {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child Process: Current Process is %d Parent process: PID = %d\n",getpid(), getppid());
    } else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }
    return 0;
}
