#include <stdio.h>
#include "buscaDecre.h"

int main()
{
    int vetor[] = {100, 95, 87, 76, 65, 52, 41, 38, 29, 10, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int chave = 38;
    int resultado;

    printf("Vetor decrescente: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\nBuscando pela chave: %d\n", chave);

    printf("\n--- Teste Versao Iterativa ---\n");
    resultado = busca_binaria_dec_iterativa(vetor, tamanho, chave);
    if (resultado != -1)
    {
        printf("Elemento encontrado na posicao: %d\n", resultado);
    }
    else
    {
        printf("Elemento nao encontrado.\n");
    }

    printf("\n--- Teste Versao Recursiva ---\n");
    resultado = busca_binaria_dec_recursiva(vetor, 0, tamanho - 1, chave);
    if (resultado != -1)
    {
        printf("Elemento encontrado na posicao: %d\n", resultado);
    }
    else
    {
        printf("Elemento nao encontrado.\n");
    }

    return 0;
}