#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct
{
    int dados[MAX];
    int topo;
} Pilha;

Pilha *criarPilha();
void destruirPilha(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p);
int verTopo(Pilha *p, int *valor);
void imprimirPilha(Pilha *p);

#endif
