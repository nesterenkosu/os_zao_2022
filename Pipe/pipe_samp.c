# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
int main() {
    char buf[255];
    //Массив дескрипторов канала
    
    //Во FreeBSD:
    //fd[0] – дескриптор для отправки данных
    //fd[1] – дескриптор для принятия данных

    //В Fedora НАОБОРОТ
    //fd[1] - дескриптор для отправки данных
    //fd[0] - дескриптор для принятия данных
    int fd[2];

    //Создание неименованного канала
    pipe(fd);

    if(fork()>0) {//Если процесс - предок
	strcpy(buf,"Hello");
	//Отправка данных в канал
	write(fd[1],buf,6);
	//Вывод сообщения на экран
	printf( 
	    "ПРОЦЕСС-ПРЕДОК: pid=%d Отправленные данные: %s.\n",
	    getpid(),
	    buf
	);
	wait();
    }
    else {
	//Если процесс - потомок
	//Принятие данных из канала
	sleep(1);
	read(fd[0],buf,6);
	//Вывод сообщения на экран
	printf(
	    "ПРОЦЕСС-ПОТОМОК: pid=%d ppid=%d. Принятые данные: %s.\n",
	    getpid(),
	    getppid(),
	    buf
	);
    }
 return 0;
}
