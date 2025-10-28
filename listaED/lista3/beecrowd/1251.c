#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ascii;
    int frequencia;
} CharFreq;

int comparar(const void *a, const void *b)
{

    const CharFreq *p1 = (const CharFreq *)a;
    const CharFreq *p2 = (const CharFreq *)b;

    if (p1->frequencia != p2->frequencia)
    {

        return p1->frequencia - p2->frequencia;
    }

    else
    {
        return p2->ascii - p1->ascii;
    }
}

int main()
{
    char linha[1002];
    int index = 1;

    while (fgets(linha, sizeof(linha), stdin) != NULL)
    {

        if (index != 1)
            printf("\n");

        int contagem[128] = {0};

        for (int i = 0; linha[i] != '\0' && linha[i] != '\n'; i++)
        {
            contagem[(int)linha[i]]++;
        }

        CharFreq resultado[96];
        int unicos = 0;

        for (int i = 32; i < 128; i++)
        {
            if (contagem[i] > 0)
            {
                resultado[unicos].ascii = i;
                resultado[unicos].frequencia = contagem[i];
                unicos++;
            }
        }

        qsort(resultado, unicos, sizeof(CharFreq), comparar);

        for (int i = 0; i < unicos; i++)
        {
            printf("%d %d\n", resultado[i].ascii, resultado[i].frequencia);
        }

        index = 0;
    }

    return 0;
}