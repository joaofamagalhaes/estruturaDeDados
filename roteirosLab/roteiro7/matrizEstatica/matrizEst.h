
#ifndef MATRIZEST_H
#define MATRIZEST_H

#define MAX 100

typedef struct {
    int lin;
    int col;
    int dados[MAX][MAX];
} Matriz;

Matriz *criaMatriz(int lin, int col);
void destroiMatriz(Matriz *mat);
int insereElem(Matriz *mat, int lin, int col, int val);
int consultaElem(Matriz *mat, int *p, int lin, int col);
void imprime(Matriz *mat);
Matriz *transposta(Matriz *mat);
int e_Quadrada(Matriz *mat);
int e_Simetrica(Matriz *mat);
Matriz *criaTriangular(Matriz *mat);
Matriz *criaDiagonal(Matriz *mat);

#endif
