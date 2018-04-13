#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief suma dos numeros y devuelve el resultado
 *
 * \param A primer numero a sumar
 * \param B segundo numero a sumar
 * \return el resultado de la suma A+B
 *
 */
float sumar (float a, float b){
    return (a+b);
}

/** \brief resta dos numeros y devuelve el resultado
 *
 * \param A numero al cual se le restara B
 * \param B es el numero que se le resta a A
 * \return el resultado de la resta A-B
 *
 */
float restar (float a, float b){
    return (a-b);
}

/** \brief divide dos numeros y devuelve el resultado
 *
 * \param A es el dividendo
 * \param B es el divisor
 * \return el resultado de la division A/B
 *
 */
float dividir (float a, float b){
        return (a/b);
}
/** \brief multiplica dos numeros y devuelve el resultado
 *
 * \param A es el primer numero a multiplicar
 * \param B es el segundo numero a multiplicar
 * \return el resultado de la multiplicacion A*B
 *
 */
float multiplicar (float a, float b){
    return (a*b);
}

/** \brief calcula el factorial de un numero devuelve el resultado
 *
 * \param A es el numero a factorizar
 * \return 1 si el numero ingresado es 0 sino devuelve el factorial del numero ingresado.
 *
 */
long long calcularFactorial(int x){
    long long a =x;
    if(a==0){
            return 1;
    }else{
        return (a*calcularFactorial(a-1));
    }
}

#endif // FUNCIONES_H_INCLUDED
