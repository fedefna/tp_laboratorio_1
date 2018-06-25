#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
}eMovie;

void agregarPelicula(FILE* archivoBinario,eMovie* lista,int* tam);

void mostrarPeliculas(eMovie* lista,int* tam);

int borrarPelicula(eMovie* lista,int* tam);

int modificarPelicula(eMovie* lista,int* tam);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(eMovie* lista,int* tam);

eMovie* nuevoArray(int tam);

void inicializarMovies(eMovie*lista,int desde,int tam);

int validoArchivos(FILE* archivoBinario,FILE* archivoHtml);

void archivoBinaroAlArray(eMovie* lista, int* tam);

void arrayAlArchivoBinario(eMovie* lista, int* tam);



#endif // FUNCIONES_H_INCLUDED
