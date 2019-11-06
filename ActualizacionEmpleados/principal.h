#ifndef PRINCIPAL_H_INCLUDED
#define PRINCIPAL_H_INCLUDED
#include "arbol.h"
#include "lista.h"

int comp(t_infoArbol*,t_infoArbol*);

void cargarArbolEmpleado(t_arbol*,const char*);
void actualizarSueldosXNovedades(t_arbol*,const char*,t_lista*,int (*cmp)(t_infoArbol*,t_infoArbol*));
void actualizarSueldosXPostulantes(t_arbol*,const char*,t_lista*,int (*cmp)(t_infoArbol*,t_infoArbol*));


#endif // PRINCIPAL_H_INCLUDED
