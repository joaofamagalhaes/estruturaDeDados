#ifndef DDE_H
#define DDE_H

typedef struct NO // struct NO define o tipo de dado que eu vou utilizar//
{
    struct NO *ant;
    int num;
    struct NO *prox;
} NO;

typedef struct // No descritor do Deque, levando o nome do mesmo//
{
    int qntd;
    struct NO *ini;
    struct NO *fim;
} Deque;

Deque *criaDeque();
void liberaDeque(Deque *dq);
int insereIni(Deque *dq, int num);
int insereFim(Deque *dq, int num);
int removeIni(Deque *dq);
int removeFim(Deque *dq);
void verInicio(Deque *dq, int *p);
void verFim(Deque *dq, int *p);
int tamanho(Deque *dq);
void imprime(Deque *dq);
int estaVazio(Deque *dq);

void excluiNegativo(Deque *dq);

void imprimeReverso(Deque *dq);

#endif