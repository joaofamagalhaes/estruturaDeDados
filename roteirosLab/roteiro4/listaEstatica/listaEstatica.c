#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

Lista *criaLista()
{
    Lista *li = malloc(sizeof(Lista));
    if (li != NULL)
        li->qtd = 0;
    return li;
};
void destroiLista(Lista *li)
{
    if (li != NULL)
        free(li);
};
int insereFim(Lista *li, int x)
{
    if (li == NULL)
        return -1;
    if (!estaCheia(li))
    {
        li->dados[li->qtd] = x;
        printf("Dado %d inserido com sucesso na posicao '%d'!\n", li->dados[li->qtd], li->qtd);
        li->qtd++;
    }
    else
    {
        printf("Nao foi possivel adicionar o dado a lista!\n");
    }
};
int insereIni(Lista *li, int x)
{
    if (li == NULL)
        return -1;
    if (!estaCheia(li))
    {
        for (int i = li->qtd - 1; i >= 0; i--)
        {
            li->dados[i + 1] = li->dados[i];
        }
        li->dados[0] = x;
        li->qtd++;
        printf("Dado %d inserido com sucesso na posicao '0'!\n", li->dados[0]);
    }
    else
    {
        printf("Nao foi possivel adicionar o dado a lista!\n");
    }
};
int removeIni(Lista *li)
{
    if (!estaVazia(li))
    {
        for (int i = 1; i <= MAX; i++)
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
int removeFim(Lista *li)
{
    if (!estaVazia(li))
    {
        li->dados[li->qtd] = 0;
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
int imprime(Lista *li)
{
    if (li == NULL)
        return -1;
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
    return (li->qtd == MAX);
};

void removeOcorr(Lista *li, int x)
{
    if (!estaVazia(li))
    {
        for (int i = 0; i < li->qtd; i++)
        {
            if (li->dados[i] == x)
            {
                for (int j = i; j < li->qtd; j++)
                {
                    li->dados[j] = li->dados[j + 1];
                }
            }
        }

        li->qtd--;
    }
    else
    {
        printf("Nao foi possivel remover o dado da lista! - Lista vazia.\n");
    }
}