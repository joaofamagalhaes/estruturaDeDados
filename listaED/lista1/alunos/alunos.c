#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"

Lista *criaLista()
{
    Lista *li = malloc(sizeof(Lista));
    if (li != NULL)
        li->inicio = NULL;
    return li;
}
void insereOrdenado(Lista *li, Alunos a)
{
    No *novo = malloc(sizeof(No));
    if (novo == NULL)
        return;

    novo->dado = a;
    novo->prox = NULL;

    if (li->inicio == NULL || strcmp(a.nome, li->inicio->dado.nome) < 0)
    {
        novo->prox = li->inicio;
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
        atual->prox = novo;
    }
};
void removePorMatricula(Lista *li, int matricula)
{
    if (li->inicio == NULL)
        return;
    No *atual = li->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->dado.matricula != matricula)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        printf("Não encontrado!\n");
        return;
    }

    if (anterior == NULL)
    {
        li->inicio = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }
    free(atual);
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
