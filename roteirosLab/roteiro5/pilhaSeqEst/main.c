#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main()
{
    Pilha *pilha = NULL;
    int opcao, valor;

    do
    {
        printf("\nMenu\n");
        printf("1 - Criar pilha\n");
        printf("2 - Empilhar um item\n");
        printf("3 - Ver o topo da pilha\n");
        printf("4 - Desempilhar um item\n");
        printf("5 - Imprimir a pilha\n");
        printf("6 - Destruir a pilha\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            pilha = criarPilha();
            if (pilha != NULL)
                printf("Pilha criada com sucesso\n");
            else
                printf("Erro ao criar pilha\n");
            break;
        case 2:
            printf("Digite o valor a empilhar: ");
            scanf("%d", &valor);
            if (empilhar(pilha, valor))
                printf("Valor empilhado com sucesso\n");
            else
                printf("Erro ao empilhar\n");
            break;
        case 3:
            if (verTopo(pilha, &valor))
                printf("Topo da pilha: %d\n", valor);
            else
                printf("Pilha vazia ou nao criada\n");
            break;
        case 4:
            if (desempilhar(pilha))
                printf("Item desempilhado com sucesso\n");
            else
                printf("Erro ao desempilhar\n");
            break;
        case 5:
            imprimirPilha(pilha);
            break;
        case 6:
            destruirPilha(pilha);
            pilha = NULL;
            printf("Pilha destruida com sucesso\n");
            break;
        case 7:
            printf("Saindo\n");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opcao != 7);

    return 0;
}
