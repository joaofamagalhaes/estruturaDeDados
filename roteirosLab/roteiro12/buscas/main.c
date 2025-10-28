#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buscas.h"

#define TAMANHO_VETOR 20

int main()
{
    int vetor[TAMANHO_VETOR];
    int comparacoes;
    int resultado;
    int chave;
    clock_t inicio, fim;
    double tempo_gasto;

    srand(time(NULL));
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        vetor[i] = rand() % 100;
    }

    printf("Vetor original: ");
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    chave = vetor[TAMANHO_VETOR - 5];
    printf("\n--- Teste Busca Sequencial ---\n");
    printf("Buscando pela chave: %d\n", chave);

    inicio = clock();
    resultado = busca_sequencial(vetor, TAMANHO_VETOR, chave, &comparacoes);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    if (resultado != -1)
    {
        printf("Elemento encontrado na posicao: %d\n", resultado);
    }
    else
    {
        printf("Elemento nao encontrado.\n");
    }
    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Tempo de execucao: %f segundos\n", tempo_gasto);

    printf("\n--- Teste Busca Binaria ---\n");
    printf("Ordenando o vetor para a busca binaria...\n");
    quick_sort(vetor, 0, TAMANHO_VETOR - 1);

    printf("Vetor ordenado: ");
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Buscando pela chave: %d\n", chave);

    inicio = clock();
    resultado = busca_binaria(vetor, TAMANHO_VETOR, chave, &comparacoes);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    if (resultado != -1)
    {
        printf("Elemento encontrado na posicao: %d\n", resultado);
    }
    else
    {
        printf("Elemento nao encontrado.\n");
    }
    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Tempo de execucao: %f segundos\n", tempo_gasto);

    return 0;
}