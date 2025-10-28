
#include <stdio.h>
#include "abp.h"

int main() {
    ABP arvore = criaABP();
    int op, valor;

    do {
        printf("\n1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Imprimir em ordem\n");
        printf("5 - Imprimir pre-ordem\n");
        printf("6 - Imprimir pos-ordem\n");
        printf("7 - Contar nos\n");
        printf("8 - Destruir arvore\n");
        printf("9 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Valor a inserir: ");
                scanf("%d", &valor);
                if (insereABP(&arvore, valor))
                    printf("Inserido com sucesso.\n");
                else
                    printf("Erro ou valor duplicado.\n");
                break;
            case 2:
                printf("Valor a buscar: ");
                scanf("%d", &valor);
                if (buscaABP(arvore, valor))
                    printf("Valor encontrado.\n");
                else
                    printf("Nao encontrado.\n");
                break;
            case 3:
                printf("Valor a remover: ");
                scanf("%d", &valor);
                if (removeABP(&arvore, valor))
                    printf("Removido com sucesso.\n");
                else
                    printf("Valor nao encontrado.\n");
                break;
            case 4:
                imprimeEmOrdem(arvore);
                printf("\n");
                break;
            case 5:
                imprimePreOrdem(arvore);
                printf("\n");
                break;
            case 6:
                imprimePosOrdem(arvore);
                printf("\n");
                break;
            case 7:
                printf("Total de nos: %d\n", contaNos(arvore));
                break;
            case 8:
                destroiABP(&arvore);
                printf("Arvore destruida.\n");
                break;
            case 9:
                destroiABP(&arvore);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (op != 9);

    return 0;
}
