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
} No;

typedef struct
{
    No *inicio;
} Lista;

Lista *criaLista();
void insereOrdenado(Lista *li, Alunos a);
void removePorMatricula(Lista *li, int matricula);
void imprimeLista(Lista *li);
void liberaLista(Lista *li);

#endif