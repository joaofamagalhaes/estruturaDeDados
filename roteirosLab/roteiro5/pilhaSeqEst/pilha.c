#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL)
    {
        p->topo = 0;
    }
    return p;
}

void destruirPilha(Pilha *p)
{
    free(p);
}

int empilhar(Pilha *p, int valor)
{
    if (p == NULL)
        return 0;
    if (p->topo == MAX)
        return 0;
    p->dados[p->topo] = valor;
    p->topo++;
    return 1;
}

int desempilhar(Pilha *p)
{
    if (p == NULL || p->topo == 0)
        return 0;
    p->topo--;
    return 1;
}

int verTopo(Pilha *p, int *valor)
{
    if (p == NULL || p->topo == 0)
        return 0;
    *valor = p->dados[p->topo - 1];
    return 1;
}

void imprimirPilha(Pilha *p)
{
    if (p == NULL || p->topo == 0)
    {
        printf("Pilha vazia\n");
        return;
    }
    printf("Pilha: ");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}
