#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if(pid < 0) {
        // Fork failed
        perror("Fork failed");
    }
    else if(pid == 0) {
        printf("Child Process: Exiting\n");
        exit(0);
    } 
    else {
        sleep(20);  
    }
return 0;
}