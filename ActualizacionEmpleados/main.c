#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
///ACTUALIZACIÓN DE LOS SUELDOS DEL ARCHIVO EMPLEADOS, POR MEDIO DE NOVEDADES.
///LOS ID QUE ESTÁN EN NOVEDADES Y NO EN EMPLEADOS SE LEEN EN POSTULANTES Y SE AGREGAN AL ARCHIVO EMPLEADOS
int main()
{
    t_arbol pa;
    t_lista lista;
    t_colaC colaC;
    t_info info;
    int errores;


    if(crearArchivos(NOM_EMP,NOM_NOV,NOM_POST))
        return 1;

    crearArbol(&pa);
    crearLista(&lista);
    crearColaC(&colaC);

    cargarArbolEmpleado(&pa,NOM_EMP,comp);
    cargarListaPostulantes(&lista,NOM_POST,comp);

    printf("Arbol 1\n");
    mostrarArbol(&pa);

    actualizarSueldosXNovedades(&pa,NOM_NOV,NOM_EMP,&colaC,comp);
    printf("Arbol 2\n");
    mostrarArbol(&pa);

    t_empleado emp;

    FILE*fp = fopen(NOM_EMP,"rb");

    printf("\nEMPLEADOS\n");
    fread(&emp,sizeof(t_empleado),1,fp);
    while(!feof(fp))
    {
        printf("id = %d, sueldo = %f\n", emp.id, emp.sueldo);
        fread(&emp,sizeof(t_empleado),1,fp);

    }
    fclose(fp);

   actualizarSueldosXPostulantes(NOM_EMP,&colaC,&lista,&errores,comp);
   mostrarEmpleadosYCantErrores(NOM_EMP,&errores);

    return 0;
}
