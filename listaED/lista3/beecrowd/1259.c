#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    int num1 = *(const int *)a;
    int num2 = *(const int *)b;

    if ((num1 % 2) != (num2 % 2)) // um par e um impar
    {
        return (num1 % 2) - (num2 % 2);
    }
    if (num1 % 2 == 0)
    {
        return num1 - num2;
    }
    else
    {
        return num2 - num1;
    }
}
int main()
{
    int N;
    scanf("%d", &N);

    int numeros[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numeros[i]);
    }

    qsort(numeros, N, sizeof(int), comparar);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", numeros[i]);
    }

    return 0;
}