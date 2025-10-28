int busca_binaria_dec_iterativa(int *vetor, int tamanho, int chave)
{
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == chave)
        {
            return meio;
        }

        if (vetor[meio] < chave)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return -1;
}

int busca_binaria_dec_recursiva(int *vetor, int inicio, int fim, int chave)
{
    if (inicio > fim)
    {
        return -1;
    }
    int meio = inicio + (fim - inicio) / 2;
    if (vetor[meio] == chave)
    {
        return meio;
    }
    if (vetor[meio] < chave)
    {
        return busca_binaria_dec_recursiva(vetor, inicio, meio - 1, chave);
    }
    else
    {
        return busca_binaria_dec_recursiva(vetor, meio + 1, fim, chave);
    }
}