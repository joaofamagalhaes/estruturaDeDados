#include <stdio.h>
#include <stdlib.h>
#include "pilhaDin.h"

pilhaDin *criarPilha()
{
    pilhaDin *topo = malloc(sizeof(pilhaDin));
    if (topo != NULL)
        topo->prox = NULL;
    return topo;
}
void liberarPilha(pilhaDin *topo)
{
    if (topo == NULL)
        return;

    pilhaDin *no;
    while (topo != NULL)
    {
        no = topo;
        topo = topo->prox;
        free(no);
    }
}

int inserePilha(pilhaDin **topo, int num)
{
    pilhaDin *novo = malloc(sizeof(pilhaDin));
    if (novo == NULL)
        return -1;
    novo->info.num = num;
    novo->prox = *topo;
    *topo = novo;
    return 1;
}

int removePilha(pilhaDin **topo)
{
    if (*topo == NULL)
        return 0;

    pilhaDin *removido = *topo;
    *topo = removido->prox;
    free(removido);
    return 1;
}
void imprimirPilha(pilhaDin *topo)
{
    if (topo == NULL)
    {
        printf("Pilha vazia\n");
        return;
    }

    pilhaDin *atual = topo;
    printf("Pilha: ");
    while (atual != NULL)
    {
        printf("%d ", atual->info.num);
        atual = atual->prox;
    }
    printf("\n");
}
void imprimirReversoPilha(pilhaDin *topo)
{
    if (topo == NULL)
    {
        printf("Pilha vazia\n");
        return;
    }

    int tamanho = 0;
    pilhaDin *aux = topo;
    while (aux != NULL)
    {
        tamanho++;
        aux = aux->prox;
    }

    int *valores = malloc(tamanho * sizeof(int));
    if (valores == NULL)
    {
        return;
    }

    aux = topo;
    for (int i = 0; i < tamanho; i++)
    {
        valores[i] = aux->info.num;
        aux = aux->prox;
    }

    printf("Pilha reverso:");
    for (int i = tamanho - 1; i >= 0; i--)
    {
        printf("%d ", valores[i]);
    }
    printf("\n");

    free(valores);
}
