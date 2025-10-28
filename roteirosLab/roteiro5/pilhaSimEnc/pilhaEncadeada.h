#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

typedef struct NO
{
    int info;
    struct NO *prox;
} NO;

typedef struct
{
    int qtd;
    NO *topo;
} Pilha;

Pilha *criarPilha();
void destruirPilha(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p);
int verTopo(Pilha *p, int *valor);
void imprimirPilha(Pilha *p);

#endif
