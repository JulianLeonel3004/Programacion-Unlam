#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
#define NOM_EMP "empleado.bin"
#define NOM_NOV "novedades.bin"
#define NOM_POST "postulantes.txt"

#define ERROR_ARCHIVO 1
#define ERROR_ACTUALIZAR 2
#define SIN_MEMORIA 4
#define DUPLICADO 8
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

///T_INFO ARBOL
typedef struct
{   int index;
    int id;
}t_info;
///--------------------------
int crearArchivos(const char*,const char*,const char*);
void mostrarEmpleadosYCantErrores(const char*, const int*);
int actualizarEmpleado(const char*,t_info*,t_novedades*);
void parsear(char*,t_postulantes*);



///ARBOL


typedef struct sNodoArbol
{
    t_info info;
    struct sNodoArbol* izq;
    struct sNodoArbol* der;

}t_nodo,* t_arbol;

void crearArbol(t_arbol*);
int insertarEnArbol(t_arbol*,const t_info*,int(*cmp)(const t_info*,const t_info*));
int buscarEnArbol(t_arbol*,t_info*,int(*cmp)(const t_info*,const t_info*));
void mostrarArbol(t_arbol*);

///LISTA

typedef struct sNodoLista
{
    t_postulantes post;
    struct sNodoLista* sig, *ant;

}t_nodoLista, *t_lista;

void crearLista(t_lista*);
int ponerEnLista(t_lista*,t_postulantes*,int (*cmp)(t_info*,t_info*));
int buscarEnLista(t_lista*,t_info*,t_postulantes*,int(*cmp)(t_info*,t_info*));

///COLA CIRCULAR

typedef struct
{
    int index;
    int id;
    float sueldo;
}t_infoC;

typedef struct sNodoColaC
{
    t_infoC info;
    struct sNodoColaC* sig;

}t_nodoColaC, *t_colaC;

void crearColaC(t_colaC*);
int ponerEnCola(t_colaC*, t_infoC*);
int desencolar(t_colaC*, t_infoC*);

///AUX
int comp(t_info*,t_info*);


///MAIN
int cargarArbolEmpleado(t_arbol*,const char*,int (*cmp)(const t_info*,const t_info*));
int cargarListaPostulantes(t_lista*,const char*,int (*cmp)(const t_info*,const t_info*));
int actualizarSueldosXNovedades(t_arbol*,const char*,const char*,t_colaC*,int (*cmp)(const t_info*, const t_info*));
int actualizarSueldosXPostulantes(const char*,t_colaC*,t_lista*,int*,int (*cmp)(const t_info*,const t_info*));


#endif // TIPOS_H_INCLUDED
