#include <stdio.h>
#include <stdlib.h>
#include "dde.h"

int main()
{
    int *p = malloc(sizeof(int));
    Deque *dq = criaDeque();
    insereIni(dq, 2);
    insereIni(dq, 1);
    insereFim(dq, 2);
    insereFim(dq, 1);
    insereIni(dq, 5);
    insereFim(dq, 10);

    imprime(dq);
    imprimeReverso(dq);

    liberaDeque(dq);
    return 0;
}