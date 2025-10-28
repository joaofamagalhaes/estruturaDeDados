#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

int main()
{
    ABP *raiz = criaABP();
    int op, valor;

    do
    {
        printf("\n===== MENU ABP =====\n");
        printf("1 - Criar ABP\n");
        printf("2 - Inserir um elemento\n");
        printf("3 - Buscar um elemento\n");
        printf("4 - Remover um elemento\n");
        printf("5 - Imprimir em ordem\n");
        printf("6 - Imprimir em pre-ordem\n");
        printf("7 - Imprimir em pos-ordem\n");
        printf("8 - Mostrar quantidade de nos\n");
        printf("9 - Mostrar caminhos das folhas ate a raiz\n");
        printf("10 - Destruir ABP\n");
        printf("11 - Imprimir em ordem decrescente\n");
        printf("12 - Mostrar maior valor\n");
        printf("13 - Mostrar menor valor\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            raiz = criaABP();
            printf("ABP criada.\n");
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            insereElem(raiz, valor);
            break;
        case 3:
            printf("Digite valor a buscar: ");
            scanf("%d", &valor);
            printf(pesquisa(raiz, valor) ? "Encontrado.\n" : "Nao encontrado.\n");
            break;
        case 4:
            printf("Digite valor a remover: ");
            scanf("%d", &valor);
            removeRecComMenorDir(raiz, valor);
            break;
        case 5:
            printf("Em ordem: ");
            em_ordem(*raiz, 0);
            printf("\n");
            break;
        case 6:
            printf("Pre-ordem: ");
            pre_ordem(*raiz, 0);
            printf("\n");
            break;
        case 7:
            printf("Pos-ordem: ");
            pos_ordem(*raiz, 0);
            printf("\n");
            break;
        case 8:
            mostrarQuantidadeNos(raiz);
            break;
        case 9:
            mostrarCaminhosFolhas(*raiz);
            break;
        case 10:
            destroiABP(raiz);
            raiz = criaABP();
            printf("ABP destruida.\n");
            break;
        case 11:
            printf("Em ordem decrescente: ");
            em_ordem_decrescente(*raiz, 0);
            printf("\n");
            break;
        case 12:
            printf("Maior valor: %d\n", maiorValor(*raiz));
            break;
        case 13:
            printf("Menor valor: %d\n", menorValor(*raiz));
            break;
        case 0:
            printf("Encerrando...\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }

    } while (op != 0);

    destroiABP(raiz);
    return 0;
}
