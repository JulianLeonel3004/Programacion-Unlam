#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#define NOM_ARCHIVO "personas.dat"
typedef struct
{
    int dni;
    char apyn[30];
}t_persona;

int crearArchivo(FILE*,char*);


#endif // ARCHIVO_H_INCLUDED
