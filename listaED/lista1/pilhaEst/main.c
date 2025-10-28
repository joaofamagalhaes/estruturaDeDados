#include <stdio.h>
#include <stdlib.h>
#include "pilhaEst.h"

int main()
{

    Pilha *pi = criarPilha();

    inserePilha(pi, 1);
    inserePilha(pi, 2);
    inserePilha(pi, 3);
    inserePilha(pi, 4);
    imprimePilha(pi);

    removePilha(pi);

    printf("\n%d\n", consultaTopo(pi));

    imprimePilhaReverso(pi);

    liberaPilha(pi);

    return 0;
}