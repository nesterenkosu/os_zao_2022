# include <stdio.h>
# include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[255]={0};
    
    //Открытие файла
    int fd = open("myfile.txt",O_RDONLY);
    
    printf("Введите номер строки:\n");
    int s_num;
    scanf("%d",&s_num);
    
    //Перемещение виртуального курсора в заданную позицию
    lseek(fd,s_num*9,SEEK_SET);
    
    //Чтение строки из файла
    read(fd,buf,9);
    
    //Вывод строки на экран
    printf("%s\n",buf);
    
    //Закрытие файла
    close(fd);
    
    return 0;
}
