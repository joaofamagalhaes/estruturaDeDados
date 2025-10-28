#include "aluno.h"
#include <string.h>
#include <stdlib.h>


int comparar_nomes(const void* a, const void* b) {
    Aluno* alunoA = (Aluno*)a;
    Aluno* alunoB = (Aluno*)b;
    return strcmp(alunoA->nome, alunoB->nome);
}

int comparar_matriculas(const void* a, const void* b) {
    Aluno* alunoA = (Aluno*)a;
    Aluno* alunoB = (Aluno*)b;
    if (alunoA->matricula < alunoB->matricula) return -1;
    if (alunoA->matricula > alunoB->matricula) return 1;
    return 0;
}

void ordenar_por_nome(Aluno* turma, int n) {
    qsort(turma, n, sizeof(Aluno), comparar_nomes);
}

void ordenar_por_matricula(Aluno* turma, int n) {
    qsort(turma, n, sizeof(Aluno), comparar_matriculas);
}

int busca_aluno_por_nome(Aluno* turma, int n, const char* nome) {
    int inicio = 0;
    int fim = n - 1;
    while(inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int cmp = strcmp(nome, turma[meio].nome);
        if (cmp == 0) {
            return meio; 
        }
        if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1; 
}

int busca_aluno_por_matricula(Aluno* turma, int n, int matricula) {
    int inicio = 0;
    int fim = n - 1;
    while(inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (turma[meio].matricula == matricula) {
            return meio; 
        }
        if (matricula < turma[meio].matricula) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1; 
}