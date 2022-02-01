# include <stdio.h>
# include <unistd.h>

int main(int argc, char *argv[])
{
    //Запуск 1-й копии текущего процесса
    fork();

    //Запуск 2-й копии текущего процесса
    fork();

    //Запуск 3-й копии текущего процесса
    fork();

    //Приостановка процесса на 30 сек
    sleep(30);
    return 0;
}
