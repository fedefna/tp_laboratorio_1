#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    char seguir='s';
    int opcion=0;
    EPersona lista[20];
    int pos;


    //Inicializo los estados del array.
    inicializarEstados(lista,20);

    while(seguir=='s'){
        system("cls");
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                pos=obtenerEspacioLibre(lista);
                if (pos!=-1){
                    agregarPersona(lista,pos,20);
                }else{
                    printf("\nNo hay lugar en la lista. Debe borrar una persona para ingresar una nueva.\n");
                    system("pause");
                }
                break;
            case 2:
                borrarPersona(lista,20);
                break;
            case 3:
                ordenarPorNombre(lista,20);
                imprimirLista(lista,20);
                break;
            case 4:
                mostrarGrafico(lista,20);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

