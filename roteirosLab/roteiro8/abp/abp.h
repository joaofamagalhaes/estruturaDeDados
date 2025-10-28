
#ifndef ABP_H
#define ABP_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

typedef No* ABP;

ABP criaABP();
void destroiRec(No *raiz);
void destroiABP(ABP *raiz);
int insereABP(ABP *raiz, int valor);
int buscaABP(ABP raiz, int valor);
int removeABP(ABP *raiz, int valor);
void imprimeEmOrdem(No *raiz);
void imprimePreOrdem(No *raiz);
void imprimePosOrdem(No *raiz);
int contaNos(No *raiz);

#endif
