#include <stdio.h>
#include <stdlib.h>
#include "FPHEAP.h"

filaP* criaFila() {
    filaP* fp = malloc(sizeof(filaP));
    if (fp != NULL) {
        fp->qtd = 0;
    }
    return fp;
}

void destroiFila(filaP *fp) {
    if (fp != NULL)
        free(fp);
}

void trocaNo(NO *a, NO *b) {
    NO temp = *a;
    *a = *b;
    *b = temp;
}

void ajustaHeapInsere(filaP *fp, int filho) {
    while (filho > 0) {
        int pai = (filho - 1) / 2;
        if (fp->dados[filho].prio < fp->dados[pai].prio) {
            trocaNo(&fp->dados[filho], &fp->dados[pai]);
            filho = pai;
        } else {
            break;
        }
    }
}

int inserePrio(filaP *fp, int num, int prio) {
    if (fp == NULL || fp->qtd == MAX)
        return 0;
    fp->dados[fp->qtd].info = num;
    fp->dados[fp->qtd].prio = prio;
    ajustaHeapInsere(fp, fp->qtd);
    fp->qtd++;
    return 1;
}

void ajustaHeapRemove(filaP *fp, int pai) {
    int filho = 2 * pai + 1;
    while (filho < fp->qtd) {
        if (filho + 1 < fp->qtd && fp->dados[filho + 1].prio < fp->dados[filho].prio)
            filho++;
        if (fp->dados[filho].prio < fp->dados[pai].prio) {
            trocaNo(&fp->dados[filho], &fp->dados[pai]);
            pai = filho;
            filho = 2 * pai + 1;
        } else {
            break;
        }
    }
}

int removeIni(filaP *fp) {
    if (fp == NULL || fp->qtd == 0)
        return 0;
    fp->dados[0] = fp->dados[--fp->qtd];
    ajustaHeapRemove(fp, 0);
    return 1;
}

void verInicio(filaP *fp) {
    if (fp != NULL && fp->qtd > 0) {
        printf("Inicio: Num %d - Prio %d\n", fp->dados[0].info, fp->dados[0].prio);
    }
}

int tamanho(filaP *fp) {
    if (fp == NULL)
        return -1;
    return fp->qtd;
}

void imprime(filaP *fp) {
    if (fp == NULL || fp->qtd == 0)
        return;
    for (int i = 0; i < fp->qtd; i++) {
        printf("Num %d - Prio %d | ", fp->dados[i].info, fp->dados[i].prio);
    }
    printf("\n");
}

int estaVazia(filaP *fp) {
    if (fp == NULL)
        return -1;
    return (fp->qtd == 0);
}
