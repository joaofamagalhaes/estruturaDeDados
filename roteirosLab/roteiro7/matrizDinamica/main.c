
#include <stdio.h>
#include "matrizDin.h"

int main() {
    Matriz *m = criaMatriz(3, 3);

    insereElem(m, 0, 0, 1);
    insereElem(m, 0, 1, 2);
    insereElem(m, 0, 2, 3);
    insereElem(m, 1, 0, 2);
    insereElem(m, 1, 1, 4);
    insereElem(m, 1, 2, 6);
    insereElem(m, 2, 0, 3);
    insereElem(m, 2, 1, 6);
    insereElem(m, 2, 2, 9);

    printf("Matriz original:\n");
    imprime(m);

    Matriz *t = transposta(m);
    printf("\nTransposta:\n");
    imprime(t);

    printf("\nEh quadrada? %s\n", e_Quadrada(m) ? "Sim" : "Nao");
    printf("Eh simetrica? %s\n", e_Simetrica(m) ? "Sim" : "Nao");

    Matriz *tri = criaTriangular(m);
    printf("\nTriangular superior:\n");
    imprime(tri);

    Matriz *diag = criaDiagonal(m);
    printf("\nDiagonal principal:\n");
    imprime(diag);

    destroiMatriz(m);
    destroiMatriz(t);
    destroiMatriz(tri);
    destroiMatriz(diag);

    return 0;
}
