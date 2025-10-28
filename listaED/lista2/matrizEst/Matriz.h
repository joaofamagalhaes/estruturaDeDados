/*----------------- File: Matriz.h  --------------------+
|Matriz Estatica                                        |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 29/09/2023      |
+-------------------------------------------------------+ */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct
{
    int dados[MAX][MAX];
    int lin, col;
} Matriz;

void zeraMatriz(Matriz *mat);
Matriz *criaMatriz(int l, int c);
void destroiMatriz(Matriz *mat);
int preencheAleatorio(Matriz *mat, int ini, int fim);
int insereElem(Matriz *mat, int elem, int l, int c);
int consultaElem(Matriz *mat, int *p, int l, int c);
void imprime(Matriz *mat);

// Matrizes Quadradas e propriedades

int e_matrizQuadrada(Matriz *mat);
Matriz *criaTriangularSup(Matriz *mat);
Matriz *criaTriangularInf(Matriz *mat);
Matriz *criaDiagonal(Matriz *mat);
int e_Simetrica(Matriz *mat);
Matriz *criaTransposta(Matriz *mat);
/*
Exercicios
Criar as operacoes de soma, subtração, multiplicacao. Para cada operação,
receba duas matrizes, e se possível (testar dimensoes), crie uma terceira matriz
que conterá o resultado da referida operação;
*/
Matriz *somaDeMatriz(Matriz *m1, Matriz *m2);
Matriz *subtracaoDeMatriz(Matriz *m1, Matriz *m2);
Matriz *multiplicaMatriz(Matriz *m1, Matriz *m2);

#endif