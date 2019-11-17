#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

void crearArbol(t_arbol* pa)
{
    *pa = NULL;
}

int insertarEnArbol(t_arbol* pa ,const t_info*d,int (*cmp)(const t_info*, const t_info*))
{
    int comp;

    if(!*pa)
    {
        *pa = (t_nodo*) malloc(sizeof(t_nodo));
        (*pa)->info = *d;
        (*pa)->der = (*pa)->izq = NULL;
        return 1;
    }

    if((comp = cmp(d,&(*pa)->info))<0)
        insertarEnArbol(&(*pa)->izq,d,cmp);
    else if(comp>0)
        insertarEnArbol(&(*pa)->der,d,cmp);
    else
        return 0;

    return 1;
}
///Si no se marcan los return en la recursividad, no me marcaría el error y siempre saldría por verdadero
int buscarEnArbol(t_arbol*pa,t_info* d,int(*cmp)(const t_info*,const t_info*))
{
    int comp;

    if(!*pa)
        return 0;
    if((comp = cmp(d,&(*pa)->info)) < 0)
        return buscarEnArbol(&(*pa)->izq,d,cmp);
    else if (comp>0)
        return buscarEnArbol(&(*pa)->der,d,cmp);
    else
        *d = (*pa)->info;
    return 1;

}




void mostrarArbol(t_arbol*pa)
{
    if(!*pa)
        return;

    mostrarArbol(&(*pa)->izq);
    printf("ID %d - INDICE %d\n",(*pa)->info.id,(*pa)->info.index);
    mostrarArbol(&(*pa)->der);
}
