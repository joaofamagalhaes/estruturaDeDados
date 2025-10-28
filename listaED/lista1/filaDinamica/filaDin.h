#ifndef FILADIN_H
#define FILADIN_H

typedef struct no
{
    int dado;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    No *fim;
} Fila;

Fila *criarFila();
void liberarFila(Fila *fi);
int estaVazia(Fila *fi);
void inserirFila(Fila *fi, int num);
void removerFila(Fila *fi);
void imprimir(Fila *fi);
void imprimirReverso(Fila *fi);

#endif