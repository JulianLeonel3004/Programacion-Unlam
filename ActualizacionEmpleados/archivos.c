#include "archivo.h"
#include <stdio.h>
#include <stdlib.h>

int crearArchivos(const char*nombreEmp,const char*nombreNov,const char*nombrePost)
{
    FILE * fpEmp, *fpNov, *fpPost;
    int i =0;

    t_empleado emp[3]= { {5,"martinez","carlos",{2006,07,03},27}, {3,"lopez","julio",{2001,12,01},11}, {911,"torres","diego",{2001,02,11},40}  };
    t_novedades nov[2] = {{5,13000},{911,30000}};
    t_postulantes postulante = {3,"apell","nom",{1998,01,02}} ;

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


        fprintf(fpPost
                ,"%d|%s|%s|%d%d%d",postulante.id,postulante.ap,
                postulante.nom,postulante.fechaNac.anio,postulante.fechaNac.mes,postulante.fechaNac.dia);

    fclose(fpEmp);
    fclose(fpNov);
    fclose(fpPost);

    return 0;
}
void mostrarEmpleado(const char* nom_emp)
{

}
