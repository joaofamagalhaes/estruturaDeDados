#ifndef ORDENACAO_H
#define ORDENACAO_H

void bubbleSort(int *v, int tam);
void insertionSort(int *v, int tam);
void selectionSort(int *v, int tam);
void shellSort(int *v, int tam);
void mergeSort(int *v, int *aux, int inicio, int fim, int *comp, int *troca);
void merge(int *v, int *aux, int inicio, int meio, int fim, int *comp, int *troca);
void mergePrint(int *v, int tam);
void quickSort(int *v, int inicio, int fim, int *comp, int *troca);
int pivoParticiona(int *v, int inicio, int fim, int *comp, int *troca);
void quickPrint(int *v, int tam);
void heapSort(int *v, int tam);
void criaHeap(int *v, int tam, int i, int *comp, int *troca);

#endif