#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#define NOM_EMP "empleadillo.bin"
#define NOM_NOV "novedadillas.bin"
#define NOM_POST "postulantesPostaPosta.txt"

typedef struct
{
    int anio, mes, dia;

}t_fecha;

typedef struct
{
    int id;
    char ap[30];
    char nom[30];
    t_fecha fechaNac;
    float sueldo;

}t_empleado;

typedef struct
{
    int id;
    float nuevoSueldo;
}t_novedades;

typedef struct
{
    int id;
    char ap[30];
    char nom[30];
    t_fecha fechaNac;

}t_postulantes;


int crearArchivos(const char*,const char*,const char*);
void mostrarEmpleado(const char*);

#endif // ARCHIVO_H_INCLUDED
