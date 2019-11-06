#include <stdio.h>
#include <stdlib.h>
#include "principal.h"
#include "archivo.h"

void cargarArbolEmpleado(t_arbol* pa,const char* nom_empleados)
{
    t_empleado emp;
    t_infoArbol info;

    FILE* fp = fopen(nom_empleados,"rb");
    if(!fp)
        return;

    fread(&emp,sizeof(t_empleado),1,fp);
    while(!feof(fp))
    {
        info.id = emp.id;
        info.sueldo = emp.sueldo;

        insertarEnArbol(pa,&info);
        fread(&emp,sizeof(t_empleado),1,fp);
    }
}

void actualizarSueldosXNovedades(t_arbol* pa,const char* arch_nov,t_lista* pl, int (*cmp)(t_infoArbol*,t_infoArbol*))
{

}
void actualizarSueldosXPostulantes(t_arbol* pa,const char* arch_post ,t_lista* pl,int (*cmp)(t_infoArbol*,t_infoArbol*))
{

}
