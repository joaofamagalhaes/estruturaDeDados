#include <stdio.h>
#include <string.h>

typedef struct
{
    char *pais;
    char *frase;
} Traducao;

Traducao dicionario[] = {
    {"brasil", "Feliz Natal!"},
    {"alemanha", "Frohliche Weihnachten!"},
    {"austria", "Frohe Weihnacht!"},
    {"coreia", "Chuk Sung Tan!"},
    {"espanha", "Feliz Navidad!"},
    {"grecia", "Kala Christougena!"},
    {"estados-unidos", "Merry Christmas!"},
    {"inglaterra", "Merry Christmas!"},
    {"australia", "Merry Christmas!"},
    {"portugal", "Feliz Natal!"},
    {"suecia", "God Jul!"},
    {"turquia", "Mutlu Noeller"},
    {"argentina", "Feliz Navidad!"},
    {"chile", "Feliz Navidad!"},
    {"mexico", "Feliz Navidad!"},
    {"antardida", "Merry Christmas!"},
    {"canada", "Merry Christmas!"},
    {"irlanda", "Nollaig Shona Dhuit!"},
    {"belgica", "Zalig Kerstfeest!"},
    {"italia", "Buon Natale!"},
    {"libia", "Buon Natale!"},
    {"siria", "Milad Mubarak!"},
    {"marrocos", "Milad Mubarak!"},
    {"japao", "Merii Kurisumasu!"}};

int main()
{
    char pais[51];

    int N = sizeof(dicionario) / sizeof(dicionario[0]);

    while (scanf("%s", pais) == 1)
    {
        int achou = 0;

        for (int i = 0; i < N; i++)
        {

            if (strcmp(pais, dicionario[i].pais) == 0)
            {
                printf("%s\n", dicionario[i].frase);
                achou = 1;
                break;
            }
        }

        if (!achou)
        {
            printf("--- NOT FOUND ---\n");
        }
    }

    return 0;
}