#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#define TAM 100

typedef struct
{
    int *dados;
    int qtd;
    int capacidade;

} Lista;

Lista *criaLista();
void destroiLista(Lista *l);
void insereFim(Lista *l, int x);
void insereIni(Lista *l, int x);
void removeIni(Lista *l);
void removeFim(Lista *l);
int procura(Lista *l, int x);
int tamanho(Lista *l);
void imprime(Lista *l);
int estaVazia(Lista *l);
int estaCheia(Lista *l);

void removeOcorr(Lista *l, int x);
void imprimeReverso(Lista *l);
#endif