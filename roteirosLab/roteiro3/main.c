#include <stdio.h>
#include "conjunto.h"

int main()
{
    Conjunto a, b, resultado;
    criaConj(&a);
    criaConj(&b);

    inserirElem(&a, 1);
    inserirElem(&a, 2);
    inserirElem(&a, 3);

    inserirElem(&b, 3);
    inserirElem(&b, 4);
    inserirElem(&b, 5);

    printf("Conjunto A:\n");
    for (int i = 0; i < a.tam; i++)
        printf("%d ", a.elementos[i]);
    printf("\nConjunto B:\n");
    for (int i = 0; i < b.tam; i++)
        printf("%d ", b.elementos[i]);
    printf("\n");

    resultado = uniaoConj(a, b);
    printf("Uniao:\n");
    for (int i = 0; i < resultado.tam; i++)
        printf("%d ", resultado.elementos[i]);
    printf("\n");

    resultado = intersecaoConj(a, b);
    printf("Intersecao:\n");
    for (int i = 0; i < resultado.tam; i++)
        printf("%d ", resultado.elementos[i]);
    printf("\n");

    resultado = diferencaConj(a, b);
    printf("Diferenca (A - B):\n");
    for (int i = 0; i < resultado.tam; i++)
        printf("%d ", resultado.elementos[i]);
    printf("\n");

    pertenceElem(&a, 2);
    pertenceElem(&b, 6);

    printf("Menor de A: %d\n", menorElem(&a));
    printf("Maior de B: %d\n", maiorElem(&b));

    comparaElem(&a, &b);
    tamConj(&a);
    vazioConj(&b);

    return 0;
}
