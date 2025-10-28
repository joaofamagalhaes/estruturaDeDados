
#ifndef MATRIZCSR_H
#define MATRIZCSR_H

typedef struct
{
    int *valores;
    int *colunas;
    int *linhas;
    int numLin;
    int numCol;
    int nnz;
} MatrizCSR;

MatrizCSR *criaCSR(int lin, int col);
void destroiCSR(MatrizCSR *mat);
int insereCSR(MatrizCSR *mat, int i, int j, int val);
int consultaCSR(MatrizCSR *mat, int i, int j, int *val);
void imprimeCSR(MatrizCSR *mat);

#endif
