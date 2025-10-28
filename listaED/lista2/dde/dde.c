#include <stdio.h>
#include <stdlib.h>
#include "dde.h"

Deque *criaDeque()
{
    Deque *dq;
    dq = malloc(sizeof(Deque));
    if (dq != NULL)
    {
        dq->qntd = 0;
        dq->ini = NULL;
        dq->fim = NULL;
    }
};

NO *alocarNo()
{
    NO *no;
    no = malloc(sizeof(NO));
    if (no != NULL)
    {
        return no;
    }
}

void liberaDeque(Deque *dq)
{
    if (dq != NULL)
    {
        NO *aux;
        while (dq->ini != NULL)
        {
            aux = dq->ini;
            dq->ini = dq->ini->prox;
            free(aux);
        }
        free(dq);
    }
}

int insereIni(Deque *dq, int num)
{
    if (dq != NULL)
    {
        NO *novo = alocarNo();
        novo->num = num;
        novo->ant = NULL;
        if (estaVazio(dq))
        {
            novo->prox = NULL;
            dq->fim = novo;
        }
        else
        {
            dq->ini->ant = novo;
            novo->prox = dq->ini;
        }
        dq->ini = novo;
        dq->qntd++;
        return 1;
    }
    return 0;
};
int insereFim(Deque *dq, int num)
{
    if (dq != NULL)
    {
        NO *novo = alocarNo();
        novo->num = num;
        novo->prox = NULL;
        if (estaVazio(dq))
        {
            novo->ant = NULL;
            dq->ini = novo;
        }
        else // != null
        {
            dq->fim->prox = novo;
            novo->ant = dq->fim;
        }
        dq->fim = novo;
        dq->qntd++;
        return 1;
    }
    return 0;
};
int removeIni(Deque *dq)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        NO *aux = alocarNo();
        aux = dq->ini;
        if (dq->ini == dq->fim)
        {
            dq->fim = dq->ini = NULL;
        }
        else
        {
            dq->ini = dq->ini->prox;
            dq->ini->ant = NULL;
        }
        free(aux);
        dq->qntd--;
        return 1;
    }
    return 0;
};
int removeFim(Deque *dq)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        NO *aux = alocarNo();
        aux = dq->fim;
        if (dq->fim == dq->ini)
        {
            dq->fim = dq->ini = NULL;
        }
        else
        {
            dq->fim = dq->fim->ant;
            dq->fim->prox = NULL;
        }
        free(aux);
        dq->qntd--;
        return 1;
    }
    return 0;
};
void verInicio(Deque *dq, int *p)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        *p = dq->ini->num;
    }
};
void verFim(Deque *dq, int *p)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        *p = dq->fim->num;
    }
};
int tamanho(Deque *dq)
{
    if (dq != NULL)
    {
        return dq->qntd;
    }
};
void imprime(Deque *dq)
{
    NO *aux;
    aux = dq->ini;
    if (dq != NULL && estaVazio(dq) == 0)
    {
        while (aux != NULL)
        {
            printf("%d ", aux->num);
            aux = aux->prox;
        }
        printf("\n");
    }
    free(aux);
};
int estaVazio(Deque *dq)
{
    if (dq != NULL)
    {
        if (dq->qntd == 0)
            return 1;
    }
    return 0;
};

void excluiNegativo(Deque *dq)
{
    NO *atual = dq->ini;
    if (dq != NULL && !estaVazio(dq))
    {
        while (atual != NULL)
        {
            NO *prox = atual->prox;
            if (atual->num < 0)
            {
                if (atual->ant == NULL) // caso seja o primeiro do deque//
                {
                    dq->ini = atual->prox;
                }
                else
                {
                    atual->ant->prox = atual->prox;
                }
                if (atual->prox == NULL) // caso seja o último//
                {
                    dq->fim = atual->ant;
                }
                else
                {
                    atual->prox->ant = atual->ant;
                }
                free(atual);
                dq->qntd--;
            }
            atual = prox;
        }
    }
};
void imprimeReverso(Deque *dq)
{
    NO *aux;
    aux = dq->fim;
    if (dq != NULL && estaVazio(dq) == 0)
    {
        while (aux != NULL)
        {
            printf("%d ", aux->num);
            aux = aux->ant;
        }
        printf("\n");
    }
    free(aux);
}
