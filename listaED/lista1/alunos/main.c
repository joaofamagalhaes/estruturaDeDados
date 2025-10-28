#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"

int main()
{
    Lista *lista = criaLista();

    Alunos a1 = {"Carlos", 123, 8.5};
    Alunos a2 = {"Amanda", 456, 9.2};
    Alunos a3 = {"Bruna", 789, 7.5};

    insereOrdenado(lista, a1);
    insereOrdenado(lista, a2);
    insereOrdenado(lista, a3);

    printf("Lista de alunos:\n");
    imprimeLista(lista);

    printf("Removendo aluno com matricula 456...\n");
    removePorMatricula(lista, 456);

    printf("Lista apos remocao:\n");
    imprimeLista(lista);

    liberaLista(lista);
    return 0;
}
