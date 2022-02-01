# include <stdio.h>
# include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[255]={0};
    
    //Открытие файла
    int fd = open("myfile.txt",O_RDWR);
    
    printf("Попытка установки блокировки ПРИ ЧТЕНИИ...\n");
    
    //Блокировка файла
    struct flock lock;
    lock.l_type=F_RDLCK; //Тип блокировки (При чтении)
    lock.l_whence=SEEK_SET;//Точка отсчёта блокируемой записи
    lock.l_start=0;//с какого байта начинается блокируемая область
    lock.l_len=0;//длина блокируемой области (в байтах)
    fcntl(fd,F_SETLKW,&lock);
    
    printf("Блокировка установлена. Выполняется ЧТЕНИЕ из файла. Нажмите ENTER для завершения и снятия блокировки");
    
    //чтение из файла
    //read(fd,buf,sizeof(buf));
    
    getchar();
    
    //Снятие блокировки
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    
    //Закрытие файла
    close(fd);
    
    return 0;
}
