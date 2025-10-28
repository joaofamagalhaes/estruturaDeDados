#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Matriz.h"

int main()
{
    Matriz *M1, *M2, *Msoma, *Mmenos, *multiM;

    M1 = criaMatriz(3, 3);
    M2 = criaMatriz(3, 3);

    preencheAleatorio(M1, 1, 10);
    preencheAleatorio(M2, 10, 20);

    imprime(M1);
    imprime(M2);

    Mmenos = subtracaoDeMatriz(M2, M1);
    Msoma = somaDeMatriz(M1, M2);
    multiM = multiplicaMatriz(M1, M2);

    imprime(Mmenos);
    imprime(Msoma);
    imprime(multiM);

    destroiMatriz(multiM);
    destroiMatriz(M1);
    destroiMatriz(M2);
    destroiMatriz(Msoma);
    return 0;
}