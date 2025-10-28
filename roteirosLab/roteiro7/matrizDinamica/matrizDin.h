
#ifndef MATRIZDIN_H
#define MATRIZDIN_H

typedef struct {
    int **dados;
    int lin;
    int col;
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
