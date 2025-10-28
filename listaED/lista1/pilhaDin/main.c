#include <stdio.h>
#include <stdlib.h>
#include "pilhaDin.h"

int main()
{
    pilhaDin *topo = criarPilha();

    inserePilha(&topo, 1);
    inserePilha(&topo, 2);
    inserePilha(&topo, 3);
    inserePilha(&topo, 4);

    imprimirPilha(topo);
    imprimirReversoPilha(topo);

    return 0;
}
