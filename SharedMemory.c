#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
int main() {
    int i;
    void *share_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);
    printf("Key of shared Memory is %d\n", shmid);
    share_memory = shmat(shmid, NULL, 0);
    printf("Process attached to %p\n",share_memory);
    printf("Enter string to write to shared memory")
    read(0,buff,100);
    strcpy(share_memory,buff);
    printf("You wrote %s\n",(char*)share_memory);
    return 0;
}