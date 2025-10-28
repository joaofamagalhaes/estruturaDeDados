#ifndef PILHAEST_H
#define PILHAEST_H
#define MAX_TAM 100

typedef struct
{
    int num;
} Dados;

typedef struct
{
    int qntd;
    Dados info[MAX_TAM];
} Pilha;

Pilha *criarPilha();
int tamanho(Pilha *pi);
void liberaPilha(Pilha *pi);
int estaCheia(Pilha *pi);
int estaVazia(Pilha *pi);
int inserePilha(Pilha *pi, int num);
int removePilha(Pilha *pi);
int consultaTopo(Pilha *pi);
void imprimePilha(Pilha *pi);
void imprimePilhaReverso(Pilha *pi);

#endif