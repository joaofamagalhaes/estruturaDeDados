#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

int main()
{
    Fracao f1;
    Fracao f2;
    int opcao, num, den;

    do
    {
        printf("--------------- Sistema de Fracoes ---------------\n");
        printf("Digite a opcao desejada: \n");
        printf("1 - Some fracoes.\n");
        printf("2 - Subtraia fracoes.\n");
        printf("3 - Multiplique fracoes.\n");
        printf("4 - Divida fracoes.\n");
        printf("5 - Simplifique uma fracao.\n");
        printf("6 - Imprima o decimal de uma fracao existente.\n");
        printf("7 - Sair do menu.\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o numerador e o denominador (consecutivamente) da primeira fracao: \n");
            scanf("%d %d", &num, &den);
            f1 = criaFracao(num, den);

            printf("Digite o numerador e o denominador (consecutivamente) da segunda fracao: \n");
            scanf("%d %d", &num, &den);
            f2 = criaFracao(num, den);

            imprime(somaFracao(f1, f2));

            break;
        case 2:
            printf("Digite o numerador e o denominador (consecutivamente) da primeira fracao: \n");
            scanf("%d %d", &num, &den);
            f1 = criaFracao(num, den);

            printf("Digite o numerador e o denominador (consecutivamente) da segunda fracao: \n");
            scanf("%d %d", &num, &den);
            f2 = criaFracao(num, den);

            imprime(subtraiFracao(f1, f2));
            break;
        case 3:

            printf("Digite o numerador e o denominador (consecutivamente) da primeira fracao: \n");
            scanf("%d %d", &num, &den);
            f1 = criaFracao(num, den);

            printf("Digite o numerador e o denominador (consecutivamente) da segunda fracao: \n");
            scanf("%d %d", &num, &den);
            f2 = criaFracao(num, den);

            imprime(multiplicaFracao(f1, f2));
            break;

        case 4:
            printf("Digite o numerador e o denominador (consecutivamente) da primeira fracao: \n");
            scanf("%d %d", &num, &den);
            f1 = criaFracao(num, den);

            printf("Digite o numerador e o denominador (consecutivamente) da segunda fracao: \n");
            scanf("%d %d", &num, &den);
            f2 = criaFracao(num, den);

            imprime(divideFracao(f1, f2));
            break;
        case 5:
            printf("Digite o numerado e o denominador da funcao a ser simplificada (se possivel) :\n");
            scanf("%d %d", &num, &den);
            f1 = criaFracao(num, den);
            imprime(simplifica(f1));

            break;
        case 6:
            printf("Digite o numerado e o denominador da funcao que voce quer saber o a forma decimal:\n");
            scanf("%d %d", &num, &den);
            f1 = criaFracao(num, den);
            printf("%.2f\n", decimal(f1));

            break;
        case 7:
            printf("Saindo...\n");
            return 1;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 7);

    return 0;
}