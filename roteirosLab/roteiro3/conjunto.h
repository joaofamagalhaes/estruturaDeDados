#ifndef CONJUNTO_H
#define CONJUNTO_H

#define MAXTAM 100

typedef struct
{
    int elementos[MAXTAM];
    int tam;

} Conjunto;

void criaConj(Conjunto *c);
int inserirElem(Conjunto *c, int valor);
int removerElem(Conjunto *c, int valor);
Conjunto uniaoConj(Conjunto c1, Conjunto c2);
Conjunto intersecaoConj(Conjunto c1, Conjunto c2);
Conjunto diferencaConj(Conjunto c1, Conjunto c2);
void pertenceElem(Conjunto *c, int valor);
int menorElem(Conjunto *c);
int maiorElem(Conjunto *c);
void comparaElem(Conjunto *c1, Conjunto *c2);
void tamConj(Conjunto *c);
void vazioConj(Conjunto *c);

#endif