#include <stdio.h>
#include <string.h>

typedef struct
{
    int numeroConta;
    double saldo;
    char nome[100];
} ContaBancaria;

void criaConta(ContaBancaria *c, int numero, char *nome)
{
    c->numeroConta = numero;
    c->saldo = 0.00;
    strcpy(c->nome, nome);
}

void depositar(ContaBancaria *c, double valor)
{
    if (valor > 0)
        c->saldo += valor;
    else
        printf("Deposito invalido!");
}

void sacar(ContaBancaria *c, double valor)
{
    if (valor > 0 && c->saldo >= valor)
    {
        c->saldo -= valor;
    }
    else
    {
        printf("Saldo insuficiente ou valor invalido!\n");
    }
}

double consultarSaldo(ContaBancaria *c)
{
    return c->saldo;
}

void imprimirInfo(ContaBancaria *c)
{
    printf("Conta: %d\n", c->numeroConta);
    printf("Titular: %s\n", c->nome);
    printf("Saldo: R$ %.2f\n", c->saldo);
}

int main()
{
    ContaBancaria minhaConta;

    criaConta(&minhaConta, 12345, "Joao Franca");
    depositar(&minhaConta, 2500.0);
    sacar(&minhaConta, 1200.0);

    printf("Saldo atual: R$ %.2f\n", consultarSaldo(&minhaConta));
    imprimirInfo(&minhaConta);

    return 0;
}