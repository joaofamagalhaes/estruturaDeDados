#include <stdio.h>
#include <stdlib.h>
#include "pilhaEncadeada.h"

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL)
    {
        p->qtd = 0;
        p->topo = NULL;
    }
    return p;
}

void destruirPilha(Pilha *p)
{
    if (p != NULL)
    {
        NO *aux;
        while (p->topo != NULL)
        {
            aux = p->topo;
            p->topo = p->topo->prox;
            free(aux);
        }
        free(p);
    }
}

int empilhar(Pilha *p, int valor)
{
    if (p == NULL)
        return 0;
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL)
        return 0;
    novo->info = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->qtd++;
    return 1;
}

int desempilhar(Pilha *p)
{
    if (p == NULL || p->topo == NULL)
        return 0;
    NO *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
    p->qtd--;
    return 1;
}

int verTopo(Pilha *p, int *valor)
{
    if (p == NULL || p->topo == NULL)
        return 0;
    *valor = p->topo->info;
    return 1;
}

void imprimirPilha(Pilha *p)
{
    if (p == NULL || p->topo == NULL)
    {
        printf("Pilha vazia\n");
        return;
    }
    NO *aux = p->topo;
    printf("Pilha: ");
    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
