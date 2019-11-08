#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

void crearArbol(t_arbol* pa)
{
    *pa = NULL;
}

int insertarOActualizarEnArbol(t_arbol* pa ,const t_info*d,int (*cmp)(const t_info*, const t_info*))
{
    int comp;
    t_nodo* nue;

    if(*pa)
    {
        if((comp = (cmp(d,&(*pa)->info))) < 0)
            insertarOActualizarEnArbol(&(*pa)->izq,d,cmp);
        else if (comp>0)
            insertarOActualizarEnArbol(&(*pa)->der,d,cmp);

    }
    else
    {
        nue = (t_nodo*)malloc(sizeof(t_nodo));
        if(!nue)
            return 0;
        nue->info = *d;
        nue->izq = nue->der = NULL;
    }

    (*pa)->info = *d;

    return 1;
}
