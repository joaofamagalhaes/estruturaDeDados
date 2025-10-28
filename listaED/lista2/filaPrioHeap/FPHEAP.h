#ifndef FPHEAP_H
#define FPHEAP_H
#define MAX 100

typedef struct {
    int info;
    int prio;
} NO;

typedef struct {
    int qtd;
    NO dados[MAX];
} filaP;

filaP* criaFila();
void destroiFila(filaP *fp);
int inserePrio(filaP *fp, int num, int prio);
void ajustaHeapInsere(filaP *fp, int i);
int removeIni(filaP *fp);
void ajustaHeapRemove(filaP *fp, int i);
void verInicio(filaP *fp);
int tamanho(filaP *fp);
void imprime(filaP *fp);
int estaVazia(filaP *fp);

#endif
