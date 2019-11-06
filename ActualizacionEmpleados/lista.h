#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct
{
    int id;
    float sueldo;
}t_infoLista;

typedef struct sNodoLista
{
    t_infoLista info;
    struct sNodoLista* sig;

}t_nodoLista, *t_lista;


void crearLista(t_lista*);

#endif // LISTA_H_INCLUDED
