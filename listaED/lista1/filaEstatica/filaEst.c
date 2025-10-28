#include <stdio.h>
#include <stdlib.h>
#include "filaEst.h"

Fila *criafila()
{
    Fila *fi = malloc(sizeof(Fila));
    if (fi != NULL)
    {
        fi->inicio = 0;
        fi->fim = 0;
        fi->qntd = 0;
    }
    return fi;
}

void liberaFila(Fila *fi)
{
    free(fi);
}
int estaVazia(Fila *fi)
{
    if (fi->qntd == 0)
        return 1;
    else
        return 0;
}
int estaCheia(Fila *fi)
{
    if (fi->qntd == MAX_TAM)
        return 1;
    else
        return 0;
}

void inserirFila(Fila *fi, int num)
{
    if (estaCheia(fi) || fi == NULL)
        return;
    fi->info[fi->fim].numero = num;
    fi->fim = (fi->fim + 1) % MAX_TAM;
    fi->qntd++;
}

void removerFila(Fila *fi)
{
    if (estaVazia(fi) || fi == NULL)
        return;
    fi->inicio = (fi->inicio + 1) % MAX_TAM;
    fi->qntd--;
}

void imprimir(Fila *fi)
{
    if (estaVazia(fi) || fi == NULL)
        return;

    for (int i = 0; i < fi->qntd; i++)
    {
        int index = (fi->inicio + i) % MAX_TAM;
        printf("%d ", fi->info[index].numero);
    }
    printf("\n");
}

void imprimirReverso(Fila *fi)
{
    if (estaVazia(fi) || fi == NULL)
        return;

    for (int i = fi->qntd - 1; i >= 0; i--)
    {
        int index = (fi->inicio + i) % MAX_TAM;
        printf("%d ", fi->info[index].numero);
    }
    printf("\n");
}
