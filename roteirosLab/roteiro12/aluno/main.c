#include <stdio.h>
#include <string.h>
#include "aluno.h"

void imprimir_turma(Aluno *turma, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Matricula: %d, Nome: %s\n", turma[i].matricula, turma[i].nome);
    }
}

int main()
{
    Aluno turma[] = {
        {"Carlos", 202302, {7.5, 8.0, 9.0}},
        {"Ana", 202301, {9.5, 9.0, 10.0}},
        {"Beatriz", 202205, {6.5, 7.0, 5.0}},
        {"Daniel", 202401, {8.0, 8.5, 8.8}}};
    int n = sizeof(turma) / sizeof(turma[0]);
    int resultado;

    printf("--- Busca por Nome ---\n");
    printf("Turma original:\n");
    imprimir_turma(turma, n);

    printf("\nOrdenando por nome\n");
    ordenar_por_nome(turma, n);
    imprimir_turma(turma, n);

    const char *nome_busca = "Beatriz";
    printf("\nBuscando por nome: %s\n", nome_busca);
    resultado = busca_aluno_por_nome(turma, n, nome_busca);
    if (resultado != -1)
    {
        printf("Aluno encontrado na posicao %d do vetor ordenado por nome.\n", resultado);
    }
    else
    {
        printf("Aluno nao encontrado.\n");
    }

    printf("\n--- Busca por Matricula ---\n");
    printf("Ordenando por matricula\n");
    ordenar_por_matricula(turma, n);
    imprimir_turma(turma, n);

    int matricula_busca = 202302;
    printf("\nBuscando por matricula: %d\n", matricula_busca);
    resultado = busca_aluno_por_matricula(turma, n, matricula_busca);
    if (resultado != -1)
    {
        printf("Aluno encontrado na posicao %d do vetor ordenado por matricula.\n", resultado);
    }
    else
    {
        printf("Aluno nao encontrado.\n");
    }

    return 0;
}