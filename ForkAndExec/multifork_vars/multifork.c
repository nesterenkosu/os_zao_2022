# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>

void log_fork(int v) {
    char buf[255]={0};
    
    sprintf(buf,"%d_%d.log",getpid(),getppid());
    int fd=open(buf,O_RDWR | O_APPEND | O_CREAT, 0600);
    sprintf(buf,"%d\n",v);
    write(fd,buf,strlen(buf));
    close(fd);
}

int main(int argc, char *argv[])
{
    int v;
    v = random();

    fork();
    fork();
    fork();

    log_fork(v);
    
    sleep(3);
    return 0;
}
