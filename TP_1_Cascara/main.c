#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float a=0;
    float b=0;
    int entero=0;
    int ingreso1=0;
    int ingreso2=0;

    while(seguir=='s')
    {
        if (ingreso1){
                printf("1- Ingresar 1er operando (A=%.2f)\n", a);
        }else {
            printf("1- Ingresar 1er operando (A=X)\n");
        }
        if (ingreso2){
                printf("2- Ingresar 2do operando (B=%.2f)\n", b);
        }else {
            printf("2- Ingresar 2do operando (B=Y)\n");
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                scanf("%f",&a);
                ingreso1=1;
                break;
            case 2:
                scanf("%f",&b);
                ingreso2=1;
                break;
            case 3:
                printf("El resultado de la suma es: %.2f.\n", sumar(a,b));
                break;
            case 4:
                printf("El resultado de la resta es: %.2f.\n", restar(a,b));
                break;
            case 5:
                if(b==0){
                    printf("Error, no se puede dividir por cero.\n");
                }else{
                    printf("El resultado de la division es: %.2f.\n", dividir(a,b));
                }
                break;
            case 6:
                printf("El resultado de la multiplicacion es: %.2f.\n", multiplicar(a,b));
                break;
            case 7:
                entero = a;
                if(a<0 || a-entero>0){
                    printf("Error, no existe el factorial de numeros negativos o fracciones.\n");
                }else{
                    printf("El resultado del factorial es: %llu.\n", calcularFactorial(a));
                }
                break;
            case 8:
                printf("El resultado de la suma es: %.2f.\n", sumar(a,b));
                printf("El resultado de la resta es: %.2f.\n", restar(a,b));
                if(b==0){
                    printf("Error, no se puede dividir por cero.\n");
                }else{
                    printf("El resultado de la division es: %.2f.\n", dividir(a,b));
                }
                printf("El resultado de la multiplicacion es: %.2f.\n", multiplicar(a,b));
                entero = a;
                if(a<0 || a-entero>0){
                    printf("Error, no existe el factorial de numeros negativos o fracciones.\n");
                }else{
                    printf("El resultado del factorial es: %.2f.\n", calcularFactorial(a));
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
}
return 0;
}
