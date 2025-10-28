#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
} NO;

typedef struct NO *ABP;

NO *alocarNO();
void liberarNO(NO *q);
ABP *criaABP();
void destroiRec(NO *no);
void destroiABP(ABP *raiz);
int estaVazia(ABP *raiz);
int insereRec(NO **raiz, int elem);
int insereElem(ABP *raiz, int elem);
int pesquisaRec(NO **raiz, int elem);
int pesquisa(ABP *raiz, int elem);
int removeRec(NO **raiz, int elem);
NO *removeAtual(NO *atual);
int removeElem(ABP *raiz, int elem);
void em_ordem(NO *raiz, int nivel);
void pre_ordem(NO *raiz, int nivel);
void pos_ordem(NO *raiz, int nivel);
void imprime(ABP *raiz);
void imprimeCaminhosFolhaAteRaiz(NO *no, int caminho[], int nivel);
void mostrarCaminhosFolhas(NO *raiz);
int contarNos(NO *raiz);
void mostrarQuantidadeNos(ABP *raiz);

#endif