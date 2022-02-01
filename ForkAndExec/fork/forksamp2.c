# include <stdio.h>
# include <string.h>

int main(int argc, char *argv[])
{
    char buf[255]={0};

    int ret;

    ret = fork();
    if(ret > 0) {
	//Предок
	sprintf(buf,"Это предок. PID=[%d]\n",getpid());
	write(1,buf,strlen(buf));
    }else if(ret==0){
	sleep(1);
	//Потомок
	sprintf(buf,"Это потомок. PID=[%d]\n",getpid());
	write(1,buf,strlen(buf));
    }else{ //ret<0
	printf("Ошибка запуска дочернего процесса\n");
    }

    return 0;
}
