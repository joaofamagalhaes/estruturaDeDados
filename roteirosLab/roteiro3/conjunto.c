#include <stdio.h>
#include "conjunto.h"

void criaConj(Conjunto *c)
{
    c->tam = 0;
}

int inserirElem(Conjunto *c, int valor)
{
    if (c->tam >= MAXTAM)
        return 0;
    for (int i = 0; i < c->tam; i++)
    {
        if (c->elementos[i] == valor)
            return 0;
    }
    c->elementos[c->tam++] = valor;
    return 1;
}

int removerElem(Conjunto *c, int valor)
{
    for (int i = 0; i < c->tam; i++)
    {
        if (c->elementos[i] == valor)
        {
            for (int j = i; j < c->tam - 1; j++)
            {
                c->elementos[j] = c->elementos[j + 1];
            }
            c->tam--;
            return 1;
        }
    }
    return 0;
}

Conjunto uniaoConj(Conjunto c1, Conjunto c2)
{
    Conjunto result;
    criaConj(&result);
    for (int i = 0; i < c1.tam; i++)
    {
        inserirElem(&result, c1.elementos[i]);
    }
    for (int i = 0; i < c2.tam; i++)
    {
        inserirElem(&result, c2.elementos[i]);
    }
    return result;
}

Conjunto intersecaoConj(Conjunto c1, Conjunto c2)
{
    Conjunto result;
    criaConj(&result);
    for (int i = 0; i < c1.tam; i++)
    {
        for (int j = 0; j < c2.tam; j++)
        {
            if (c1.elementos[i] == c2.elementos[j])
            {
                inserirElem(&result, c1.elementos[i]);
                break;
            }
        }
    }
    return result;
}

Conjunto diferencaConj(Conjunto c1, Conjunto c2)
{
    Conjunto result;
    criaConj(&result);
    for (int i = 0; i < c1.tam; i++)
    {
        int encontrado = 0;
        for (int j = 0; j < c2.tam; j++)
        {
            if (c1.elementos[i] == c2.elementos[j])
            {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado)
        {
            inserirElem(&result, c1.elementos[i]);
        }
    }
    return result;
}

void pertenceElem(Conjunto *c, int valor)
{
    for (int i = 0; i < c->tam; i++)
    {
        if (c->elementos[i] == valor)
        {
            printf("%d pertence ao conjunto\n", valor);
            return;
        }
    }
    printf("%d nao pertence ao conjunto\n", valor);
}

int menorElem(Conjunto *c)
{
    if (c->tam == 0)
        return -1;
    int menor = c->elementos[0];
    for (int i = 1; i < c->tam; i++)
    {
        if (c->elementos[i] < menor)
            menor = c->elementos[i];
    }
    return menor;
}

int maiorElem(Conjunto *c)
{
    if (c->tam == 0)
        return -1;
    int maior = c->elementos[0];
    for (int i = 1; i < c->tam; i++)
    {
        if (c->elementos[i] > maior)
            maior = c->elementos[i];
    }
    return maior;
}

void comparaElem(Conjunto *c1, Conjunto *c2)
{
    if (c1->tam != c2->tam)
    {
        printf("Conjuntos diferentes\n");
        return;
    }
    for (int i = 0; i < c1->tam; i++)
    {
        int encontrado = 0;
        for (int j = 0; j < c2->tam; j++)
        {
            if (c1->elementos[i] == c2->elementos[j])
            {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado)
        {
            printf("Conjuntos diferentes\n");
            return;
        }
    }
    printf("Conjuntos iguais\n");
}

void tamConj(Conjunto *c)
{
    printf("Tamanho do conjunto: %d\n", c->tam);
}

void vazioConj(Conjunto *c)
{
    if (c->tam == 0)
        printf("O conjunto esta vazio\n");
    else
        printf("O conjunto nao esta vazio\n");
}