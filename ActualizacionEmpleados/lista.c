#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

void crearLista(t_lista* p)
{
    *p = NULL;
}
int ponerEnLista(t_lista* p,t_postulantes* d,int (*cmp)(t_info*,t_info*))
{
    t_nodoLista * act,*sig,*ant,*nue;
    t_info info1, info2;
    int comp;

    nue = (t_nodoLista*)malloc(sizeof(t_nodoLista));
    if(!nue)
        return SIN_MEMORIA;

    act = sig = ant = NULL;

    if(*p)
    {
        act = *p;
        info1.id = d->id;
        info2.id = (*p)->post.id;

        while(act->sig && cmp(&info1,&info2)>0)
        {
            act = act->sig;
            info2.id = act->post.id;
        }

        while(act->ant && cmp(&info1,&info2)<0)
        {
            act = act->ant;
            info2.id = act->post.id;
        }

        if((comp = cmp(&info1,&info2)) > 0)
        {
            ant = act;
            sig = act->sig;
        }
        else if(comp<0)
        {
            sig = act;
            ant = act->ant;
        }
        else
            return DUPLICADO;

    }
    else
    {
        ant = sig = NULL;
    }

    nue->post = *d;
    nue->sig = sig;
    nue->ant = ant;

    if(ant)
        ant->sig = nue;
    if(sig)
        sig->ant = nue;

    *p = nue;

    return 1;
}
int buscarEnLista(t_lista* p,t_info* d, t_postulantes *post, int(*cmp)(t_info*,t_info*))
{
    int comp;
    t_info info;

    if(!*p)
        return 0;

    info.id = (*p)->post.id;

    if((comp=cmp(d,&info))<0)
         return buscarEnLista(&(*p)->ant,d,post,cmp);
    if(comp>0)
         return buscarEnLista(&(*p)->sig,d,post,cmp);
    *post = (*p)->post;

    return 1;
}
