#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

int main()
{
    ContaBancaria *c = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    int id, opcao = 0;
    double valor;
    char nome[100];
    printf("Digite o nome do titular da conta:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("Digite a ID (5 numeros) de acesso pessoal da conta:\n");
    scanf("%d", &id);

    criarConta(c, id, nome);

    while (opcao != 5)
    {
        printf("\n---------- Menu principal ----------\n");
        printf("Digite a opcao desejada para operar o menu\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Consultar Saldo\n");
        printf("4 - Informacoes da conta\n");
        printf("5 - Fechar menu\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            printf("Digite o valor a ser depositado:\n");
            scanf("%lf", &valor);
            depositar(c, valor);
            break;
        case 2:
            printf("Digite o valor que deseja sacar:\n");
            scanf("%lf", &valor);
            sacar(c, valor);
            break;
        case 3:
            consultarSaldo(c);
            break;
        case 4:
            imprimirInfo(c);
            break;
        case 5:
            printf("Fechando o menu...\n");
            break;
        default:
            printf("Operacao invalida!\n");
            break;
        }
    }
    free(c);
    return 0;
}