# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <stdio.h>
# include <stdio_ext.h>

int main(int argc, char *argv[])
{
    //Генерация ключа объекта
    //межпроцессного взаимодействия
    key_t key=ftok(".",'A');
    
    //Создание семафора
    int semid = semget(key,1,IPC_CREAT | IPC_EXCL | 0600);
    if(semid<0) {
	printf("Ошибка создания семафора. ");
	printf("Возможно, он уже существует\n");
	return -1;
    }
    
    //Создание разделяемой памяти объёмом 7 байт
    int shmid = shmget(key,7,IPC_CREAT | IPC_EXCL | 0600);
    if(shmid<0) {
	printf("Ошибка создания разделяемой памяти. ");
	printf("Возможно, она уже создана\n");
	return -1;
    }
 
    //Объявление переменной-указателя, через которую
    //будет происходить работа с разделяемой памятью,
    //и связывание её с разделяемой памятью.
    char *buf=(char *)shmat(shmid,NULL,0);;
    
    //Запрос пользователю на ввод строки для отправки
    //через разделяемую память
    printf("Введите строку для отправки через разделяемую память: ");

    //Считывание строки с клавиатуры
    //с одновременной её отправкой через
    //разделяемую память
    scanf("%s",buf);
    printf("Строка отправлена.\n");
    printf("Для завершения нажмите любую клавишу\n");
 
    //Ожидание нажатия на любую клавишу
    //__fpurge(stdin);getchar();

    //Установление семафора в значение 1
    struct sembuf sem_op[1];
    sem_op[0].sem_num=0;
    sem_op[0].sem_op=1;
    sem_op[0].sem_flg=0;
    semop(semid,sem_op,1);
    

 
    //Отсоединение разделяемой памяти
    shmdt(buf);
 
    //Удаление разделяемой памяти
    shmctl(shmid,IPC_RMID,0);
    return 0;
}
