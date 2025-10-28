#include <stdio.h>
#include <string.h>
#include "conta.h"

void criarConta(ContaBancaria *c, int id, char *nome)
{
    c->id = id;
    strcpy(c->nome, nome);
    c->saldo = 0;

    printf("Conta criada com sucesso no nome de %s, com identificacao de %d e saldo no valor de R$ %.2f\n", c->nome, c->id, c->saldo);
}
void depositar(ContaBancaria *c, double valor)
{
    c->saldo += valor;
    printf("O seu deposito no valor de %.2f foi realizado com sucesso! Seu saldo e de R$ %2.f\n", valor, c->saldo);
}
void sacar(ContaBancaria *c, double valor)
{
    c->saldo -= valor;
    printf("O seu saque no valor de %.2f foi realizado com sucesso! Seu saldo e de R$ %2.f\n", valor, c->saldo);
}
void consultarSaldo(ContaBancaria *c)
{
    printf("Seu saldo é de R$ %2.f\n", c->saldo);
}
void imprimirInfo(ContaBancaria *c)
{
    printf("Aqui esta a informacao da sua conta:\n");
    printf("Nome: %s\n", c->nome);
    printf("ID pessoal: %d\n", c->id);
    printf("Saldo: R$ %2.f\n", c->saldo);
}
