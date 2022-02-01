# include <stdio.h>
# include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Это программа program1. Нажмите ENTER для запуска программы program2\n");
    getchar();
    
    //Замещение программы program1 программой program2
    execl("./program2","./program2",0);


    return 0;
}
