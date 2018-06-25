#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

int main()
{
    char seguir='s';
    int opcion=0;
    int desde=0;
    int aux;
    int* tam=10;
    eMovie* lista;
    lista=nuevoArray(tam);
    //primero intento abrir los archivos
    FILE *archivoBinario;
    FILE *archivoHtml;
    archivoBinario= fopen("archivoBinario.dat","rb+");
    archivoHtml= fopen("archivoHtml.html","r+");
    //Valio si existen sino existen los creo
    aux=validoArchivos(archivoBinario,archivoHtml);
    //Si el puntaje de la pelicula=0 entonces esl espacio esta libre
    inicializarMovies(lista,desde,tam);
    //Si aux es 0 los archivos ya existen, po lo tanto leo el bin para pasarlo al array
    if(aux==0){
        archivoBinaroAlArray(lista,tam);
    }

    while(seguir=='s')
    {
        system("cls");
        printf("********MENU PRINCIPAL********\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(archivoBinario,lista,tam);
                break;
            case 2:
                borrarPelicula(lista,tam);
                break;
            case 3:
                modificarPelicula(lista,tam);
               break;
            case 4:
                generarPagina(lista,tam);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
