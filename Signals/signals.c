# include <signal.h>
# include <stdio.h>

void sigusr1_handler() {
    printf("Получен сигнал SIGUSR1\n");
}

void sigusr2_handler() {
    printf("Получен сигнал SIGUSR2\n");
}

int main() {
    signal(SIGUSR1,sigusr1_handler);
    signal(SIGUSR2,sigusr2_handler);

    getchar();
    return 0;
}
