#include <stdio.h>
#include <stdlib.h>
#include "dequeCarac.h"

Deque *criaDeque()
{
    Deque *dq = malloc(sizeof(Deque));
    if (dq != NULL)
    {
        dq->fim = dq->inicio = dq->qntd = 0;
    }

    return dq;
}
void destroiDeque(Deque *dq)
{
    if (dq != NULL)
        free(dq);
};
int insereIni(Deque *dq, char c)
{
    if (dq != NULL && estaCheio(dq) == 0)
    {
        dq->inicio = (dq->inicio <= 0) ? MAX - 1 : dq->inicio - 1;
        dq->dados[dq->inicio] = c;
        dq->qntd++;
        return 1;
    };
    return 0;
}
int insereFim(Deque *dq, char c)
{
    if (dq != NULL && estaCheio(dq) == 0)
    {
        dq->dados[dq->fim] = c;
        dq->fim = (dq->fim + 1) % MAX;
        dq->qntd++;
        return 1;
    };
    return 0;
};
int removeIni(Deque *dq)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        dq->inicio = (dq->inicio + 1) % MAX;
        dq->qntd--;
        return 1;
    };
    return 0;
};
int removeFim(Deque *dq)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        dq->fim = (dq->fim <= 0) ? MAX - 1 : dq->fim - 1;
        dq->qntd--;
        return 1;
    };
    return 0;
};
void verInicio(Deque *dq)
{
    if (dq != NULL)
    {
        printf("%c\n", dq->dados[dq->inicio]);
    }
};
void verFim(Deque *dq)
{
    if (dq != NULL)
    {
        printf("%c\n", dq->dados[(dq->fim - 1 + MAX) % MAX]);
    }
};
int tamanho(Deque *dq)
{
    if (dq != NULL)
    {
        return dq->qntd;
    }
    else
        return 0;
};
void imprime(Deque *dq)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        for (int i = 0; i < dq->qntd; i++)
        {
            int pos = (dq->inicio + i) % MAX;
            printf("%c ", dq->dados[pos]);
        }
        printf("\n");
    }
};
int estaVazio(Deque *dq)
{
    if (dq != NULL && dq->qntd == 0)
    {
        return 1;
    }
    else
        return 0;
};
int estaCheio(Deque *dq)
{

    if (dq != NULL && dq->qntd == MAX)
    {
        return 1;
    }
    else
        return 0;
};

int palindromo(Deque *dq)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        for (int i = 0; i < dq->qntd / 2; i++)
        {
            int pos = (dq->inicio + i) % MAX;
            if (dq->dados[pos] != dq->dados[(dq->fim - 1 + MAX) % MAX] - i)
            {
                printf("Nao palindromo!\n");
                return 0;
            }
        }
        return 1;
    }
};

void imprimeReverso(Deque *dq)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        for (int i = dq->qntd - 1; i >= 0; i--)
        {
            int pos = (dq->inicio + i) % MAX;
            printf("%c ", dq->dados[pos]);
        }
        printf("\n");
    }
}

int simetria(Deque *dq)
{
    if (dq != NULL && estaVazio(dq) == 0)
    {
        for (int i = 0; i < dq->qntd / 2; i++)
        {
            int pos = (dq->inicio + i) % MAX;
            if (dq->dados[pos] != dq->dados[(dq->fim - 1 - i + MAX) % MAX])
            {
                printf("Nao simetrico!\n");

                return 0;
            }
        }
        return 1;
    }
};