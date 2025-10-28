#ifndef FILA_H
#define FILA_H

#define MAX 100

typedef struct
{
    int dados[MAX];
    int inicio, fim;
} Fila;

Fila *criarFila();
void destruirFila(Fila *f);
int enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f);
int verInicio(Fila *f, int *valor);
void imprimirFila(Fila *f);

#endif
