# include <stdio.h>
# include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Это программа program1. Нажмите ENTER для запуска программы program2\n");
    getchar();
    
    //Запуск program2 параллельно с program1
    if(fork()==0)
	execl("./program2","./program2",0);

    sleep(30);

    return 0;
}
