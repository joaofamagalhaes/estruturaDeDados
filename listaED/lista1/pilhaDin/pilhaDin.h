#ifndef PILHADIN_H
#define PILHADIN_H

typedef struct
{
    int num;
} Dados;

typedef struct pilhaDin
{
    Dados info;
    struct pilhaDin *prox;
} pilhaDin;

pilhaDin *criarPilha();
void liberarPilha(pilhaDin *topo);
int inserePilha(pilhaDin **topo, int num);
int removePilha(pilhaDin **topo);
void imprimirPilha(pilhaDin *topo);
void imprimirReversoPilha(pilhaDin *topo);
#endif