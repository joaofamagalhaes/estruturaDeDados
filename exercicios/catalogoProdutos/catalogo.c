#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

void criarCatalogo(CatalogoProdutos *c)
{
    c->totalProdutos = 0;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade)
{
    int quantProdutos;
    printf("Quantos produtos voce deseja adicionar?\n");
    scanf("%d", &quantProdutos);
    for (int i = 0; i < quantProdutos; i++)
    {
        /* code */
    }
}
int verificarEstoque(CatalogoProdutos *c, char *nome);
void imprimirCatalogo(CatalogoProdutos *c);