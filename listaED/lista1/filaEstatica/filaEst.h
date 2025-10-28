#ifndef FILAEST_H
#define FILAEST_H
#define MAX_TAM 100
typedef struct
{
    int numero;
} Dados;

typedef struct
{
    int inicio;
    int fim;
    int qntd;
    Dados info[MAX_TAM];
} Fila;

Fila *criafila();
void liberaFila(Fila *fi);
int estaVazia(Fila *fi);
int estaCheia(Fila *fi);
void inserirFila(Fila *fi, int num);
void removerFila(Fila *fi);
void imprimir(Fila *fi);
void imprimirReverso(Fila *fi);

#endif