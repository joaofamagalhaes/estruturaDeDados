#include <stdio.h>
#include <stdlib.h>
#include "filaDin.h"

Fila *criarFila()
{
    Fila *fi = malloc(sizeof(Fila));
    if (fi != NULL)
    {
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

void liberarFila(Fila *fi)
{
    free(fi->fim->prox);
    free(fi->inicio->prox);
    free(fi);
}
int estaVazia(Fila *fi)
{
    if (fi == NULL)
        return 1;
    if (fi->inicio == NULL)
        return 1;
    return 0;
}
int tamanhoFila(Fila *fi)
{
    if (fi == NULL)
        return 0;
    int cont = 0;
    No *no = fi->inicio;
    while (no != NULL)
    {
        no = no->prox;
        cont++;
    }
    return cont;
}
void inserirFila(Fila *fi, int num)
{
    if (fi == NULL)
        return;

    No *novo = malloc(sizeof(No));
    if (novo == NULL)
        return;

    novo->dado = num;
    novo->prox = NULL;

    if (fi->fim == NULL)
    {
        fi->inicio = novo;
        fi->fim = novo;
    }
    else
    {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
}
void removerFila(Fila *fi)
{
    if (fi == NULL || fi->inicio == NULL)
        return;

    No *removido = fi->inicio;
    fi->inicio = fi->inicio->prox;

    if (fi->inicio == NULL)
        fi->fim = NULL;

    free(removido);
}
void imprimir(Fila *fi)
{
    if (fi == NULL || fi->inicio == NULL)
        return;

    No *atual = fi->inicio;
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}
void imprimirReverso(Fila *fi)
{
    if (fi == NULL || fi->inicio == NULL)
        return;

    int valores[1000];
    int i = 0;

    No *atual = fi->inicio;
    while (atual != NULL)
    {
        valores[i++] = atual->dado;
        atual = atual->prox;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d ", valores[j]);
    }
    printf("\n");
}
