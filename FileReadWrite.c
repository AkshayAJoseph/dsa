#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void main() {
    int fr, fd, n;
    char buff[20];
    fd = open("text.txt",O_RDONLY);
    printf("The description of the file is %d",fd);
    n = read(fd,buff,10);
    fr = open("r.txt",O_WRONLY | O_CREAT);
    n = write(fr,buff,n);
    close(fr);
    close(fd);
}