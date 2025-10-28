
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp_aluno.h"

ABP criaABP() {
    return NULL;
}

void destroiRec(No *raiz) {
    if (raiz != NULL) {
        destroiRec(raiz->esq);
        destroiRec(raiz->dir);
        free(raiz);
    }
}

void destroiABP(ABP *raiz) {
    if (raiz != NULL) {
        destroiRec(*raiz);
        *raiz = NULL;
    }
}

int insereABP(ABP *raiz, Aluno a) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(No));
        if (*raiz == NULL) return 0;
        (*raiz)->dado = a;
        (*raiz)->esq = (*raiz)->dir = NULL;
        return 1;
    }

    int cmp = strcmp(a.nome, (*raiz)->dado.nome);
    if (cmp < 0)
        return insereABP(&(*raiz)->esq, a);
    else if (cmp > 0)
        return insereABP(&(*raiz)->dir, a);
    return 0;
}

No *buscaABP(ABP raiz, char nome[]) {
    if (raiz == NULL) return NULL;

    int cmp = strcmp(nome, raiz->dado.nome);
    if (cmp == 0)
        return raiz;
    else if (cmp < 0)
        return buscaABP(raiz->esq, nome);
    else
        return buscaABP(raiz->dir, nome);
}

int removeABP(ABP *raiz, char nome[]) {
    if (*raiz == NULL) return 0;

    int cmp = strcmp(nome, (*raiz)->dado.nome);
    if (cmp < 0)
        return removeABP(&(*raiz)->esq, nome);
    else if (cmp > 0)
        return removeABP(&(*raiz)->dir, nome);
    else {
        No *temp = *raiz;
        if ((*raiz)->esq == NULL)
            *raiz = (*raiz)->dir;
        else if ((*raiz)->dir == NULL)
            *raiz = (*raiz)->esq;
        else {
            No *pai = *raiz;
            No *suc = (*raiz)->dir;
            while (suc->esq != NULL) {
                pai = suc;
                suc = suc->esq;
            }
            (*raiz)->dado = suc->dado;
            if (pai->esq == suc)
                pai->esq = suc->dir;
            else
                pai->dir = suc->dir;
            temp = suc;
        }
        free(temp);
        return 1;
    }
}

void imprimeEmOrdem(ABP raiz) {
    if (raiz != NULL) {
        imprimeEmOrdem(raiz->esq);
        printf("Nome: %s | Matricula: %d | Nota: %.2f\n",
               raiz->dado.nome, raiz->dado.matricula, raiz->dado.nota);
        imprimeEmOrdem(raiz->dir);
    }
}

Aluno *maiorNota(ABP raiz) {
    if (raiz == NULL) return NULL;

    Aluno *maiorEsq = maiorNota(raiz->esq);
    Aluno *maiorDir = maiorNota(raiz->dir);
    Aluno *maior = &raiz->dado;

    if (maiorEsq != NULL && maiorEsq->nota > maior->nota)
        maior = maiorEsq;
    if (maiorDir != NULL && maiorDir->nota > maior->nota)
        maior = maiorDir;

    return maior;
}

Aluno *menorNota(ABP raiz) {
    if (raiz == NULL) return NULL;

    Aluno *menorEsq = menorNota(raiz->esq);
    Aluno *menorDir = menorNota(raiz->dir);
    Aluno *menor = &raiz->dado;

    if (menorEsq != NULL && menorEsq->nota < menor->nota)
        menor = menorEsq;
    if (menorDir != NULL && menorDir->nota < menor->nota)
        menor = menorDir;

    return menor;
}
