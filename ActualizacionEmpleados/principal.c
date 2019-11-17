#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

int cargarArbolEmpleado(t_arbol* pa,const char* nom_empleados,int (*cmp)(const t_info*, const t_info*))
{
    t_empleado emp;
    t_info info;
    int index = 0;

    FILE* fp = fopen(nom_empleados,"rb");
    if(!fp)
        return 0;

    fread(&emp,sizeof(t_empleado),1,fp);
    while(!feof(fp))
    {
        info.id = emp.id;
        info.index  = index++;

        insertarEnArbol(pa,&info,cmp);

        fread(&emp,sizeof(t_empleado),1,fp);
    }

    fclose(fp);

    return 1;
}
int cargarListaPostulantes(t_lista*p,const char* arch_post,int(*cmp)(const t_info*,const t_info*))
{
    char aux[68];
    t_postulantes post;

    FILE*fp = fopen(arch_post,"rt");
    if(!fp)
        return 0;

    while(fgets(aux,sizeof(t_postulantes),fp))
    {
        parsear(aux,&post);
        if(!ponerEnLista(p,&post,cmp))
            return 0;
    }

    fclose(fp);

    return 1;
}

int actualizarSueldosXNovedades(t_arbol* pa,const char* arch_nov,const char* arch_emp,t_colaC* cola, int (*cmp)(const t_info*,const t_info*))
{
    t_novedades nov;
    t_info info;
    t_infoC infoCola;

    FILE* fp = fopen(arch_nov,"rb");
    if(!fp)
        return ERROR_ARCHIVO;

    fread(&nov,sizeof(t_novedades),1,fp);
    while(!feof(fp))
    {
       info.id = nov.id;

        if(buscarEnArbol(pa,&info,cmp))
        {
          if(!actualizarEmpleado(arch_emp,&info,&nov))
                return ERROR_ACTUALIZAR;
        }
        else
        {
            infoCola.id = info.id;
            infoCola.sueldo = nov.nuevoSueldo;

            if(!ponerEnCola(cola,&infoCola))
                return SIN_MEMORIA;
        }


        fread(&nov,sizeof(t_novedades),1,fp);
    }

    fclose(fp);

    return 0;
}

int actualizarSueldosXPostulantes(const char* arch_emp, t_colaC* pc, t_lista* pl,int *pe,int (*cmp)(const t_info*,const t_info*))
{
    t_info info;
    t_postulantes post;
    t_infoC infoCola;
    t_empleado emp;
    int errores= 0;

    FILE* fp = fopen(arch_emp,"ab");



    fseek(fp,sizeof(t_empleado),SEEK_END);

    while(desencolar(pc,&infoCola))
    {
        info.id = infoCola.id;

        if(buscarEnLista(pl,&info,&post,cmp))
        {
            emp.id = post.id;
            strcpy(emp.ap, post.ap);
            strcpy(emp.nom, post.nom);
            emp.fechaNac = post.fechaNac;

            emp.sueldo = infoCola.sueldo;

            fwrite(&emp,sizeof(t_empleado),1,fp);
        }
        else
            errores++;
    }

    *pe = errores;

    fclose(fp);

    return 1;


}
int comp(t_info* d1, t_info* d2)
{
    return d1->id - d2->id;
}
