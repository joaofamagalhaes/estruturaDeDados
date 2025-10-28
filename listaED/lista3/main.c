#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao.h"

int main()
{
    int vetor1[] = {1, 4, 7, 9, 14, 17};
    int tam1 = 6;
    int vetor2[] = {21, 19, 17, 9, 5, 1};
    int tam2 = 6;
    int vetor3[] = {15, 27, 2, 18, 11, 6};
    int tam3 = 6;
    int vetor4[] = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1};
    int tam4 = 12;
    int vetor5[] = {2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11};
    int tam5 = 12;
    int vetor6[] = {18, 29, 17, 29, 23, 21, 23, 8, 14, 6};
    int tam6 = 10;

    printf("\n");
    for (int i = 0; i < tam6; i++)
    {
        printf("%d ", vetor6[i]);
    }
    printf("\n");

    // bubbleSort(vetor6, tam6);
    // insertionSort(vetor6, tam6);
    // selectionSort(vetor6, tam6);
    // shellSort(vetor6, tam6);

    // mergePrint(vetor6, tam6);
    quickPrint(vetor6, tam6);
    // heapSort(vetor6, tam6);

    return 0;
}