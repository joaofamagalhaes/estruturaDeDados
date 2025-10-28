#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

int main()
{

    Cubo c;
    printf("Digite o valor para as arestas do cubo:\n");
    scanf("%d", &c.aresta);

    printf("Cubo de aresta %d\n", c.aresta);
    printf("Area lateral: %d\n", areaLateral(&c));
    printf("Area total: %d\n", areaTotal(&c));
    printf("Volume: %d\n", volume(&c));

    return 0;
}