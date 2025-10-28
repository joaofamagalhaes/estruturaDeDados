// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// void ordenarTamanho(char palavras[][51], int numPalavras)
// {
//     int i, j;
//     char temp[51];

//     for (i = 0; i < numPalavras - 1; i++)
//     {
//         for (j = 0; j < numPalavras - i - 1; j++)
//         {
//             if (strlen(palavras[j]) < strlen(palavras[j + 1]))
//             {

//                 strcpy(temp, palavras[j]);
//                 strcpy(palavras[j], palavras[j + 1]);
//                 strcpy(palavras[j + 1], temp);
//             }
//         }
//     }
// }

// int main()
// {
//     int N;

//     scanf("%d", &N);
//     while (N >= 0)
//     {
//         char linhaCompleta[2601];
//         char palavras[51][51];
//         int numPalavras = 0;

//         fgets(linhaCompleta, sizeof(linhaCompleta), stdin);
//         linhaCompleta[strcspn(linhaCompleta, "\n")] = '\0';

//         char *token = strtok(linhaCompleta, " ");

//         while (token != NULL)
//         {
//             strcpy(palavras[numPalavras], token);
//             numPalavras++;
//             token = strtok(NULL, " ");
//         }

//         ordenarTamanho(palavras, numPalavras);

//         for (int i = 0; i < numPalavras; i++)
//         {
//             printf("%s", palavras[i]);
//             if (i < numPalavras - 1)
//             {
//                 printf(" ");
//             }
//         }
//         printf("\n");

//         N--;
//     }

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ordenarPorTamanho(char palavras[][51], int num_palavras)
{
    int i, j;
    char temp[51];
    for (i = 0; i < num_palavras - 1; i++)
    {
        for (j = 0; j < num_palavras - i - 1; j++)
        {
            if (strlen(palavras[j]) < strlen(palavras[j + 1]))
            {
                strcpy(temp, palavras[j]);
                strcpy(palavras[j], palavras[j + 1]);
                strcpy(palavras[j + 1], temp);
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar(); // consome o '\n'

    char **resultados_finais = malloc(N * sizeof(char *));
    if (resultados_finais == NULL)
    {
        printf("Erro de alocação de memória principal.\n");
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        char linha_completa[2601];
        char palavras[51][51];
        int num_palavras = 0;

        fgets(linha_completa, sizeof(linha_completa), stdin);
        linha_completa[strcspn(linha_completa, "\n")] = '\0';

        char *token = strtok(linha_completa, " ");
        while (token != NULL)
        {
            strcpy(palavras[num_palavras], token);
            num_palavras++;
            token = strtok(NULL, " ");
        }

        ordenarPorTamanho(palavras, num_palavras);

        char linha_ordenada[2601] = "";

        for (int j = 0; j < num_palavras; j++)
        {
            strcat(linha_ordenada, palavras[j]);
            if (j < num_palavras - 1)
            {
                strcat(linha_ordenada, " ");
            }
        }

        resultados_finais[i] = malloc(strlen(linha_ordenada) + 1);
        if (resultados_finais[i] != NULL)
        {
            strcpy(resultados_finais[i], linha_ordenada);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (resultados_finais[i] != NULL)
        {
            printf("%s\n", resultados_finais[i]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        free(resultados_finais[i]);
    }
    free(resultados_finais);

    return 0;
}