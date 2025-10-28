#include <stdio.h>

int main()
{
    int n;

    while (scanf("%d", &n) && n != 0)
    {
        int fila[50];
        int ini = 0, fim = n - 1;
        int descartadas[50], qtdDescartadas = 0;

        for (int i = 0; i < n; i++)
        {
            fila[i] = i + 1;
        }

        while (fim - ini >= 1)
        {
            descartadas[qtdDescartadas++] = fila[ini++];

            fila[++fim] = fila[ini++];
        }

        printf("Discarded cards:");
        for (int i = 0; i < qtdDescartadas; i++)
        {
            if (i == 0)
                printf(" %d", descartadas[i]);
            else
                printf(", %d", descartadas[i]);
        }
        printf("\nRemaining card: %d\n", fila[ini]);
    }

    return 0;
}