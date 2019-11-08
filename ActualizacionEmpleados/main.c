#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

int main()
{
    t_arbol pa;
    t_lista lista;
    t_colaC colaC;
    int errores;
    int (*cmp)(t_info*,t_info*);

    if(crearArchivos(NOM_EMP,NOM_NOV,NOM_POST))
        return 1;

    crearArbol(&pa);
    crearLista(&lista);
    //crearColaC(&colaC);

    cargarArbolEmpleado(&pa,NOM_EMP,cmp);
    cargarListaPostulantes(&lista,NOM_POST);

    actualizarSueldosXNovedades(&pa,NOM_NOV,&lista,cmp);

    actualizarSueldosXPostulantes(&pa,&lista,&errores,cmp);

    mostrarEmpleadosYCantErrores(NOM_EMP,errores);


    return 0;
}
