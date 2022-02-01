# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>

void log_fork(char *message) {
    char buf[255]={0};
    
    sprintf(buf,"%d_%d.log",getpid(),getppid());
    int fd=open(buf,O_RDWR | O_APPEND | O_CREAT, 0600);
    write(fd,message,strlen(message));
    close(fd);
}

int main(int argc, char *argv[])
{
    log_fork("1\n");
    
    fork();

    log_fork("2\n");
    
    fork();
    
    log_fork("3\n");
    
    fork();
    
    log_fork("4\n");
    
    sleep(3);
    return 0;
}
