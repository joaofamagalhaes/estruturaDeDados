#ifndef ALUNOS_H
#define ALUNOS_H

typedef struct
{
    char nome[50];
    int matricula;
    double nota;
} Alunos;

typedef struct no
{
    Alunos dado;
    struct no *prox;
    struct no *ant;
} No;

typedef struct
{
    No *inicio;
    No *fim;
} Lista;

Lista *criaLista();
void insereOrdenado(Lista *li, Alunos a);
void imprimeLista(Lista *li);
void liberaLista(Lista *li);

void imprimeReverso(Lista *li);

#endif