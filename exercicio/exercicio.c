#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void implementacao_filho1() {
    printf("Processo filho1 criado\n");
    for(int i = 100; i <= 199; i++) {
        printf("filho1 -> PID = %d, PID pai = %d, i = %d\n", getpid(), getppid(), i);
        sleep(1);
    }
    printf("Processo filho1 finalizado\n");
}

void implementacao_filho2() {
    printf("Processo filho2 criado\n");
    for(int i = 200; i <= 299; i++) {
        printf("filho2 -> PID = %d, PID pai = %d, i = %d\n", getpid(), getppid(), i);
        sleep(1);
    }
    printf("Processo filho2 finalizado\n");
}

int main() {
    pid_t filho1, filho2;

    printf("Processo PAI (PID = %d)\n", getpid());
    filho1 = fork();
    
    if (filho1 == 0) { /*Exec de filho1*/
        implementacao_filho1();
        exit(0);
    }
    
    filho2 = fork();
    if (filho2 == 0) { /*Exec de filho2*/
        implementacao_filho2();
        exit(0);
    } else {
        for(int i = 0; i <= 50; i++) {
            printf("pai -> PID = %d, i = %d\n", getpid(), i);
            sleep(2);
        }
        printf("Processo pai finalizado\n");
    }

    return 0;
}