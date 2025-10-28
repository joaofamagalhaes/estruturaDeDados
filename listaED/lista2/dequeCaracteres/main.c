#include <stdio.h>
#include <stdlib.h>
#include "dequeCarac.h"

int main()
{

    Deque *dq = criaDeque();
    insereIni(dq, 'b');
    insereIni(dq, 'a');
    insereFim(dq, 'b');
    insereFim(dq, 'a');

    imprime(dq);
    if (simetria(dq))
        printf("Simetrico!\n");
    imprime(dq);

    destroiDeque(dq);
    return 0;
}