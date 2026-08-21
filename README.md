# Aula 03 - Processos 

Este projeto foi desenvolvido para a disciplina IMD0036 - Sistemas Operacionais e demonstra o uso de processos em C, com foco na criação e sincronização de processos por meio da função `fork()` e `wait()`.

## Estrutura do projeto

O repositório contém duas pastas principais:

- `criacao_de_processo/`: exemplo simples de criação de um processo filho.
- `exercicio/`: exemplo mais completo com dois processos filhos e execução concorrente.

## 1) Introdução a criação de processos

Arquivo: `criacao_de_processo/criacao_de_processo.c`

Este programa aborda o comportamento básico de `fork()` e `wait()`:

- o processo atual imprime seu PID;
- o processo pai chama `fork()`;
- no processo filho, o código executa uma rotina específica e finaliza com `exit()`;
- no processo pai, o programa espera o término do filho com `wait(NULL)`;
- são exibidos os PIDs do pai e do filho para demonstrar a relação entre eles - chamadas `getpid()` e `getppid()`.

### Como compilar e executar

```bash
cd criacao_de_processo
gcc -Wall -Wextra criacao_de_processo.c -o criacao_de_processo
./criacao_de_processo
```

---

## 2) Exercício: dois filhos concorrentes

Arquivo: `exercicio/exercicio.c`
Enunciado: `exercicio/enunciado.txt`

Este código estende o conceito do primeiro exemplo e cria dois processos filhos.

### Objetivo

- criar um processo pai;
- gerar dois filhos a partir do pai;
- estudar e entender a independencia entre os processos;
- cada processo filho executa uma rotina distinta;
- o pai continua executando em paralelo.

A concorrência entre processos é uma característica central dos sistemas operacionais!

### Funcionamento

- `filho1` imprime valores de `100` a `199`;
- `filho2` imprime valores de `200` a `299`;
- o processo pai imprime sua própria sequência numérica e também continua ativo enquanto os filhos executam.

### Como compilar e executar

```bash
cd exercicio
gcc -Wall -Wextra exercicio.c -o exercicio
./exercicio
```
---

## Conceitos abordados

- criação de processos com `fork()`;
- diferença entre processo pai e processo filho;
- uso de `getpid()` e `getppid()`;
- sincronização com `wait()`;
- execução concorrente de múltiplos processos;
- identificação de processos por PID.

## Conclusão

Este projeto serviu como base para entender como os processos são criados, gerenciados e executados em um sistema operacional Linux. Os exemplos mostram como o `fork()` é usado para duplicar o fluxo de execução e como o pai e os filhos podem agir em paralelo.
