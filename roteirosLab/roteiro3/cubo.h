#ifndef CUBO_H
#define CUBO_H

typedef struct
{
    int aresta;
} Cubo;

int areaLateral(Cubo *c)
{
    int areaLateral = 4 * (c->aresta * c->aresta);
    return areaLateral;
}

int areaTotal(Cubo *c)
{
    int areaTotal = 6 * (c->aresta * c->aresta);
    return areaTotal;
}

int volume(Cubo *c)
{
    int volume = c->aresta * c->aresta * c->aresta;
    return volume;
}

#endif
