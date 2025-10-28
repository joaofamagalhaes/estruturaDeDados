
#include <stdio.h>
#include "tridiagonal.h"

int main()
{
    int n, op, i, j, val;
    MatrizTri *m = NULL;

    printf("Informe a ordem da matriz tridiagonal: ");
    scanf("%d", &n);
    m = criaTri(n);

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
            if (insereTri(m, i, j, val))
                printf("Inserido!\n");
            else
                printf("Posicao invalida.\n");
            break;
        case 2:
            printf("Posicao (i j): ");
            scanf("%d %d", &i, &j);
            if (consultaTri(m, i, j, &val))
                printf("Valor: %d\n", val);
            else
                printf("Posicao invalida.\n");
            break;
        case 3:
            printf("Matriz:\n");
            imprimeTri(m);
            break;
        case 4:
            destroiTri(m);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }

    } while (op != 4);

    return 0;
}
