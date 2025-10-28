#include <stdio.h>
#include <string.h>

int main()
{
    int quantEnt;
    char entrada[1000];

    scanf("%d", &quantEnt);
    getchar();

    for (int i = 0; i < quantEnt; i++)
    {
        fgets(entrada, 1000, stdin);

        int abertos = 0;
        int dimas = 0;

        for (int j = 0; entrada[j] != '\0'; j++)
        {
            if (entrada[j] == '<')
                abertos++;
            else if (entrada[j] == '>' && abertos > 0)
            {
                abertos--;
                dimas++;
            }
        }

        printf("%d\n", dimas);
    }

    return 0;
}
