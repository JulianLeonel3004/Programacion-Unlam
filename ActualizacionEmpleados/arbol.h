#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct
{
    int id;
    float sueldo;
}t_infoArbol;

typedef struct sNodo
{
    t_infoArbol info;
    struct sNodo* izq;
    struct sNodo* der;

}t_nodo,* t_arbol;

void crearArbol(t_arbol*);
int insertarEnArbol(t_arbol*,const t_infoArbol*);

#endif // ARBOL_H_INCLUDED
