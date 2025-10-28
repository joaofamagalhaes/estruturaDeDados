// algoritmos inspirados nas video aulas do Prof. Andre Backes no Youtube https://www.youtube.com/@progdescomplicada e nas aulas de Estrutura de Dados ministradas pelo Prof. Guilherme Pena da UFSJ
// João França Aguilar Magalhães - aula de Estrutura de Dados UFSJ 2025

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao.h"

// === algoritmos de ordenacao simples O(N^2) ====

void bubbleSort(int *v, int tam)
{
    int i, j, aux;
    int comp = 0;
    int troca = 0;

    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - i - 1; j++)
        {
            comp++;
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                troca += 3; // conta 3 movimentações por troca
            }
        }
    }

    printf("\nVetor ordenado por BubbleSort: \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Numero de comparacoes: %d\n", comp);
    printf("Numero de trocas: %d\n", troca);
}
// compara o elemento com o da posição anterior e  o move os outros para frente
void insertionSort(int *v, int tam)
{
    int comp = 0;
    int troca = 0;
    int i, j, aux;

    for (i = 1; i < tam; i++)
    {
        aux = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > aux)
        {
            comp++;
            v[j + 1] = v[j];
            troca++;
            j--;
        }
        if (j >= 0)
        {
            comp++;
        }
        v[j + 1] = aux;
        troca++;
    }

    printf("\nVetor ordenado por InsertionSort: \n");
    for (int k = 0; k < tam; k++)
    {
        printf("%d ", v[k]);
    }
    printf("\n");
    printf("Numero de comparacoes: %d\n", comp);
    printf("Numero de trocas: %d\n", troca);
}
// compara o elemento com o menor elemento do vetor, repete para cada posição
void selectionSort(int *v, int tam)
{
    int troca = 0;
    int comp = 0;
    int i, j, menor_idx;

    // o loop principal percorre o vetor para posicionar o elemento correto em cada posicao 'i'
    for (i = 0; i < tam - 1; i++)
    {
        menor_idx = i;

        for (j = i + 1; j < tam; j++)
        {
            comp++;
            if (v[j] < v[menor_idx])
            {
                menor_idx = j;
            }
        }

        if (i != menor_idx)
        {
            int aux = v[i];
            v[i] = v[menor_idx];
            v[menor_idx] = aux;
            troca = troca + 3;
        }
    }

    printf("\nVetor ordenado por SelectionSort: \n");
    for (int k = 0; k < tam; k++)
    {
        printf("%d ", v[k]);
    }
    printf("\n");
    printf("Numero de comparacoes: %d\n", comp);
    printf("Numero de trocas: %d\n", troca); // Este agora e o numero de movimentos
}

void shellSort(int *v, int tam)
{
    int comp = 0;
    int troca = 0;
    int h = 1;

    // calcula o 'h' inicial (sequencia de Knuth)
    while (h < tam)
        h = 3 * h + 1;

    while (h > 1)
    {
        h = h / 3;
        // insertion sort com o gap 'h'
        for (int i = h; i < tam; i++)
        {
            int atual = v[i];
            int j = i;

            while (j >= h && atual < v[j - h])
            {

                comp++;
                v[j] = v[j - h];
                troca++;
                j = j - h;
            }

            if (j >= h)
            {
                comp++;
            }

            v[j] = atual;
            troca++;
        }
    }

    printf("\nVetor ordenado por ShellSort: \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Numero de comparacoes: %d\n", comp);
    printf("Numero de trocas: %d\n", troca);
}
//-------------------------------//

// algoritmos de ordenacao sofisticados N(Log N)

