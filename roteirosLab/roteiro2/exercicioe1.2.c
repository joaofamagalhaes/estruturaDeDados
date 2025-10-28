#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    double preco;
    int quantidade;
} Produto;

typedef struct
{
    Produto produtos[100];
    int totalProdutos;
} CatalogoProdutos;

void criarCatalogo(CatalogoProdutos *c)
{
    c->totalProdutos = 0;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade)
{
    if (c->totalProdutos < 100)
    {
        Produto *p = &c->produtos[c->totalProdutos];
        strcpy(p->nome, nome);
        p->preco = preco;
        p->quantidade = quantidade;
        c->totalProdutos++;
    }
    else
    {
        printf("Catalogo cheio! Nao e possivel adicionar mais produtos.\n");
    }
}

int verificarEstoque(CatalogoProdutos *c, char *nome)
{
    for (int i = 0; i < c->totalProdutos; i++)
    {
        if (strcmp(c->produtos[i].nome, nome) == 0)
        {
            return c->produtos[i].quantidade;
        }
    }
    return -1;
}

void imprimirCatalogo(CatalogoProdutos *c)
{
    printf("\n--- Catalogo de Produtos ---\n");
    for (int i = 0; i < c->totalProdutos; i++)
    {
        Produto *p = &c->produtos[i];
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", p->nome);
        printf("Preco: R$ %.2f\n", p->preco);
        printf("Quantidade: %d\n\n", p->quantidade);
    }
}

int main()
{
    CatalogoProdutos catalogo;
    criarCatalogo(&catalogo);

    adicionarProduto(&catalogo, "Camiseta", 29.99, 50);
    adicionarProduto(&catalogo, "Calca Jeans", 99.90, 30);
    adicionarProduto(&catalogo, "Tenis", 199.90, 20);

    imprimirCatalogo(&catalogo);

    char nomeBusca[100] = "Calca Jeans";
    int estoque = verificarEstoque(&catalogo, nomeBusca);
    if (estoque != -1)
    {
        printf("Estoque de '%s': %d unidades\n", nomeBusca, estoque);
    }
    else
    {
        printf("Produto '%s' nao encontrado no catalogo\n", nomeBusca);
    }

    return 0;
}
