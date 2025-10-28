#include <stdio.h>
#include <stdlib.h>
#include "filaEncadeada.h"

Fila *criarFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f != NULL)
    {
        f->qtd = 0;
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

void destruirFila(Fila *f)
{
    if (f != NULL)
    {
        NO *aux;
        while (f->ini != NULL)
        {
            aux = f->ini;
            f->ini = f->ini->prox;
            free(aux);
        }
        free(f);
    }
}

int enfileirar(Fila *f, int valor)
{
    if (f == NULL)
        return 0;
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL)
        return 0;
    novo->info = valor;
    novo->prox = NULL;
    if (f->fim == NULL)
    {
        f->ini = novo;
    }
    else
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->qtd++;
    return 1;
}

int desenfileirar(Fila *f)
{
    if (f == NULL || f->ini == NULL)
        return 0;
    NO *aux = f->ini;
    f->ini = f->ini->prox;
    free(aux);
    f->qtd--;
    if (f->ini == NULL)
    { // Se ficou vazia
        f->fim = NULL;
    }
    return 1;
}

int verInicio(Fila *f, int *valor)
{
    if (f == NULL || f->ini == NULL)
        return 0;
    *valor = f->ini->info;
    return 1;
}

void imprimirFila(Fila *f)
{
    if (f == NULL || f->ini == NULL)
    {
        printf("Fila vazia.\n");
        return;
    }
    NO *aux = f->ini;
    printf("Fila: ");
    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
