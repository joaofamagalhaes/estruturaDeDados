#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

Pedido criarPedido()
{
    Pedido p;
    p.quantItem = 0;
    p.preco = 0;
    strcpy(p.status, "Pendente");
    strcpy(p.endereco, "Nao definido");
    return p;
};
void adicionarItem(Pedido *p, Item item)
{

    if (p->quantItem >= MAX)
        return;
    p->item[p->quantItem++] = item;
    printf("%s adicionado com sucesso, o preco total eh %.2f\n", item.nome, calcularTotal(p));
};
void removerItem(Pedido *p, char nome[])
{
    for (int i = 0; i < p->quantItem; i++)
    {
        if (strcmp(p->item[i].nome, nome) == 0)
        {
            for (int j = i; j < p->quantItem - 1; j++)
            {
                p->item[j] = p->item[j - 1];
            }
            p->quantItem--;
            printf("%s removido com sucesso, o preco total eh %.2f\n", nome, calcularTotal(p));
        }
    }
}
double calcularTotal(Pedido *p)
{
    p->preco = 0.0;
    for (int i = 0; i < p->quantItem; i++)
    {
        p->preco += p->item[i].preco;
    }
    return p->preco;
}
void definirEndereco(Pedido *p, char endereco[])
{
    strcpy(p->endereco, endereco);
    printf("Endereco do pedido definido!\nEndereco: %s\n", p->endereco);
}
void alterarStatus(Pedido *p, char status[])
{
    strcpy(p->status, status);
    printf("Status do pedido atualizado!\nStatus: %s\n", p->status);
}
void finalizarPedido(Pedido *p)
{
    printf("\n------------------ Pedido finalizado ------------------\n");
    imprimirPedido(p);
}
void imprimirPedido(Pedido *p)
{
    printf("Endereco: %s\n", p->endereco);
    printf("Status: %s\n", p->status);
    printf("Itens:\n");
    for (int i = 0; i < p->quantItem; i++)
    {
        printf(" - %s | R$%.2f x %d\n", p->item[i].nome, p->item[i].preco, p->item[i].quantidade);
    }
    printf("Total: R$%.2f\n", p->preco);
}