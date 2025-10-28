
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp_aluno.h"

int main() {
    ABP arvore = criaABP();
    int op;
    Aluno a;
    char nome[50];
    No *resultado;

    do {
        printf("\n1 - Inserir aluno\n");
        printf("2 - Buscar aluno pelo nome\n");
        printf("3 - Remover aluno pelo nome\n");
        printf("4 - Imprimir em ordem (alfabetica)\n");
        printf("5 - Mostrar aluno com MAIOR nota\n");
        printf("6 - Mostrar aluno com MENOR nota\n");
        printf("7 - Destruir ABP\n");
        printf("8 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                printf("Nome: ");
                fgets(a.nome, 50, stdin);
                a.nome[strcspn(a.nome, "\n")] = 0;
                printf("Matricula: ");
                scanf("%d", &a.matricula);
                printf("Nota: ");
                scanf("%lf", &a.nota);
                insereABP(&arvore, a);
                break;
            case 2:
                printf("Nome a buscar: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                resultado = buscaABP(arvore, nome);
                if (resultado != NULL)
                    printf("Matricula: %d | Nota: %.2f\n", resultado->dado.matricula, resultado->dado.nota);
                else
                    printf("Aluno nao encontrado.\n");
                break;
            case 3:
                printf("Nome a remover: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                if (removeABP(&arvore, nome))
                    printf("Removido com sucesso.\n");
                else
                    printf("Aluno nao encontrado.\n");
                break;
            case 4:
                imprimeEmOrdem(arvore);
                break;
            case 5: {
                Aluno *maior = maiorNota(arvore);
                if (maior)
                    printf("Maior nota: %s - %.2f\n", maior->nome, maior->nota);
                else
                    printf("Arvore vazia.\n");
                break;
            }
            case 6: {
                Aluno *menor = menorNota(arvore);
                if (menor)
                    printf("Menor nota: %s - %.2f\n", menor->nome, menor->nota);
                else
                    printf("Arvore vazia.\n");
                break;
            }
            case 7:
                destroiABP(&arvore);
                printf("ABP destruida.\n");
                break;
            case 8:
                destroiABP(&arvore);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (op != 8);

    return 0;
}
