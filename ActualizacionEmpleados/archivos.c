#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

int crearArchivos(const char*nombreEmp,const char*nombreNov,const char*nombrePost)
{
    FILE * fpEmp, *fpNov, *fpPost;
    int i = 2;

    t_empleado emp[3]= { {5,"martinez","carlos",{2006,07,03},27}, {3,"lopez","julian",{2001,12,01},11}, {911,"sosa","diego",{2001,02,11},40}  };
    t_novedades nov[3] = {{56,13000},{12,34},{911,30000}};
    t_postulantes postulante[2] = {{12,"apell","nom",{1998,01,02}}, {56,"martin","morales",{1997,03,17}}};

    fpEmp = fopen(nombreEmp,"wb");
    if(!fpEmp) return 1;

    fpNov = fopen(nombreNov,"wb");
    if(!fpNov)
    {
        fclose(fpEmp);
        return 2;
    }

    fpPost = fopen(nombrePost,"wt");
    if(!fpPost)
    {
        fclose(fpEmp);
        fclose(fpNov);
        return 4;
    }

    fwrite(emp,sizeof(emp),1,fpEmp);
    fwrite(nov,sizeof(nov),1,fpNov);

    for(i=0;i<2;i++)
    {
        fprintf(fpPost
                ,"%d|%s|%s|%d/%d/%d\n",postulante[i].id,postulante[i].ap,
                postulante[i].nom,postulante[i].fechaNac.anio,postulante[i].fechaNac.mes,postulante[i].fechaNac.dia);

    }


    fclose(fpEmp);
    fclose(fpNov);
    fclose(fpPost);

    return 0;
}
int actualizarEmpleado(const char* arch_emp,t_info* pInfo,t_novedades* pNov)
{
    t_empleado emp;

    FILE* fp = fopen(arch_emp,"r+");
    if(!fp)
        return ERROR_ARCHIVO;


    fseek(fp,sizeof(t_empleado)* pInfo->index,SEEK_SET);
    fread(&emp,sizeof(t_empleado),1,fp);
    emp.sueldo = pNov->nuevoSueldo;

    fseek(fp,-(sizeof(t_empleado)),SEEK_CUR);
    fwrite(&emp,sizeof(t_empleado),1,fp);

    fclose(fp);

    return 1;
}
void mostrarEmpleadosYCantErrores(const char* nom_emp,const int* errores)
{
    t_empleado emp;
    FILE*fp = fopen(nom_emp,"rb");

    if(!fp)
    {
        printf("Error archivo");
        return;
    }

    fread(&emp,sizeof(t_empleado),1,fp);

    while(!feof(fp))
    {
        printf("EMPLEADO: %d - %s - %s - %d/%d/%d - %f\n", emp.id,emp.ap,emp.nom,emp.fechaNac.dia,emp.fechaNac.mes,
                                                                                    emp.fechaNac.anio, emp.sueldo);
        fread(&emp,sizeof(t_empleado),1,fp);
    }

    fclose(fp);

    printf("Cantidad de Errores: %d",*errores);
}
void parsear(char* cad,t_postulantes* post)
{
    char* aux; //= strchr(cad,'\0');

    aux = strrchr(cad,'|');
    sscanf(aux+1,"%d/%d/%d",&post->fechaNac.anio,&post->fechaNac.mes,&post->fechaNac.dia);
    *aux = '\0';

    aux = strrchr(cad,'|');
    strcpy(post->nom,aux+1);
    *aux = '\0';

    aux = strrchr(cad,'|');
    strcpy(post->ap,aux+1);
    *aux = '\0';

    sscanf(cad,"%d",&post->id);

}
