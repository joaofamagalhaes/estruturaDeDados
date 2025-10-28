#ifndef LISTA_H
#define LISTA_H

#define MAX 100

typedef struct
{
    int dados[MAX];
    int qtd;
} Lista;

Lista *criaLista();
void destroiLista(Lista *l);
int insereFim(Lista *l, int x);
int insereIni(Lista *l, int x);
int removeIni(Lista *l);
int removeFim(Lista *l);
int procura(Lista *l, int x);
int tamanho(Lista *l);
int imprime(Lista *l);
int estaVazia(Lista *l);
int estaCheia(Lista *l);

void removeOcorr(Lista *l, int x);

#endif