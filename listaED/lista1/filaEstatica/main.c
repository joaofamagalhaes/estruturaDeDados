#include <stdio.h>
#include <stdlib.h>
#include "filaEst.h"

int main()
{

    Fila *fi = criafila();
    inserirFila(fi, 1);
    inserirFila(fi, 2);
    inserirFila(fi, 3);
    imprimir(fi);
    removerFila(fi);
    imprimir(fi);
    imprimirReverso(fi);
    liberaFila(fi);
    return 0;
}