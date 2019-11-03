#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
#include "arbol.h"
int main()
{
    FILE* fp;
    t_arbol pa;

    if(!crearArchivo(fp,NOM_ARCHIVO))
        return 1;

    fp = fopen(NOM_ARCHIVO,"rb");
    if(!fp)
        return 2;

    crearArbol(&pa);
    insertarEnArbol(&pa,fp);
    return 0;
}
