#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int chave;
    struct NO *proximo;
} NO;

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            printf("\n");
        }

        int endBase, quantC;
        scanf("%d %d", &endBase, &quantC);

        NO *tabelaHash[endBase];
        for (int j = 0; j < endBase; j++)
        {
            tabelaHash[j] = NULL;
        }

        for (int j = 0; j < quantC; j++)
        {
            int valorChave;
            scanf("%d", &valorChave);

            int indexHash = valorChave % endBase;

            NO *novo = (NO *)malloc(sizeof(NO));
            if (novo == NULL)
                return 1;

            novo->chave = valorChave;
            novo->proximo = NULL;

            if (tabelaHash[indexHash] == NULL)
            {
                tabelaHash[indexHash] = novo;
            }
            else
            {
                NO *atual = tabelaHash[indexHash];
                while (atual->proximo != NULL)
                {
                    atual = atual->proximo;
                }
                atual->proximo = novo;
            }
        }

        for (int j = 0; j < endBase; j++)
        {
            printf("%d -> ", j);
            NO *atual = tabelaHash[j];
            while (atual != NULL)
            {
                printf("%d -> ", atual->chave);
                atual = atual->proximo;
            }
            printf("\\\n");
        }

        for (int j = 0; j < endBase; j++)
        {
            NO *atual = tabelaHash[j];
            while (atual != NULL)
            {
                NO *libera = atual;
                atual = atual->proximo;
                free(libera);
            }
        }
    }

    return 0;
}