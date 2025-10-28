
#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

ABP criaABP()
{
    return NULL;
}

void destroiRec(No *raiz)
{
    if (raiz != NULL)
    {
        destroiRec(raiz->esq);
        destroiRec(raiz->dir);
        free(raiz);
    }
}

void destroiABP(ABP *raiz)
{
    if (raiz != NULL)
    {
        destroiRec(*raiz);
        *raiz = NULL;
    }
}

int insereABP(ABP *raiz, int valor)
{
    if (*raiz == NULL)
    {
        *raiz = malloc(sizeof(No));
        if (*raiz == NULL)
            return 0;
        (*raiz)->valor = valor;
        (*raiz)->esq = (*raiz)->dir = NULL;
        return 1;
    }
    if (valor < (*raiz)->valor)
        return insereABP(&(*raiz)->esq, valor);
    else if (valor > (*raiz)->valor)
        return insereABP(&(*raiz)->dir, valor);
    return 0;
}

int buscaABP(ABP raiz, int valor)
{
    if (raiz == NULL)
        return 0;
    if (valor == raiz->valor)
        return 1;
    if (valor < raiz->valor)
        return buscaABP(raiz->esq, valor);
    else
        return buscaABP(raiz->dir, valor);
}

int removeABP(ABP *raiz, int valor)
{
    if (*raiz == NULL)
        return 0;
    if (valor < (*raiz)->valor)
        return removeABP(&(*raiz)->esq, valor);
    else if (valor > (*raiz)->valor)
        return removeABP(&(*raiz)->dir, valor);
    else
    {
        No *temp = *raiz;
        if ((*raiz)->esq == NULL)
        {
            *raiz = (*raiz)->dir;
        }
        else if ((*raiz)->dir == NULL)
        {
            *raiz = (*raiz)->esq;
        }
        else
        {
            No *pai = *raiz;
            No *sucessor = (*raiz)->dir;
            while (sucessor->esq != NULL)
            {
                pai = sucessor;
                sucessor = sucessor->esq;
            }
            (*raiz)->valor = sucessor->valor;
            if (pai->esq == sucessor)
                pai->esq = sucessor->dir;
            else
                pai->dir = sucessor->dir;
            temp = sucessor;
        }
        free(temp);
        return 1;
    }
}

void imprimeEmOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        imprimeEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimeEmOrdem(raiz->dir);
    }
}

void imprimePreOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        imprimePreOrdem(raiz->esq);
        imprimePreOrdem(raiz->dir);
    }
}

void imprimePosOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        imprimePosOrdem(raiz->esq);
        imprimePosOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

int contaNos(No *raiz)
{
    if (raiz == NULL)
        return 0;
    return 1 + contaNos(raiz->esq) + contaNos(raiz->dir);
}
