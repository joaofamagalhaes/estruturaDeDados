#ifndef ALUNO_H
#define ALUNO_H

typedef struct
{
    char nome[100];
    int matricula;
    float notas[3];
} Aluno;

void ordenar_por_nome(Aluno *turma, int n);
void ordenar_por_matricula(Aluno *turma, int n);

int busca_aluno_por_nome(Aluno *turma, int n, const char *nome);
int busca_aluno_por_matricula(Aluno *turma, int n, int matricula);

#endif