#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct
{
    int clave;
    int index;
}t_info;

typedef struct sNodo
{
    struct sNodo* izq;
    struct sNodo* der;
    t_info info;
}t_nodo, *t_arbol;

void crearArbol(t_arbol*);
int insertarEnArbol(t_arbol*,FILE*);
#endif // ARBOL_H_INCLUDED
