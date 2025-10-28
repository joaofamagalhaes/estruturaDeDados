#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

int main()
{
    int opcao, opcItem;
    char nomItem[20], endereco[50], status[20];

    Pedido pedido = criarPedido();
    Item hamburguer = {"Hamburguer", 20.00, 1};
    Item batata = {"Batata Frita", 10.00, 1};
    Item refrigerante = {"Refrigerante", 7.50, 1};

    do
    {
        printf("\n--------------- Menu de Pedidos ---------------\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Definir endereco\n");
        printf("4 - Alterar status\n");
        printf("5 - Imprimir pedido\n");
        printf("6 - Finalizar pedido e sair do menu\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Escolha o item que voce deseja adicionar\n");
            printf("1 - Hamburguer\n");
            printf("2 - Batata frita\n");
            printf("3 - Refrigerante\n");
            scanf("%d", &opcItem);
            switch (opcItem)
            {
            case 1:
                adicionarItem(&pedido, hamburguer);
                break;
            case 2:
                adicionarItem(&pedido, batata);
                break;
            case 3:
                adicionarItem(&pedido, refrigerante);
                break;
            default:
                printf("Opcao invalida! Tente novamente\n");
                break;
            }
            break;
        case 2:
            printf("Digite o nome do item a ser removido: \n");
            fgets(nomItem, sizeof(nomItem), stdin);
            nomItem[strcspn(nomItem, "\n")] = '\0';
            removerItem(&pedido, nomItem);
            break;
        case 3:
            printf("Digite o endereco: \n");
            fgets(endereco, sizeof(endereco), stdin);
            endereco[strcspn(endereco, "\n")] = '\0';
            definirEndereco(&pedido, endereco);
            break;
        case 4:
            printf("Digite o status do pedido: \n");
            fgets(status, sizeof(status), stdin);
            status[strcspn(status, "\n")] = '\0';
            alterarStatus(&pedido, status);
            break;
        case 5:
            imprimirPedido(&pedido);
            break;
        case 6:
            finalizarPedido(&pedido);
            break;
        default:
            printf("Opcao invalida! Tente novamente\n");
            break;
        }
    } while (opcao != 6);

    return 0;
}