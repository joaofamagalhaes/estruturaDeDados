#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

Fracao criaFracao(int num, int den)
{
    Fracao f;
    f.numerador = num;
    f.denominador = den;
    return f;
};
Fracao somaFracao(Fracao f1, Fracao f2)
{
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return simplifica(resultado);
};
Fracao subtraiFracao(Fracao f1, Fracao f2)
{
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    resultado.denominador = f1.denominador * f2.denominador;
    return simplifica(resultado);
};
Fracao multiplicaFracao(Fracao f1, Fracao f2)
{
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;
    return simplifica(resultado);
};
Fracao divideFracao(Fracao f1, Fracao f2)
{
    Fracao resultado;
    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f1.denominador * f2.numerador;
    return simplifica(resultado);
};
Fracao simplifica(Fracao f)
{
    int divisor = mdc(f.numerador, f.denominador);
    f.numerador /= divisor;
    f.denominador /= divisor;
    return f;
};
double decimal(Fracao f)
{
    return f.numerador / f.denominador;
};
void imprime(Fracao f)
{
    printf("%d/%d\n", f.numerador, f.denominador);
};