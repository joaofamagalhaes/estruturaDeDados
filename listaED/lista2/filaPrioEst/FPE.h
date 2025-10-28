#ifndef FPE_H
#define FPE_H

#define MAX_TAM 100
typedef struct NO
{
    int num;
    int prioridade;
} NO;

typedef struct
{
    int qntd;
    NO dados[MAX_TAM];
} filaP;

filaP *criaFila();
void liberaFila(filaP *fp);
int tamanho(filaP *fp);
int estaCheia(filaP *fp);
int estaVazia(filaP *fp);
int insereElem(filaP *fp, int num, int prio);
void imprime(filaP *fp);
int conjuntoFilas(filaP *fp1, filaP *fp2);

#endif