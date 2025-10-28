#include <stdio.h>
#include <string.h>

int main()
{
    char exp[1001];

    while (fgets(exp, 1001, stdin) != NULL)
    {
        int equal = 0;
        int correto = 1;

        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(')
            {
                equal++;
            }
            else if (exp[i] == ')')
            {
                equal--;
                if (equal < 0)
                {
                    correto = 0;
                    break;
                }
            }
        }

        if (equal != 0)
            correto = 0;

        if (correto)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}
