#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Suma dos numeros
 *
 * \param el primer numero a sumar (float x)
 * \param el segundo numero a sumar (float y)
 * \return resultado de la suma (float)
 *
 */
float sumar (float x, float y)
{
    float resultado = x+y;
    return resultado;
}







/** \brief Resta dos numeros
 *
 * \param el primer numero a restar (float x)
 * \param el segundo numero a restar (float y)
 * \return resultado de la resta (float)
 *
 */
float restar (float x, float y)
{
    float resultado = x-y;
    return resultado;
}





/** \brief Multiplica dos numeros
 *
 * \param el primer numero a multiplicar (float x)
 * \param el segundo numero a multiplicar (float y)
 * \return resultado de la multiplicacion (float)
 *
 */
float multiplicacion (float x, float y)
{
    float resultado = x*y;
    return resultado;
}





/** \brief Divide dos numeros
 *
 * \param el dividendo (float x)
 * \param el divisor (float y)
 * \return resultado de la division (float)
 *
 */
float division (float x, float y)
{
    while (y==0)
    {
        printf ("ERROR! No se puede dividir por 0, porfavor, reingrese el divisor: ");
        scanf ("%f", &y);
    }
    float resultado = x/y;
    return resultado;
}





/** \brief Pide un numero natural, si el que fue ingresado es flotante o negativo
 *
 * \return Numero entero
 *
 */
int pedirEntero()
{
    float numEntero;
    printf ("El numero A no es NATURAL, porfavor reingrese: ");
    scanf ("%f",&numEntero);
    while ((numEntero - (int)numEntero != 0) || numEntero<0)
    {
        printf ("El numero A no es NATURAL, porfavor reingrese: ");
        scanf ("%f",&numEntero);
    }
    return numEntero;
}





/** \brief Calcula el factorial de un numero
 *
 * \param el numero a factorizar (float x)
 * \return el resultado del factoreo (long long int)
 *
 */
    long long int factorial (float x)
{
    long long int acumulador = 1;
    int i = (int)x;
    for (i=x;i>0;i--)
    {
        acumulador = acumulador * i;
    }
    return acumulador;
}

