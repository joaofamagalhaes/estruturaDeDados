#ifndef TABELAHASH_H
#define TABELAHASH_H

#define TAMANHO_TABELA 13

typedef enum
{
    DIVISAO,
    MULTIPLICACAO,
    DOBRA
} TipoHash;

typedef struct
{
    int *tabela;
    int tamanho;
} TabelaHash;

TabelaHash *criar_tabela(int tamanho);
void liberar_tabela(TabelaHash *th);
void inserir(TabelaHash *th, int chave, TipoHash tipo);
int buscar(TabelaHash *th, int chave, TipoHash tipo);
void imprimir_tabela(TabelaHash *th);

#endif