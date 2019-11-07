#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
#define NOM_EMP "empleado.bin"
#define NOM_NOV "novedades.bin"
#define NOM_POST "postulantes.txt"

///ARCHIVO
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
void parsear(char*,t_postulantes*);

///T_INFO GENERAL
typedef struct
{
    int id;
    float sueldo;
}t_info;

///ARBOL

typedef struct sNodoArbol
{
    t_info info;
    struct sNodoArbol* izq;
    struct sNodoArbol* der;

}t_nodo,* t_arbol;

void crearArbol(t_arbol*);
int insertarOActualizarEnArbol(t_arbol*,const t_info*,int(*cmp)(t_info*,t_info*));

///LISTA

typedef struct sNodoLista
{
    t_info info;
    struct sNodoLista* sig;

}t_nodoLista, *t_lista;

void crearLista(t_lista*);
int ponerEnLista(t_lista*,t_info*,int (*cmp)(t_info*,t_info*));

///AUX
int comp(t_info*,t_info*);


///MAIN
int cargarArbolEmpleado(t_arbol*,const char*,int (*cmp)(t_info*,t_info*));
int actualizarSueldosXNovedades(t_arbol*,const char*,t_lista*,int (*cmp)(t_info*,t_info*));
int actualizarSueldosXPostulantes(t_arbol*,const char*,t_lista*,int (*cmp)(t_info*,t_info*));



#endif // TIPOS_H_INCLUDED
