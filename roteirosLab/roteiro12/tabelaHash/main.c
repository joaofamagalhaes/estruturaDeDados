#include <stdio.h>
#include "tabelaHash.h"

int main()
{
    int chaves[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int n_chaves = sizeof(chaves) / sizeof(chaves[0]);

    printf("--- Testando Espalhamento com Funcao de DIVISAO ---\n");
    TabelaHash *th_div = criar_tabela(TAMANHO_TABELA);
    for (int i = 0; i < n_chaves; i++)
    {
        inserir(th_div, chaves[i], DIVISAO);
    }
    imprimir_tabela(th_div);
    printf("Buscando chave 94... Posicao: %d\n", buscar(th_div, 94, DIVISAO));
    printf("Buscando chave 100... Posicao: %d\n\n", buscar(th_div, 100, DIVISAO));
    liberar_tabela(th_div);

    printf("--- Testando Espalhamento com Funcao de MULTIPLICACAO ---\n");
    TabelaHash *th_mult = criar_tabela(TAMANHO_TABELA);
    for (int i = 0; i < n_chaves; i++)
    {
        inserir(th_mult, chaves[i], MULTIPLICACAO);
    }
    imprimir_tabela(th_mult);
    liberar_tabela(th_mult);

    printf("\n--- Testando Espalhamento com Funcao de DOBRA ---\n");
    TabelaHash *th_dobra = criar_tabela(TAMANHO_TABELA);
    int chaves_dobra[] = {123456, 789012, 112233, 445566};
    n_chaves = sizeof(chaves_dobra) / sizeof(chaves_dobra[0]);
    for (int i = 0; i < n_chaves; i++)
    {
        inserir(th_dobra, chaves_dobra[i], DOBRA);
    }
    imprimir_tabela(th_dobra);
    liberar_tabela(th_dobra);

    return 0;
}