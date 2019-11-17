#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

void crearColaC(t_colaC* pc)
{
    *pc = NULL;

}
int ponerEnCola(t_colaC* pc, t_infoC* d)
{
    t_nodoColaC *nue = (t_nodoColaC*) malloc(sizeof(t_nodoColaC));
    if(!nue)
        return 0;

    nue->info = *d;

    if(*pc)
    {
        nue->sig = *pc;
        (*pc)->sig = nue;
    }
    else
        nue->sig = nue;

    *pc = nue;

    return 1;
}

int desencolar(t_colaC* pc, t_infoC *d)
{
    t_nodoColaC *aux;

    if(!*pc)
        return 0;


    aux = (*pc)->sig;
    if(*pc == aux)
        *pc = NULL;
    else
        (*pc)->sig = aux->sig;

    *d = aux->info;
    free(aux);

    return 1;
}
