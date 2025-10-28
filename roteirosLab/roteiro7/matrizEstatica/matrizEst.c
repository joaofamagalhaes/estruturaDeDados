
#include <stdio.h>
#include <stdlib.h>
#include "matrizEst.h"

Matriz *criaMatriz(int lin, int col) {
    if (lin > MAX || col > MAX || lin <= 0 || col <= 0) return NULL;
    Matriz *mat = malloc(sizeof(Matriz));
    if (mat != NULL) {
        mat->lin = lin;
        mat->col = col;
        for (int i = 0; i < lin; i++)
            for (int j = 0; j < col; j++)
                mat->dados[i][j] = 0;
    }
    return mat;
}

void destroiMatriz(Matriz *mat) {
    free(mat);
}

int insereElem(Matriz *mat, int lin, int col, int val) {
    if (mat == NULL) return 0;
    if (lin >= 0 && lin < mat->lin && col >= 0 && col < mat->col) {
        mat->dados[lin][col] = val;
        return 1;
    }
    return 0;
}

int consultaElem(Matriz *mat, int *p, int lin, int col) {
    if (mat != NULL && p != NULL) {
        if (lin >= 0 && lin < mat->lin && col >= 0 && col < mat->col) {
            *p = mat->dados[lin][col];
            return 1;
        }
    }
    return 0;
}

void imprime(Matriz *mat) {
    if (mat == NULL) return;
    for (int i = 0; i < mat->lin; i++) {
        for (int j = 0; j < mat->col; j++) {
            printf("%d ", mat->dados[i][j]);
        }
        printf("\n");
    }
}

Matriz *transposta(Matriz *mat) {
    if (mat == NULL) return NULL;
    Matriz *nova = criaMatriz(mat->col, mat->lin);
    if (nova == NULL) return NULL;
    for (int i = 0; i < mat->lin; i++)
        for (int j = 0; j < mat->col; j++)
            nova->dados[j][i] = mat->dados[i][j];
    return nova;
}

int e_Quadrada(Matriz *mat) {
    return (mat != NULL && mat->lin == mat->col);
}

int e_Simetrica(Matriz *mat) {
    if (!e_Quadrada(mat)) return 0;
    for (int i = 0; i < mat->lin; i++)
        for (int j = 0; j < mat->col; j++)
            if (mat->dados[i][j] != mat->dados[j][i])
                return 0;
    return 1;
}

Matriz *criaTriangular(Matriz *mat) {
    if (!e_Quadrada(mat)) return NULL;
    Matriz *nova = criaMatriz(mat->lin, mat->col);
    if (nova == NULL) return NULL;
    for (int i = 0; i < mat->lin; i++)
        for (int j = 0; j < mat->col; j++)
            nova->dados[i][j] = (i <= j) ? mat->dados[i][j] : 0;
    return nova;
}

Matriz *criaDiagonal(Matriz *mat) {
    if (!e_Quadrada(mat)) return NULL;
    Matriz *nova = criaMatriz(mat->lin, mat->col);
    if (nova == NULL) return NULL;
    for (int i = 0; i < mat->lin; i++)
        for (int j = 0; j < mat->col; j++)
            nova->dados[i][j] = (i == j) ? mat->dados[i][j] : 0;
    return nova;
}
