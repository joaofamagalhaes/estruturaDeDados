#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunosLDE.h"

Lista *criaLista()
{
    Lista *li = malloc(sizeof(Lista));
    if (li != NULL)
    {
        li->inicio = NULL;
        li->fim = NULL;
    }
    return li;
}
void insereOrdenado(Lista *li, Alunos a)
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
        return;

    novo->dado = a;
    novo->prox = NULL;
    novo->ant = NULL;

    if (li->inicio == NULL)
    {
        li->inicio = novo;
        li->fim = novo;
    }
    else if (strcmp(a.nome, li->inicio->dado.nome) < 0)
    {
        novo->prox = li->inicio;
        li->inicio->ant = novo;
        li->inicio = novo;
    }
    else
    {
        No *atual = li->inicio;
        while (atual->prox != NULL && strcmp(atual->prox->dado.nome, a.nome) < 0)
        {
            atual = atual->prox;
        }

        novo->prox = atual->prox;
        novo->ant = atual;
        atual->prox = novo;

        if (novo->prox != NULL)
            novo->prox->ant = novo;
        else
            li->fim = novo;
    }
};

void imprimeLista(Lista *li)
{
    No *aux = li->inicio;
    while (aux != NULL)
    {
        printf("Nome %s\n", aux->dado.nome);
        printf("Matricula %d\n", aux->dado.matricula);
        printf("Nota %2.f\n", aux->dado.nota);
        aux = aux->prox;
    }
};
void liberaLista(Lista *li)
{
    No *atual = li->inicio;
    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(li);
};

void imprimeReverso(Lista *li)
{
    if (li == NULL || li->fim == NULL)
    {
        printf("Lista vazia ou inexistente\n");
        return;
    }

    No *aux = li->fim;
    while (aux != NULL)
    {
        printf("Nome %s\n", aux->dado.nome);
        printf("Matricula %d\n", aux->dado.matricula);
        printf("Nota %2.f\n", aux->dado.nota);
        aux = aux->ant;
    }
}