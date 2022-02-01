# include <stdio.h>
# include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[255]={0};
    
    //Открытие файла
    int fd = open("myfile.txt",O_RDWR);
    
    printf("Попытка установки блокировки ПРИ ЗАПИСИ...\n");
    
    //Блокировка файла
    
    //задание параметров блокировки
    struct flock lock;
    lock.l_type=F_WRLCK; //Тип блокировки (при записи)
    lock.l_whence=SEEK_SET;//Точка отсчёта блокируемой записи
    lock.l_start=0;//с какого байта начинается блокируемая область
    lock.l_len=0;//длина блокируемой области (в байтах)
    
    //Собственно установка блокировки
    fcntl(fd,F_SETLKW,&lock); 
        
    printf("Блокировка установлена. Выполняется заись в файл. Нажмите ENTER для завершения и снятия блокировки");getchar();
    
    //Выполнение операций по записи в файл
    //write(fd,buf,sizeof(buf));
    
    //Снятие блокировки
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    
    //Закрытие файла
    close(fd);
    
    return 0;
}
