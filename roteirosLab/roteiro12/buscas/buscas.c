#include "buscas.h"
#include <stdio.h>

int busca_sequencial(int *vetor, int tamanho, int chave, int *comparacoes)
{
    *comparacoes = 0;
    for (int i = 0; i < tamanho; i++)
    {
        (*comparacoes)++;
        if (vetor[i] == chave)
        {
            return i;
        }
    }
    return -1;
}

int busca_binaria(int *vetor, int tamanho, int chave, int *comparacoes)
{
    *comparacoes = 0;
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        (*comparacoes)++;
        if (vetor[meio] == chave)
        {
            return meio; // Retorna a posicao
        }
        (*comparacoes)++;
        if (vetor[meio] < chave)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int *vetor, int inicio, int fim)
{
    int pivo = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++)
    {
        if (vetor[j] < pivo)
        {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

void quick_sort(int *vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pi = particionar(vetor, inicio, fim);
        quick_sort(vetor, inicio, pi - 1);
        quick_sort(vetor, pi + 1, fim);
    }
}