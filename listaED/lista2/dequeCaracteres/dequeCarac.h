#ifndef DEQUECARAC_H
#define DEQUECARAC_H
#define MAX 100

typedef struct
{
    char dados[MAX];
    int inicio;
    int fim;
    int qntd;

} Deque;

Deque *criaDeque();
void destroiDeque(Deque *dq);
int insereIni(Deque *dq, char c);
int insereFim(Deque *dq, char c);
int removeIni(Deque *dq);
int removeFim(Deque *dq);
void verInicio(Deque *dq);
void verFim(Deque *dq);
int tamanho(Deque *dq);
void imprime(Deque *dq);
int estaVazio(Deque *dq);
int estaCheio(Deque *dq);
int palindromo(Deque *dq);
void imprimeReverso(Deque *dq);
int simetria(Deque *dq);
#endif