#ifndef FRACAO_H
#define FRACAO_H

typedef struct
{
    int numerador;
    int denominador;

} Fracao;

Fracao criaFracao(int num, int den);
Fracao somaFracao(Fracao f1, Fracao f2);
Fracao subtraiFracao(Fracao f1, Fracao f2);
Fracao multiplicaFracao(Fracao f1, Fracao f2);
Fracao divideFracao(Fracao f1, Fracao f2);
Fracao simplifica(Fracao f);
double decimal(Fracao f);
void imprime(Fracao f);

#endif