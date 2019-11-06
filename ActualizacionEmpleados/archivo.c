#ifndef ARCHIVO_C_INCLUDED
#define ARCHIVO_C_INCLUDED

int crearArchivos(const char*nombreEmp,const char*nombreNov,const char*nombrePost)
{
    FILE * fpEmp, *fpNov, *fpPost;
    //t_empleado emp[3]= {};
    t_novedades nov;
    t_postulantes postulante;

    fpEmp = fopen(nombreEmp,"wb");
    if(!fpEmp) return 1;

    fpNov = fopen(nombreNov,"wb");
    if(!fpNov)
    {
        fclose(fpEmp);
        return 2;
    }

    fpPost = fopen(nombrePost,"wb");
    if(!fpPost)
    {
        fclose(fpEmp);
        fclose(fpNov);
        return 4;
    }



    return 0;
}


#endif // ARCHIVO_C_INCLUDED
