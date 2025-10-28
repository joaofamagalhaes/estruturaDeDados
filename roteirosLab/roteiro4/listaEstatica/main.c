#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

int main()
{
    Lista *li;
    int x, opcao = 0;
    li = criaLista();

    while (opcao != 9)
    {
        printf("\n---------- Menu principal ----------\n");
        printf("Digite a opcao desejada para operar a lista\n");
        printf("1 - Inserir dado no inicio\n");
        printf("2 - Inserir dado no fim\n");
        printf("3 - Remover dado no inicio\n");
        printf("4 - Remover dado no fim\n");
        printf("5 - Procurar dado\n");
        printf("6 - Tamanho da lista\n");
        printf("7 - Imprimir lista\n");
        printf("8 - Remover a primeira ocorrencia de um dado\n");
        printf("9 - Fechar menu\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: \n");
            scanf("%d", &x);
            insereIni(li, x);
            break;
        case 2:
            printf("Digite o valor a ser inserido: \n");
            scanf("%d", &x);
            insereFim(li, x);
            break;
        case 3:
            removeIni(li);
            break;
        case 4:
            removeFim(li);
            break;
        case 5:
            printf("Digite o valor que voce deseja procurar:\n");
            scanf("%d", &x);
            procura(li, x);
            break;
        case 6:
            printf("Lista de tamanho %d\n", tamanho(li));
            break;
        case 7:
            imprime(li);
            break;
        case 8:
            printf("Digite o dado que deseja remover:\n");
            scanf("%d", &x);
            removeOcorr(li, x);
            break;
        case 9:
            printf("Fechando o menu...\n");
            break;
        default:
            printf("Operacao invalida!\n");
            break;
        }
    }

    return 0;
}