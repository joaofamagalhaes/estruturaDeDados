
#ifndef TRIDIAGONAL_H
#define TRIDIAGONAL_H

typedef struct
{
    int *valores;
    int n;
} MatrizTri;

MatrizTri *criaTri(int n);
void destroiTri(MatrizTri *mat);
int insereTri(MatrizTri *mat, int i, int j, int val);
int consultaTri(MatrizTri *mat, int i, int j, int *val);
void imprimeTri(MatrizTri *mat);

#endif