void merge(int *v, int *aux, int inicio, int meio, int fim, int *comp, int *troca)
{
    int tam = fim - inicio + 1;
    int i = inicio, j = meio + 1, k = 0;
    while (i <= meio && j <= fim)
    {
        (*comp)++;
        if (v[i] < v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
        k++;
        (*troca)++;
    }
    while (i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
        (*troca)++;
    }
    while (j <= fim)
    {
        aux[k] = v[j];
        j++;
        k++;
        (*troca)++;
    }
    for (i = inicio, k = 0; i <= fim; i++, k++)
    {
        v[i] = aux[k];
    }
}

void mergeSort(int *v, int *aux, int inicio, int fim, int *comp, int *troca)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(v, aux, inicio, meio, comp, troca);
        mergeSort(v, aux, meio + 1, fim, comp, troca);
        merge(v, aux, inicio, meio, fim, comp, troca);
    }
}
void mergePrint(int *v, int tam)
{
    int *aux = malloc(tam * sizeof(int));
    int comp = 0;
    int troca = 0;

    mergeSort(v, aux, 0, tam - 1, &comp, &troca);

    printf("\nVetor ordenado por MergeSort: \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Numero de comparacoes: %d\n", comp);
    printf("Numero de trocas: %d\n", troca);
}

int pivoParticiona(int *v, int inicio, int fim, int *comp, int *troca)
{
    int pivo = v[inicio];
    int i = inicio + 1;
    int j = fim;

    while (i <= j)
    {

        (*comp)++;
        while (i <= fim && v[i] <= pivo)
        {
            i++;

            if (i <= fim)
                (*comp)++;
        }

        (*comp)++;
        while (j > inicio && v[j] > pivo)
        {
            j--;

            if (j > inicio)
                (*comp)++;
        }

        if (i < j)
        {

            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            (*troca) += 3;
            i++;
            j--;
        }
    }

    v[inicio] = v[j];
    v[j] = pivo;
    (*troca) += 3;

    return j;
}

void quickSort(int *v, int inicio, int fim, int *comp, int *troca)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        int aux;

        if (v[inicio] > v[meio])
        {
            aux = v[inicio];
            v[inicio] = v[meio];
            v[meio] = aux;
            (*troca) += 3;
        }
        if (v[inicio] > v[fim])
        {
            aux = v[inicio];
            v[inicio] = v[fim];
            v[fim] = aux;
            (*troca) += 3;
        }
        if (v[meio] > v[fim])
        {
            aux = v[meio];
            v[meio] = v[fim];
            v[fim] = aux;
            (*troca) += 3;
        }

        aux = v[inicio];
        v[inicio] = v[meio];
        v[meio] = aux;
        (*troca) += 3;

        int pivoPos = pivoParticiona(v, inicio, fim, comp, troca);
        quickSort(v, inicio, pivoPos - 1, comp, troca);
        quickSort(v, pivoPos + 1, fim, comp, troca);
    }
}

void quickPrint(int *v, int tam)
{
    int comp = 0;
    int trocas = 0;

    quickSort(v, 0, tam - 1, &comp, &trocas);

    printf("\nVetor ordenado por QuickSort: \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Numero de comparacoes: %d\n", comp);
    printf("Numero de trocas: %d\n", trocas);
}

void criaHeap(int *v, int tam, int i, int *comp, int *troca)
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    (*comp)++;
    if (esq < tam && v[esq] > v[maior])
    {
        maior = esq;
    }

    (*comp)++;
    if (dir < tam && v[dir] > v[maior])
    {
        maior = dir;
    }

    if (maior != i)
    {
        int aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        (*troca) += 3;

        criaHeap(v, tam, maior, comp, troca);
    }
}

void heapSort(int *v, int tam)
{
    int comparacoes = 0;
    int trocas = 0;

    for (int i = tam / 2 - 1; i >= 0; i--)
    {
        criaHeap(v, tam, i, &comparacoes, &trocas);
    }

    for (int i = tam - 1; i > 0; i--)
    {
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        trocas += 3;

        criaHeap(v, i, 0, &comparacoes, &trocas);
    }

    printf("\nVetor ordenado por HeapSort: \n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Numero de trocas: %d\n", trocas);
}