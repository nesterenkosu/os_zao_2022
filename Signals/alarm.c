#include <signal.h>
#include <stdio.h>

void alarm_handler() {
    printf("Получен сигнал таймера\n");
    alarm(3);
}

int main() {
    signal(SIGALRM,alarm_handler);
    alarm(3);
    getchar();
    return 0;
}

