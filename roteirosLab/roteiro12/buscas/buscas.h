#ifndef BUSCAS_H
#define BUSCAS_H

int busca_sequencial(int *vetor, int tamanho, int chave, int *comparacoes);
int busca_binaria(int *vetor, int tamanho, int chave, int *comparacoes);

void quick_sort(int *vetor, int inicio, int fim);

#endif