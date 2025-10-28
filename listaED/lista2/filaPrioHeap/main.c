#include <stdio.h>
#include <stdlib.h>
#include "FPHEAP.h"

int main() {
    filaP* fp = criaFila();
    int op, num, prio;

    do {
        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Ver início\n4 - Imprimir fila\n5 - Tamanho\n0 - Sair\nEscolha: ");
        scanf("%d", &op);
        switch(op) {
            case 1:
                printf("Digite o valor e a prioridade: ");
                scanf("%d %d", &num, &prio);
                if (inserePrio(fp, num, prio))
                    printf("Inserido com sucesso!\n");
                else
                    printf("Erro ao inserir.\n");
                break;
            case 2:
                if (removeIni(fp))
                    printf("Removido com sucesso!\n");
                else
                    printf("Erro ao remover.\n");
                break;
            case 3:
                verInicio(fp);
                break;
            case 4:
                imprime(fp);
                break;
            case 5:
                printf("Tamanho: %d\n", tamanho(fp));
                break;
        }
    } while (op != 0);

    destroiFila(fp);
    return 0;
}
