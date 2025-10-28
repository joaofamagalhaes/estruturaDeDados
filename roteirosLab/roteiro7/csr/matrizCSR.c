
#include <stdio.h>
#include <stdlib.h>
#include "matrizCSR.h"

MatrizCSR *criaCSR(int lin, int col)
{
    MatrizCSR *mat = malloc(sizeof(MatrizCSR));
    if (mat == NULL)
        return NULL;

    mat->numLin = lin;
    mat->numCol = col;
    mat->nnz = 0;
    mat->valores = malloc(sizeof(int));
    mat->colunas = malloc(sizeof(int));
    mat->linhas = calloc(lin + 1, sizeof(int));
    return mat;
}

void destroiCSR(MatrizCSR *mat)
{
    if (mat)
    {
        free(mat->valores);
        free(mat->colunas);
        free(mat->linhas);
        free(mat);
    }
}

int insereCSR(MatrizCSR *mat, int i, int j, int val)
{
    if (mat == NULL || i < 0 || i >= mat->numLin || j < 0 || j >= mat->numCol)
        return 0;

    mat->valores = realloc(mat->valores, (mat->nnz + 1) * sizeof(int));
    mat->colunas = realloc(mat->colunas, (mat->nnz + 1) * sizeof(int));

    if (mat->valores == NULL || mat->colunas == NULL)
        return 0;

    mat->valores[mat->nnz] = val;
    mat->colunas[mat->nnz] = j;

    for (int k = i + 1; k <= mat->numLin; k++)
    {
        mat->linhas[k]++;
    }

    mat->nnz++;
    return 1;
}

int consultaCSR(MatrizCSR *mat, int i, int j, int *val)
{
    if (mat == NULL || val == NULL || i < 0 || i >= mat->numLin || j < 0 || j >= mat->numCol)
        return 0;

    for (int k = mat->linhas[i]; k < mat->linhas[i + 1]; k++)
    {
        if (mat->colunas[k] == j)
        {
            *val = mat->valores[k];
            return 1;
        }
    }

    *val = 0;
    return 1;
}

void imprimeCSR(MatrizCSR *mat)
{
    int v;
    for (int i = 0; i < mat->numLin; i++)
    {
        for (int j = 0; j < mat->numCol; j++)
        {
            consultaCSR(mat, i, j, &v);
            printf("%d ", v);
        }
        printf("\n");
    }
}
