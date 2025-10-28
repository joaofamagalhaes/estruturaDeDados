#include <stdio.h>
#include "FPSE.h"

int main()
{
    filaP *fp1 = criaFila();
    filaP *fp2 = criaFila();

    insereElem(fp1, 10, 3);
    insereElem(fp1, 20, 1);

    insereElem(fp2, 30, 4);
    insereElem(fp2, 40, 2);

    imprime(fp1);
    imprime(fp2);

    conjuntoFilas(fp1, fp2);

    imprime(fp1);

    liberaFila(fp1);
    liberaFila(fp2);

    return 0;
}
