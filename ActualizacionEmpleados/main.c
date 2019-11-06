#include <stdio.h>
#include <stdlib.h>
#include "principal.h"
#include "archivo.h"
#include "arbol.h"
#include "lista.h"

int main()
{
    t_arbol pa;
    t_lista lista;
    int (*cmp)(t_infoArbol*,t_infoArbol*);

    if(crearArchivos(NOM_EMP,NOM_NOV,NOM_POST))
        return 1;

    crearArbol(&pa);
    crearLista(&lista);

    cargarArbolEmpleado(&pa,NOM_EMP);
    actualizarSueldosXNovedades(&pa,NOM_NOV,&lista,cmp);
    actualizarSueldosXPostulantes(&pa,NOM_POST,&lista,cmp);
    mostrarEmpleado(NOM_EMP);


    return 0;
}
