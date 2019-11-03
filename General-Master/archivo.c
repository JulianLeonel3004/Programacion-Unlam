#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"

int crearArchivo(FILE* fp, char* nombreArchivo)
{
    t_persona persAux;

    t_persona personas[] = {{8,"Julian"},{5,"Cristian"},{10,"Lara"}};

    fp = fopen(nombreArchivo,"wb");
    if(!fp)
        return 0;

    fwrite(&personas,sizeof(personas),1,fp);

    return 1;

}
