#include <stdio.h>
#include <stdlib.h>
#include "FilaEncadeada.h"

int main()
{
    Fila *fila = NULL;
    int opcao, valor;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Criar fila\n");
        printf("2 - Enfileirar um item\n");
        printf("3 - Ver o inicio da fila\n");
        printf("4 - Desenfileirar um item\n");
        printf("5 - Imprimir a fila\n");
        printf("6 - Destruir a fila\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            fila = criarFila();
            if (fila != NULL)
                printf("Fila criada com sucesso!\n");
            else
                printf("Erro ao criar fila.\n");
            break;
        case 2:
            printf("Digite o valor a enfileirar: ");
            scanf("%d", &valor);
            if (enfileirar(fila, valor))
                printf("Valor enfileirado com sucesso.\n");
            else
                printf("Erro ao enfileirar.\n");
            break;
        case 3:
            if (verInicio(fila, &valor))
                printf("Inicio da fila: %d\n", valor);
            else
                printf("Fila vazia ou nao criada.\n");
            break;
        case 4:
            if (desenfileirar(fila))
                printf("Item desenfileirado com sucesso.\n");
            else
                printf("Erro ao desenfileirar.\n");
            break;
        case 5:
            imprimirFila(fila);
            break;
        case 6:
            destruirFila(fila);
            fila = NULL;
            printf("Fila destruida com sucesso.\n");
            break;
        case 7:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 7);

    return 0;
}
