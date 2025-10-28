#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void encontrarComuns(int *v1, int *v2, int n)
{

    qsort(v1, n, sizeof(int), comparar);
    qsort(v2, n, sizeof(int), comparar);

    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {
        if (v1[i] == v2[j])
        {
            printf("%d ", v1[i]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }

        else
        {
            j++;
        }
    }
    printf("\n");
}

int main()
{
    int vetor1[] = {15, 27, 2, 18, 11, 6, 88, 32};
    int vetor2[] = {10, 11, 88, 4, 15, 9, 2, 77};
    int n = sizeof(vetor1) / sizeof(vetor1[0]);

    printf("Vetor 1: ");
    for (int i = 0; i < n; i++)
        printf("%d ", vetor1[i]);
    printf("\n");

    printf("Vetor 2: ");
    for (int i = 0; i < n; i++)
        printf("%d ", vetor2[i]);
    printf("\n\n");

    encontrarComuns(vetor1, vetor2, n);

    return 0;
}