#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"

eMovie* nuevoArray(int tam){
    eMovie* array;
    if(tam>0){
        array=(eMovie*) malloc(tam*sizeof(eMovie));
    }
    if (array==NULL){
        printf("Error al pedir memoria.");
        system("pause");
        exit(1);
    }
    return array;
}

void inicializarMovies(eMovie*lista,int desde,int tam){
    for(int i=desde; i<tam;i++){
        lista[i].puntaje=0;
    }
}

int validoArchivos(FILE* archivoBinario,FILE* archivoHtml){
    int resultado=0;
    if(archivoBinario==NULL){
        archivoBinario= fopen("archivoBinario.dat","wb+");
        fclose(archivoBinario);
        resultado=1;
    }
    if(archivoHtml==NULL){
        archivoHtml= fopen("archivoHtml.html","w+");
        fclose(archivoHtml);
        resultado=1;
    }
    if(archivoBinario==NULL || archivoHtml==NULL){
        printf("Error al abrir archivos.");
        system("pause");
        exit(1);
    }
    return resultado;
}

void archivoBinaroAlArray(eMovie* lista, int* tam){
    int pos=0;
    int cant;

    FILE* archivoBinario;

    archivoBinario = fopen("archivoBinario.dat","rb");
    rewind(archivoBinario);

    if(archivoBinario!=NULL){
        while(!feof(archivoBinario)){
            cant=fread((lista+pos), sizeof(eMovie), 1, archivoBinario);
            pos++;
            if (cant != 1){
                    if (feof(archivoBinario))
                    {
                        break;
                    }
                    else{
                        printf("Error al leer el archivo.\n");
                        break;
                    }
            }
            if(pos==tam){
                eMovie* aux;
                *tam=*tam+5;
                aux=(eMovie*) realloc(lista, sizeof(eMovie)*(*tam));
                if (aux!= NULL){
                    lista= aux;
                }
            }
            inicializarMovies(lista,pos,tam);
        }
        fclose(archivoBinario);
    }

}

