#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    while (N--)
    {
        char linhaComp[21001];
        char listaItem[1000][21];
        int numItem = 0;

        if (fgets(linhaComp, sizeof(linhaComp), stdin) == NULL)
        {
            break;
        }
        linhaComp[strcspn(linhaComp, "\n")] = '\0';

        char *token = strtok(linhaComp, " ");

        while (token != NULL && numItem < 1000)
        {
            strcpy(listaItem[numItem], token);
            numItem++;
            token = strtok(NULL, " ");
        }

        qsort(listaItem, numItem, sizeof(listaItem[0]), compara);

        if (numItem > 0)
        {
            printf("%s", listaItem[0]);

            for (int i = 1; i < numItem; i++)
            {
                if (strcmp(listaItem[i], listaItem[i - 1]) != 0)
                {
                    printf(" %s", listaItem[i]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}