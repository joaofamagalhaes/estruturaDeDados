#include <stdio.h>
#include <stdlib.h>
#include "filaDin.h"
int main()
{
    Fila *fi = criarFila();

    inserirFila(fi, 10);
    inserirFila(fi, 20);
    inserirFila(fi, 30);
    inserirFila(fi, 40);

    printf("Normal:\n");
    imprimir(fi);

    printf("Reversa:\n");
    imprimirReverso(fi);

    removerFila(fi);

    printf("Normal:\n");
    imprimir(fi);

    printf("Reversa:\n");
    imprimirReverso(fi);

    liberarFila(fi);
    return 0;
}
