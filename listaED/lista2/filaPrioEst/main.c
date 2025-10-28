#include <stdio.h>
#include <stdlib.h>
#include "FPE.h"

int main()
{
    filaP *fp1 = criaFila();
    filaP *fp2 = criaFila();

    insereElem(fp1, 1, 3);
    insereElem(fp1, 10, 1);
    insereElem(fp2, 2, 4);
    insereElem(fp2, 20, 2);

    imprime(fp1);
    imprime(fp2);

    conjuntoFilas(fp1, fp2);

    imprime(fp1);

    liberaFila(fp1);
    liberaFila(fp2);

    return 0;
}