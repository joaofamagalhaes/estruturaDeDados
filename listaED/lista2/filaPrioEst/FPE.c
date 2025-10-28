#include <stdio.h>
#include <stdlib.h>
#include "FPE.h"

filaP *criaFila()
{
    filaP *fp = malloc(sizeof(filaP));
    if (fp != NULL)
    {
        fp->qntd = 0;
        return fp;
    }
};
void liberaFila(filaP *fp)
{
    if (fp != NULL)
    {
        free(fp);
    }
};
int tamanho(filaP *fp)
{
    if (fp != NULL)
    {
        return fp->qntd;
    }
};
int estaCheia(filaP *fp)
{
    if (fp != NULL && fp->qntd == MAX_TAM)
    {
        return 1;
    }
    return 0;
};
int estaVazia(filaP *fp)
{
    if (fp != NULL && fp->qntd == 0)
    {
        return 1;
    }
    return 0;
};

int insereElem(filaP *fp, int num, int prio)
{
    if (fp == NULL)
        return 0;
    if (estaCheia(fp))
        return 0;

    int i = fp->qntd - 1; // a prioridade está ao fim da fila, portanto, começo a checar por lá//
    while (i >= 0 && fp->dados[i].prioridade >= prio)
    {
        fp->dados[i + 1] = fp->dados[i]; // enquanto i for maior que 0 e a prioridade for maior ou igual a do elemento a ser inserido, os elemntos andam um espaço em direção ao fim, para dar espaço para o novo elemento ser inserido//
        i--;
    }
    fp->dados[i + 1].num = num;
    fp->dados[i + 1].prioridade = prio;
    fp->qntd++;
    return 1;
};

int removeElem(filaP *fp)
{
    if (fp == NULL)
        return 0;
    if (estaVazia(fp))
        return 0;
    fp->qntd--;
    return 1;
};

int consultaFila(filaP *fp, int *p)
{
    if (fp == NULL)
        return 0;
    if (estaVazia(fp))
        return 0;

    *p = fp->dados[fp->qntd - 1].num;
    return 1;
}

void imprime(filaP *fp)
{
    if (estaVazia(fp) || fp == NULL)
        return;

    for (int i = 0; i < fp->qntd; i++)
    {
        printf("%d - [%d] ", fp->dados[i].num, fp->dados[i].prioridade);
    }
    printf("\n");
}

int conjuntoFilas(filaP *fp1, filaP *fp2)
{
    if (fp1 == NULL || fp2 == NULL)
        return 0;

    if (fp1->qntd + fp2->qntd > MAX_TAM - 1)
        return 0;

    filaP *aux = criaFila();

    for (int i = 0; i < fp1->qntd; i++)
    {
        insereElem(aux, fp1->dados[i].num, fp1->dados[i].prioridade);
    }

    for (int i = 0; i < fp2->qntd; i++)
    {
        insereElem(aux, fp2->dados[i].num, fp2->dados[i].prioridade);
    }

    *fp1 = *aux;
    free(aux);

    return 1;
}
