#ifndef CATALOGO_H
#define CATALOGO_H

typedef struct
{
    int quantidade;
    double preco;
    char nome[100];
} Produtos;

typedef struct
{
    Produtos idProdutos[100];
    int totalProdutos;
} CatalogoProdutos;

void criarCatalogo(CatalogoProdutos *c);
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade);
int verificarEstoque(CatalogoProdutos *c, char *nome);
void imprimirCatalogo(CatalogoProdutos *c);

#endif