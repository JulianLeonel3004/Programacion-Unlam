#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

int cargarArbolEmpleado(t_arbol* pa,const char* nom_empleados,int(*cmp)(t_info*, t_info*))
{
    t_empleado emp;
    t_info info;

    FILE* fp = fopen(nom_empleados,"rb");
    if(!fp)
        return 0;

    fread(&emp,sizeof(t_empleado),1,fp);
    while(!feof(fp))
    {
        info.id = emp.id;
        info.sueldo = emp.sueldo;

        insertarOActualizarEnArbol(pa,&info,cmp);
        fread(&emp,sizeof(t_empleado),1,fp);
    }

    fclose(fp);

    return 1;
}

int actualizarSueldosXNovedades(t_arbol* pa,const char* arch_nov,t_lista* pl, int (*cmp)(t_info*,t_info*))
{
    t_novedades nov;
    t_info info;
    FILE* fp = fopen(arch_nov,"rb");
    if(!fp)
        return 1;

    fread(&nov,sizeof(t_novedades),1,fp);
    while(!feof(fp))
    {
       info.id = nov.id;
       info.sueldo = nov.nuevoSueldo;

        if(!insertarOActualizarEnArbol(pa,&info,cmp))
            if(!ponerEnLista(pl,&info,cmp))
                return 2;
        fread(&nov,sizeof(t_novedades),1,fp);
    }

    fclose(fp);

    return 0;
}
int actualizarSueldosXPostulantes(t_arbol* pa,const char* arch_post ,t_lista* pl,int (*cmp)(t_info*,t_info*))
{
    char aux[68];
   // t_postulantes post;

    FILE*fp = fopen(arch_post,"rt");
    if(!fp)
        return 0;

    while(fgets(aux,sizeof(t_postulantes),fp))
    {
        ///parsear en post
        ///buscar en lista
        ///si está, cargar en arbol
        ///si NO está, enviar a cola
    }

    fclose(fp);

    return 1;
}

int id;
    char ap[30];
    char nom[30];
    t_fecha fechaNac;
