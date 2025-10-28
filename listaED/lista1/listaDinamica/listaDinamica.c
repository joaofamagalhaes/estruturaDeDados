#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h"

Lista *criaLista()
{
    Lista *li = malloc(sizeof(Lista));
    if (li != NULL)
    {
        li->dados = malloc(TAM * sizeof(int));
        if (li->dados == NULL)
        {
            free(li);
        }
        li->qtd = 0;
        li->capacidade = TAM;
    }
    return li;
};
void destroiLista(Lista *li)
{
    if (li != NULL)
        free(li->dados);
    free(li);
};
void insereFim(Lista *li, int x)
{
    if (li == NULL)
        return;
    if (estaCheia(li))
    {
        int novaCap = li->capacidade + TAM;
        int *novo = realloc(li->dados, novaCap * sizeof(int));
        if (novo == NULL)
            return;
        li->dados = novo;
        li->capacidade = novaCap;
    };
    li->dados[li->qtd] = x;
    printf("Dado %d inserido com sucesso na posicao '%d'!\n", li->dados[li->qtd], li->qtd);
    li->qtd++;
}
void insereIni(Lista *li, int x)
{
    if (li == NULL)
        return;
    if (estaCheia(li))
    {
        int novaCap = li->capacidade + TAM;
        int *novo = realloc(li->dados, novaCap * sizeof(int));
        if (novo == NULL)
            return;
        li->dados = novo;
        li->capacidade = novaCap;
        for (int i = li->qtd - 1; i >= 0; i--)
        {
            li->dados[i + 1] = li->dados[i];
        }
    }
    li->dados[0] = x;
    li->qtd++;
    printf("Dado %d inserido com sucesso na posicao '0'!\n", li->dados[0]);
};
void removeIni(Lista *li)
{
    if (!estaVazia(li))
    {
        for (int i = 1; i < li->qtd; i++)
        {
            li->dados[i - 1] = li->dados[i];
        }
        li->qtd--;
        printf("Dado removido com sucesso! Dado %d na posicao 0 agora.\n", li->dados[0]);
    }
    else
    {
        printf("Nao foi possivel remover o dado da lista! - Lista vazia.\n");
    }
};
void removeFim(Lista *li)
{
    if (!estaVazia(li))
    {
        li->qtd--;
        printf("Dado removido com sucesso! %d na posicao '%d'.\n", li->dados[li->qtd], li->qtd);
    }
    else
    {
        printf("Nao foi possivel remover o dado da lista! - Lista vazia.\n");
    }
};
int procura(Lista *li, int x)
{
    for (int i = 0; i < li->qtd; i++)
    {
        if (li->dados[i] == x)
        {
            printf("Dado achado com sucesso, %d na posicao '%d'!\n", li->dados[i], i);
            return li->dados[i];
        }
    }

    printf("Item nao encontrado!\n");
};
int tamanho(Lista *li)
{
    if (li == NULL)
        return -1;
    return li->qtd;
};
void imprime(Lista *li)
{
    if (li == NULL)
        return;
    for (int i = 0; i < li->qtd; i++)
    {
        printf("%d ", li->dados[i]);
    }
    printf("\n");
};
int estaVazia(Lista *li)
{
    if (li == NULL)
        return -1;
    return (li->qtd == 0);
};
int estaCheia(Lista *li)
{
    if (li == NULL)
        return -1;
    return (li->qtd == li->capacidade);
};

void removeOcorr(Lista *li, int x)
{
    if (!estaVazia(li))
    {
        int i = 0;
        while (i < li->qtd)
        {
            if (li->dados[i] == x)
            {
                for (int j = i; j < li->qtd - 1; j++)
                {
                    li->dados[j] = li->dados[j + 1];
                }
                li->qtd--;
            }
            else
            {
                i++;
            }
        }
    }
    else
    {
        printf("Nao foi possivel remover o dado da lista! - Lista vazia.\n");
    }
}

void imprimeReverso(Lista *li)
{
    if (li == NULL || li->qtd == 0)
        return;
    for (int i = li->qtd; i >= 0; i--)
        printf("%d ", li->dados[i]);
    printf("\n");
}
