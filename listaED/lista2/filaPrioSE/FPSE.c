#include <stdio.h>
#include <stdlib.h>
#include "FPSE.h"

filaP *criaFila()
{
    filaP *fp = malloc(sizeof(filaP));
    if (fp != NULL)
    {

        *fp = NULL;
        return fp;
    }
}
void liberaFila(filaP *fp)
{
    while ((*fp) != NULL)
    {
        NO *aux = *fp;
        *fp = (*fp)->prox;
        free(aux);
    }
    free(fp);
};
int tamanho(filaP *fp)
{
    if (fp == NULL)
        return -1;
    int tam = 0;
    NO *aux = *fp;
    while (aux != NULL)
    {
        aux = aux->prox;
        tam++;
    }
    return tam;
};
int estaVazia(filaP *fp)
{
    if (fp == NULL)
        return -1;
    if (*fp == NULL)
        return 1;
    else
        return 0;
};
int insereElem(filaP *fp, int num, int prio)
{
    if (fp == NULL)
        return 0;
    filaP novo = malloc(sizeof(NO));
    if (novo == NULL)
        return 0;
    novo->info = num;
    novo->prio = prio;
    novo->prox = NULL;

    if (*fp == NULL || (*fp)->prio < prio) // insere no início//
    {
        novo->prox = *fp;
        *fp = novo;
        return 1;
    }

    filaP atual = *fp;
    while (atual->prox != NULL && atual->prox->prio >= prio) // pesquisa pelo local certo para inserir//
    {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;

    return 1;
};
void imprime(filaP *fp)
{

    if (fp == NULL)
        return;
    filaP aux = *fp;
    while (aux != NULL)
    {
        printf("Num %d - Prio %d | ", aux->info, aux->prio);
        aux = aux->prox;
    }
    printf("\n");
};
int conjuntoFilas(filaP *fp1, filaP *fp2)
{
    if (fp1 == NULL || fp2 == NULL)
        return 0;

    filaP atual;
    atual = *fp2;
    while (atual != NULL)
    {
        insereElem(fp1, atual->info, atual->prio);
        atual = atual->prox;
    }
    return 1;
};
