#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[51];
    char cor[10];
    char tamanho;
} Camiseta;

int comparar(const void *a, const void *b)
{

    const Camiseta *c1 = (const Camiseta *)a;
    const Camiseta *c2 = (const Camiseta *)b;

    int comparaCor = strcmp(c1->cor, c2->cor);
    if (comparaCor != 0)
    {
        return comparaCor;
    }

    if (c1->tamanho != c2->tamanho)
    {
        return c2->tamanho - c1->tamanho;
    }

    return strcmp(c1->nome, c2->nome);
}

int main()
{
    int N;
    int primeiro = 1;

    while (scanf("%d", &N) == 1 && N != 0)
    {

        if (!primeiro)
        {
            printf("\n");
        }

        Camiseta pedidos[N];
        getchar();

        for (int i = 0; i < N; i++)
        {
            fgets(pedidos[i].nome, 51, stdin);
            pedidos[i].nome[strcspn(pedidos[i].nome, "\n")] = '\0';

            scanf("%s %c", pedidos[i].cor, &pedidos[i].tamanho);

            getchar();
        }

        qsort(pedidos, N, sizeof(Camiseta), comparar);

        for (int i = 0; i < N; i++)
        {
            printf("%s %c %s\n", pedidos[i].cor, pedidos[i].tamanho, pedidos[i].nome);
        }

        primeiro = 0;
    }

    return 0;
}