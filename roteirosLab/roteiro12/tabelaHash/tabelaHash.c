#include "tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hash_divisao(int chave, int tamanho)
{
    return chave % tamanho;
}

int hash_multiplicacao(int chave, int tamanho)
{
    double A = 0.6180339887;
    double val = chave * A;
    val = val - floor(val);
    return (int)(tamanho * val);
}

int hash_dobra(int chave, int tamanho)
{

    int p1 = chave / 1000;
    int p2 = chave % 1000;
    return (p1 + p2) % tamanho;
}

int funcao_hash(int chave, int tamanho, TipoHash tipo)
{
    switch (tipo)
    {
    case DIVISAO:
        return hash_divisao(chave, tamanho);
    case MULTIPLICACAO:
        return hash_multiplicacao(chave, tamanho);
    case DOBRA:
        return hash_dobra(chave, tamanho);
    default:
        return -1;
    }
}

TabelaHash *criar_tabela(int tamanho)
{
    TabelaHash *th = (TabelaHash *)malloc(sizeof(TabelaHash));
    th->tamanho = tamanho;
    th->tabela = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
    {
        th->tabela[i] = -1;
    }
    return th;
}

void liberar_tabela(TabelaHash *th)
{
    free(th->tabela);
    free(th);
}

void inserir(TabelaHash *th, int chave, TipoHash tipo)
{
    int pos = funcao_hash(chave, th->tamanho, tipo);

    th->tabela[pos] = chave;
}

int buscar(TabelaHash *th, int chave, TipoHash tipo)
{
    int pos = funcao_hash(chave, th->tamanho, tipo);
    if (th->tabela[pos] == chave)
    {
        return pos;
    }
    return -1;
}

void imprimir_tabela(TabelaHash *th)
{
    for (int i = 0; i < th->tamanho; i++)
    {
        printf("Pos %d: %d\n", i, th->tabela[i]);
    }
}