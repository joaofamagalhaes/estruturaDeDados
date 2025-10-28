#ifndef CONTA_H
#define CONTA_H

typedef struct
{
    int id;
    double saldo;
    char nome[100];

} ContaBancaria;

void criarConta(ContaBancaria *c, int id, char *nome);
void depositar(ContaBancaria *c, double valor);
void sacar(ContaBancaria *c, double valor);
void consultarSaldo(ContaBancaria *c);
void imprimirInfo(ContaBancaria *c);

#endif