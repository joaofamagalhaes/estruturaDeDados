
#include <stdio.h>
#include <stdlib.h>
#include "tridiagonal.h"

MatrizTri *criaTri(int n) {
    if (n <= 0) return NULL;
    MatrizTri *mat = malloc(sizeof(MatrizTri));
    if (mat == NULL) return NULL;

    mat->n = n;
    mat->valores = malloc((3 * n - 2) * sizeof(int));
    if (mat->valores == NULL) {
        free(mat);
        return NULL;
    }

    for (int i = 0; i < 3 * n - 2; i++)
        mat->valores[i] = 0;

    return mat;
}

void destroiTri(MatrizTri *mat) {
    if (mat != NULL) {
        free(mat->valores);
        free(mat);
    }
}

int posicaoTri(MatrizTri *mat, int i, int j) {
    if (i < 0 || i >= mat->n || j < 0 || j >= mat->n)
        return -1;
    if (i == j)
        return mat->n - 1 + i;
    else if (i == j + 1)
        return j;
    else if (i + 1 == j)
        return 2 * mat->n - 1 + i;
    return -1;
}

int insereTri(MatrizTri *mat, int i, int j, int val) {
    int pos = posicaoTri(mat, i, j);
    if (pos == -1) return 0;
    mat->valores[pos] = val;
    return 1;
}

int consultaTri(MatrizTri *mat, int i, int j, int *val) {
    int pos = posicaoTri(mat, i, j);
    if (pos == -1) {
        *val = 0;
        return 0;
    }
    *val = mat->valores[pos];
    return 1;
}

void imprimeTri(MatrizTri *mat) {
    int v;
    for (int i = 0; i < mat->n; i++) {
        for (int j = 0; j < mat->n; j++) {
            consultaTri(mat, i, j, &v);
            printf("%d ", v);
        }
        printf("\n");
    }
}
