#include <stdio.h>
#include <stdlib.h>
#include "pilhaEst.h"

Pilha *criarPilha()
{
    Pilha *pi;
    pi = malloc(sizeof(Pilha));
    if (pi != NULL)
    {
        pi->qntd = 0;
    }
    return pi;
};

void liberaPilha(Pilha *pi)
{
    free(pi);
}

int tamanho(Pilha *pi)
{
    if (pi == NULL)
        return -1;
    else
        return pi->qntd;
}

int estaCheia(Pilha *pi)
{
    if (pi == NULL)
        return -1;
    else
        return (pi->qntd == MAX_TAM);
}

int estaVazia(Pilha *pi)
{
    if (pi == NULL)
        return -1;
    else
        return (pi->qntd == 0);
}

int inserePilha(Pilha *pi, int num)
{
    if (pi == NULL)
        return -1;
    else if (estaCheia(pi))
        return -1;
    pi->info[pi->qntd].num = num;
    pi->qntd++;
    return 1;
}

int removePilha(Pilha *pi)
{
    if (pi == NULL)
        return -1;
    else if (estaVazia(pi))
        return -1;
    pi->qntd--;
    return 1;
}

int consultaTopo(Pilha *pi)
{
    if (pi == NULL)
        return -1;
    if (estaVazia(pi))
        return -1;
    return pi->info[pi->qntd - 1].num;
}

void imprimePilha(Pilha *pi)
{
    if (pi == NULL)
        return;
    if (estaVazia(pi))
        return;
    for (int i = pi->qntd - 1; i >= 0; i--)
    {
        printf("%d \n", pi->info[i].num);
    }
}

void imprimePilhaReverso(Pilha *pi)
{
    if (pi == NULL)
        return;
    if (estaVazia(pi))
        return;
    for (int i = 0; i < pi->qntd; i++)
    {
        printf("%d \n", pi->info[i].num);
    }
}
