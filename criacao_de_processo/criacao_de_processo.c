#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    printf("PID do processo atual: %d\n", getpid());
    pid = fork();
    
    if (pid < 0) { /*Ocorrência de erro*/
        exit(-1);
    }
    else if (pid == 0) { /*Processo filho*/
        sleep(1); /*Processo pai ganha 1s de "vantagem"*/
        printf("Processo FILHO iniciado\n");
        printf("Processo FILHO - Valor de pid retornado: %d\n", pid);
        printf("processo FILHO - PID: %d, Parent PID (PID processo PAI): %d\n", getpid(), getppid());
        printf("Fim do processo FILHO\n");
    }
    else { /*Processo pai*/
        printf("Processo PAI iniciado\n");
        printf("Processo PAI aguardando processo FILHO -> wait(NULL)\n");
        wait(NULL); /*Pai aguarda processo filho terminar*/
        printf("Processo PAI - PID: %d, PID do filho -> Valor de pid retornado: %d\n", getpid(), pid);
        
        printf("Fim do processo PAI\n");
    }
    
    return 0;
}
/*
gcc -Wall -Wextra criacao_de_processo.c -o criacao_de_processo && ./criacao_de_processo
*/
