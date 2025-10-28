#ifndef FPSE_H
#define FPSE_H

typedef struct NO
{
    int info;
    int prio;
    struct NO *prox;
} NO;

typedef struct NO *filaP;

NO alocarNO();
filaP *criaFila();
void liberaFila(filaP *fp);
int tamanho(filaP *fp);
int estaVazia(filaP *fp);
int insereElem(filaP *fp, int num, int prio);
void imprime(filaP *fp);
int conjuntoFilas(filaP *fp1, filaP *fp2);

#endif