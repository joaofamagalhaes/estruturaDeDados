
#include <stdio.h>
#include "matrizCSR.h"

int main()
{
    int lin, col, op, i, j, val;
    MatrizCSR *mat = NULL;

    printf("Informe o número de linhas e colunas: ");
    scanf("%d %d", &lin, &col);

    mat = criaCSR(lin, col);

    do
    {
        printf("\n1 - Inserir elemento\n");
        printf("2 - Consultar elemento\n");
        printf("3 - Imprimir matriz\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Posicao (i j) e valor: ");
            scanf("%d %d %d", &i, &j, &val);
            if (insereCSR(mat, i, j, val))
                printf("Inserido!\n");
            else
                printf("Erro ao inserir.\n");
            break;
        case 2:
            printf("Posicao (i j): ");
            scanf("%d %d", &i, &j);
            if (consultaCSR(mat, i, j, &val))
                printf("Valor: %d\n", val);
            else
                printf("Erro na consulta.\n");
            break;
        case 3:
            printf("Matriz completa:\n");
            imprimeCSR(mat);
            break;
        case 4:
            destroiCSR(mat);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }

    } while (op != 4);

    return 0;
}
