#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX 100

typedef struct
{
    char nome[50];
    double preco;
    int quantidade;
} Item;

typedef struct
{
    Item item[MAX];
    int quantItem;
    char endereco[100];
    double preco;
    char status[20];
} Pedido;

Pedido criarPedido();
void adicionarItem(Pedido *p, Item item);
void removerItem(Pedido *p, char nome[]);
double calcularTotal(Pedido *p);
void definirEndereco(Pedido *p, char endereco[]);
void alterarStatus(Pedido *p, char status[]);
void finalizarPedido(Pedido *p);
void imprimirPedido(Pedido *p);

#endif