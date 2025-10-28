
#ifndef ABP_ALUNO_H
#define ABP_ALUNO_H

typedef struct {
    char nome[50];
    int matricula;
    double nota;
} Aluno;

typedef struct no {
    Aluno dado;
    struct no *esq;
    struct no *dir;
} No;

typedef No* ABP;

ABP criaABP();
void destroiRec(No *raiz);
void destroiABP(ABP *raiz);
int insereABP(ABP *raiz, Aluno a);
No *buscaABP(ABP raiz, char nome[]);
int removeABP(ABP *raiz, char nome[]);
void imprimeEmOrdem(ABP raiz);
Aluno *maiorNota(ABP raiz);
Aluno *menorNota(ABP raiz);

#endif