void agregarPelicula(FILE* archivoBinario,eMovie* lista,int* tam){
    system("cls");
    printf("********AGREGAR PELICULA********\n");
    //abro el archivo
    archivoBinario= fopen("archivoBinario.dat","rb+");
    eMovie peli;

    printf("\nIngrese el titulo: ");
    fflush(stdin);
    gets(peli.titulo);

    printf("\nIngrese el genero: ");
    fflush(stdin);
    gets(peli.genero);

    printf("\nIngrese la descripcion:");
    fflush(stdin);
    gets(peli.descripcion);

    printf("\nIngrese el puntaje: ");
    fflush(stdin);
    scanf("%d",&peli.puntaje);

    printf("\nIngrese la duracion en minutos: ");
    fflush(stdin);
    scanf("%d",&peli.duracion);

    printf("\nIngrese el link de la imagen de la pelicula: ");
    fflush(stdin);
    gets(peli.linkImagen);

    fseek(archivoBinario, 0L, SEEK_END);
    fwrite(&peli, sizeof(eMovie), 1, archivoBinario);
    fclose(archivoBinario);
    //actualizo el array con el archivo binario
    archivoBinaroAlArray(lista,tam);

    printf("Pelicula ingresada!\n");
    system("pause");
}
void mostrarPeliculas(eMovie* lista,int* tam){
    archivoBinaroAlArray(lista,tam);
    for(int i=0; i<tam;i++){
        if(lista[i].puntaje!=0){
            printf("Titulo: ");
            printf("%s \n",lista[i].titulo);
            printf("Genero: ");
            printf("%s \n",lista[i].genero);
            printf("Descripcion: ");
            printf("%s \n",lista[i].descripcion);
            printf("Puntaje: ");
            printf("%d \n",lista[i].puntaje);
            printf("Minutos: ");
            printf("%d \n",lista[i].duracion);
            printf("Link: ");
            printf("%s \n\n",lista[i].linkImagen);
        }
    }
}
int borrarPelicula(eMovie* lista,int* tam){
    archivoBinaroAlArray(lista,tam);
    char tituloAux[20];

    system("cls");
    printf("********BORRAR PELICULA********\n\n");
    //abro el archivo
    //FILE* archivoBinario;
    //archivoBinario= fopen("archivoBinario.dat","rb");

    printf("Ingrese el titulo de la pelicula a borrar: ");
    fflush(stdin);
    gets(tituloAux);

    for(int i=0; i<tam;i++){
        if(lista[i].puntaje!=0){
            if(strcmpi(tituloAux,lista[i].titulo)==0){
                lista[i].puntaje=0;
                break;
            }
        }
    }
    arrayAlArchivoBinario(lista,tam);
    system("pause");
}
void arrayAlArchivoBinario(eMovie* lista, int* tam){
    FILE* archivoBinario;
    archivoBinario= fopen("archivoBinario.dat","wb");
    rewind(archivoBinario);
    eMovie peli;
    int cant;

    for(int i=0; i<tam;i++){
        if(lista[i].puntaje!=0){
            strcpy(peli.descripcion,lista[i].descripcion);
            peli.duracion=lista[i].duracion;
            strcpy(peli.genero,lista[i].genero);
            strcpy(peli.linkImagen,lista[i].linkImagen);
            peli.puntaje=lista[i].puntaje;
            strcpy(peli.titulo,lista[i].titulo);

            cant=fwrite(&peli, sizeof(eMovie), 1, archivoBinario);
            if (cant != 1){
                printf("Error al escribir el archivo.\n\n");
            }
        }
    }
    fclose(archivoBinario);
}
void generarPagina(eMovie* lista, int* tam){
    archivoBinaroAlArray(lista,tam);
    FILE* archivoHtml;
    archivoHtml = fopen("archivoHtml.html","w");
    rewind(archivoHtml);

    char texto1[]="<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'> <title>Lista peliculas</title>  <link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>";
    char texto2[]="<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
    char texto3[]="'alt=''></a><h3><a href='#'>";
    char texto4[]="</a></h3><ul><li>Genero:";
    char texto5[]="</li><li>Puntaje:";
    char texto6[]="</li><li>Duracion:";
    char texto7[]="</li></ul><p>";
    char texto8[]="</p></article>";
    char texto9[]="</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>";

    fprintf(archivoHtml, "%s\n", texto1);
    for (int i=0; i<tam; i++){
        if(lista[i].puntaje!=0){
            fprintf(archivoHtml, "%s", texto2);
            fprintf(archivoHtml,"%s",lista[i].linkImagen);
            fprintf(archivoHtml, "%s", texto3);
            fprintf(archivoHtml,"%s",lista[i].titulo);
            fprintf(archivoHtml, "%s", texto4);
            fprintf(archivoHtml,"%s",lista[i].genero);
            fprintf(archivoHtml, "%s", texto5);
            fprintf(archivoHtml,"%d",lista[i].puntaje);
            fprintf(archivoHtml, "%s", texto6);
            fprintf(archivoHtml,"%d",lista[i].duracion);
            fprintf(archivoHtml, "%s", texto7);
            fprintf(archivoHtml,"%s",lista[i].descripcion);
            fprintf(archivoHtml, "%s\n", texto8);
        }
    }
    fprintf(archivoHtml, "%s", texto9);
    fclose(archivoHtml);
    printf("Pagina Web creada!\n");
    system("pause");
}
int modificarPelicula(eMovie* lista,int* tam){
    archivoBinaroAlArray(lista,tam);
    int flag=0;
    char seguir='s';
    eMovie peli;
    char tituloAux[20];

    system("cls");
    printf("********MODIFICAR PELICULA********\n\n");

    mostrarPeliculas(lista,tam);
    printf("Ingrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(tituloAux);

    for(int i=0; i<tam;i++){
        if(lista[i].puntaje!=0){
            if(strcmpi(tituloAux,lista[i].titulo)==0){
                int opcion;
                flag =1;
                printf("Pelicula encontrada!\n");
                peli=lista[i];
                system("pause");
                while(seguir=='s'){
                    system("cls");
                    printf("********SELECCIONE EL CAMPO A MODIFICAR********\n\n");
                    printf("1- Titulo\n");
                    printf("2- Genero\n");
                    printf("3- Descripcion\n");
                    printf("4- Puntaje\n");
                    printf("5- Duracion\n");
                    printf("6- Link de la imagen\n");
                    printf("7- Guardar cambios\n");

                    scanf("%d",&opcion);

                    switch(opcion){
                        case 1:
                            printf("\nIngrese el titulo nuevo: ");
                            fflush(stdin);
                            gets(peli.titulo);
                            break;
                        case 2:
                            printf("\nIngrese el genero nuevo: ");
                            fflush(stdin);
                            gets(peli.genero);
                            break;
                        case 3:
                            printf("\nIngrese la descripcion nueva:");
                            fflush(stdin);
                            gets(peli.descripcion);
                           break;
                        case 4:
                            printf("\nIngrese el puntaje nuevo: ");
                            fflush(stdin);
                            scanf("%d",&peli.puntaje);
                            break;
                        case 5:
                            printf("\nIngrese la duracion nueva en minutos: ");
                            fflush(stdin);
                            scanf("%d",&peli.duracion);
                            break;
                        case 6:
                            printf("\nIngrese el link nuevo para la imagen de la pelicula: ");
                            fflush(stdin);
                            gets(peli.linkImagen);
                            break;
                        case 7:
                            seguir = 'n';
                            break;
                    }
                }
            lista[i]=peli;
            break;
            }
        }
    }

    if (flag==0){
        printf("Esa pelicula no existe.\n");
        system("pause");
    }else if(flag==1){
        arrayAlArchivoBinario(lista,tam);
        printf("Los cambios se realizaron con exito!\n");
        system("pause");
    }
}
