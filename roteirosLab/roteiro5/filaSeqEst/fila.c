#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

Fila *criarFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f != NULL)
    {
        f->inicio = 0;
        f->fim = 0;
    }
    return f;
}

void destruirFila(Fila *f)
{
    free(f);
}

int enfileirar(Fila *f, int valor)
{
    if (f == NULL)
        return 0;
    if (f->fim == MAX)
        return 0;
    f->dados[f->fim] = valor;
    f->fim++;
    return 1;
}

int desenfileirar(Fila *f)
{
    if (f == NULL)
        return 0;
    if (f->inicio == f->fim)
        return 0;
    f->inicio++;
    return 1;
}

int verInicio(Fila *f, int *valor)
{
    if (f == NULL || f->inicio == f->fim)
        return 0;
    *valor = f->dados[f->inicio];
    return 1;
}

void imprimirFila(Fila *f)
{
    if (f == NULL || f->inicio == f->fim)
    {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->inicio; i < f->fim; i++)
    {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}
