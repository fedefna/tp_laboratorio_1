#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array. Si no hay indice libre devuelve -1.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible o un -1 si no hay disponible.
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 * Recibe la lista y la posicion de la lista donde agregar la nueva persona. Agrega una persona si no existe el mismo documento cargado y a la vez esta activo.
 * @param una lita del tipo ePersona
 * @param el tamaño de la lista
 * @return Mensaje confimando el ingreso de la persona.
 */
void agregarPersona(EPersona lista[], int pos, int tam);

/**
 * Inicializa todos los estados en 1(1=libre y 0=ocupado).
 * @param una lita del tipo ePersona
 * @param el tamaño de la lista
 * @return No devuelve nada.
 */
void inicializarEstados(EPersona lista[], int tam);

/**
 * Busca una persona por dni y la borra.
 * @param una lita del tipo ePersona
 * @param el tamaño de la lista
 * @return No devuelve nada. Imprime un mensaje de exito o error.
 */
void borrarPersona(EPersona lista[],int tam);

/**
 * Ordena la lista que recibe por nombre.
 * @param una lita del tipo ePersona
 * @param el tamaño de la lista
 * @return No devuelve nada. Cambia el orden del vector.
 */
void ordenarPorNombre(EPersona lista[],int tam);

/**
 * Busca una persona por dni y la borra.
 * @param una lita del tipo ePersona
 * @param el tamaño de la lista
 * @return No devuelve nada. Imprime un mensaje de exito o error.
 */
void imprimirLista(EPersona lista[],int tam);

/**
 * Busca una persona por dni y la borra.
 * @param una lita del tipo ePersona
 * @param el tamaño de la lista
 * @return No devuelve nada. Imprime un mensaje de exito o error.
 */
void mostrarGrafico(EPersona lista[],int tam);
#endif // FUNCIONES_H_INCLUDED
