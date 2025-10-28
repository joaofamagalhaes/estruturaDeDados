#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

typedef struct NO
{
    int info;
    struct NO *prox;
} NO;

typedef struct
{
    int qtd;
    NO *ini;
    NO *fim;
} Fila;

Fila *criarFila();
void destruirFila(Fila *f);
int enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f);
int verInicio(Fila *f, int *valor);
void imprimirFila(Fila *f);

#endif
