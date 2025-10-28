#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.h"

void zeraMatriz(Matriz *mat)
{
    int i, j;
    for (i = 0; i < mat->lin; i++)
        for (j = 0; j < mat->col; j++)
            mat->dados[i][j] = 0;
}

Matriz *criaMatriz(int l, int c)
{
    Matriz *mat;
    mat = (Matriz *)malloc(sizeof(Matriz));
    if (mat != NULL)
    {
        if (l <= 0 || c <= 0 || l > MAX || c > MAX)
        {
            printf("Valores invalidos, matriz nao criada!\n");
            return NULL;
        }
        mat->lin = l;
        mat->col = c;
        zeraMatriz(mat);
    }
    return mat;
}

void destroiMatriz(Matriz *mat)
{
    if (mat != NULL)
        free(mat);
}

int preencheAleatorio(Matriz *mat, int ini, int fim)
{
    if (mat == NULL)
        return 0;
    srand(time(NULL));
    int i, j;
    for (i = 0; i < mat->lin; i++)
        for (j = 0; j < mat->col; j++)
            mat->dados[i][j] = ini + rand() % (fim - ini + 1);
    return 1;
}

int insereElem(Matriz *mat, int elem, int l, int c)
{
    if (mat == NULL)
        return 0;
    if (l < 0 || c < 0 || l >= mat->lin || c >= mat->col)
    {
        printf("Valores invalidos, elem nao inserido!\n");
        return 0;
    }
    mat->dados[l][c] = elem;
    return 1;
}

int consultaElem(Matriz *mat, int *p, int l, int c)
{
    if (mat == NULL)
        return 0;
    if (l < 0 || c < 0 || l >= mat->lin || c >= mat->col)
    {
        printf("Valores invalidos, elem nao existe!\n");
        return 0;
    }
    *p = mat->dados[l][c];
    return 1;
}

void imprime(Matriz *mat)
{
    if (mat == NULL)
        return;
    int i, j;
    printf("Matriz %d x %d:\n", mat->lin, mat->col);
    for (i = 0; i < mat->lin; i++)
    {
        for (j = 0; j < mat->col; j++)
            printf("\t%d", mat->dados[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Matrizes Quadradas e propriedades

int e_matrizQuadrada(Matriz *mat)
{
    if (mat == NULL)
        return 0;
    return (mat->lin == mat->col);
}

Matriz *criaTriangularSup(Matriz *mat)
{
    if (mat == NULL)
        return NULL;
    if (!e_matrizQuadrada(mat))
    {
        printf("Matriz nao Quadrada!\n");
        return NULL;
    }
    int i, j;
    Matriz *ts = criaMatriz(mat->lin, mat->col);
    for (i = 0; i < mat->lin; i++)
        for (j = 0; j < mat->col; j++)
            if (i <= j)
                ts->dados[i][j] = mat->dados[i][j];
    return ts;
}

Matriz *criaTriangularInf(Matriz *mat)
{
    if (mat == NULL)
        return NULL;
    if (!e_matrizQuadrada(mat))
    {
        printf("Matriz nao Quadrada!\n");
        return NULL;
    }
    int i, j;
    Matriz *ti = criaMatriz(mat->lin, mat->col);
    for (i = 0; i < mat->lin; i++)
        for (j = 0; j < mat->col; j++)
            if (i >= j)
                ti->dados[i][j] = mat->dados[i][j];
    return ti;
}

Matriz *criaDiagonal(Matriz *mat)
{
    if (mat == NULL)
        return NULL;
    if (!e_matrizQuadrada(mat))
    {
        printf("Matriz nao Quadrada!\n");
        return NULL;
    }
    int i, j;
    Matriz *d = criaMatriz(mat->lin, mat->col);
    for (i = 0; i < mat->lin; i++)
        d->dados[i][i] = mat->dados[i][i];
    return d;
}

int e_Simetrica(Matriz *mat)
{
    if (mat == NULL)
        return 0;
    if (!e_matrizQuadrada(mat))
    {
        printf("Matriz nao Quadrada!\n");
        return 0;
    }
    int i, j;
    for (i = 0; i < mat->lin; i++)
        for (j = i + 1; j < mat->col; j++)
            if (mat->dados[i][j] != mat->dados[j][i])
                return 0;
    return 1;
}

Matriz *criaTransposta(Matriz *mat)
{
    if (mat == NULL)
        return NULL;
    Matriz *t = criaMatriz(mat->col, mat->lin);
    int i, j;
    for (i = 0; i < mat->lin; i++)
        for (j = 0; j < mat->col; j++)
            t->dados[j][i] = mat->dados[i][j];
    return t;
}

Matriz *somaDeMatriz(Matriz *m1, Matriz *m2)
{
    if (m1 == NULL || m2 == NULL)
        return NULL;
    Matriz *mSoma = criaMatriz(3, 3);

    for (int i = 0; i < mSoma->lin; i++)
        for (int j = 0; j < mSoma->col; j++)
            mSoma->dados[i][j] = m1->dados[i][j] + m2->dados[i][j];

    return mSoma;
}

Matriz *subtracaoDeMatriz(Matriz *m1, Matriz *m2)
{
    if (m1 == NULL || m2 == NULL)
        return NULL;
    Matriz *mMenos = criaMatriz(3, 3);

    for (int i = 0; i < mMenos->lin; i++)
        for (int j = 0; j < mMenos->col; j++)
            mMenos->dados[i][j] = m1->dados[i][j] - m2->dados[i][j];

    return mMenos;
}

Matriz *multiplicaMatriz(Matriz *m1, Matriz *m2)
{
    if (m1 == NULL || m2 == NULL)
        return NULL;
    if (m1->lin != m2->col || m1->col != m2->lin)
        return NULL;
    Matriz *multiMatriz = criaMatriz(m1->lin, m2->col);

    for (int i = 0; i < m1->lin; i++)
    {
        for (int j = 0; j < m2->col; j++)
        {
            for (int k = 0; k < m1->col; k++)
            {
                multiMatriz->dados[i][j] += m1->dados[i][k] * m2->dados[k][j];
            }
        }
    }
    return multiMatriz;
}
