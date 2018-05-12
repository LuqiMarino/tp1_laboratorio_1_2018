#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define TAM 20

void iniciarEstadoyEdad (ePersona lista[], int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        lista[i].estado = 0;
        lista[i].edad = -1;
    }
}
int buscarEspacio (ePersona lista[], int tam)
{
    int i, auxInt;
    for (i=0;i<tam;i++)
    {
        if (lista[i].estado==0)
        {
            auxInt = i;
            break;
        }
        else
        {
            auxInt = -1;
        }
    }
    return auxInt;
}
void agregarPersona (ePersona lista[], int tam)
{
    int auxInt, i;
    auxInt = buscarEspacio(lista,tam);
    if (lista[auxInt].estado!=-1)
    {
        lista[auxInt].estado = 1;

        printf ("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[auxInt].nombre);

        while (StringSoloLetras (lista[auxInt].nombre) == 0)
        {
            printf ("\nNombre invalido, reingrese: ");
            fflush(stdin);
            gets(lista[auxInt].nombre);
        }
        lista[auxInt].edad = GetInt ("Ingrese edad: ",0,130,"\nNo es un numero entero, reingrese: ");

        printf ("Ingrese dni: ");
        fflush(stdin);
        gets (lista[auxInt].dni);

        while (GetDNI(lista[auxInt].dni) == 0)
        {
            printf ("\nDni invalido, reingrese: ");
            fflush(stdin);
            gets (lista[auxInt].dni);
        }
    }
    else
    {
        printf ("No hay mas espacio");
    }
}
void mostrarLista (ePersona lista[], int tam)
{
    printf ("\nListado: \n");
    int i;
    printf ("\n Nombre      Edad     Dni");
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            printf("\n%6s         %2d%8s", lista[i].nombre,lista[i].edad,lista[i].dni);
        }
    }
    printf ("\n\n");
}

void eliminarPersona (ePersona lista[], int tam)
{
    int i;
    char rta, auxDni[15];
    printf ("Ingrese dni de la persona a eliminar: ");
    fflush(stdin);
    gets (auxDni);

    while (GetDNI(auxDni) == 0)
        {
            printf ("\nDni invalido, reingrese: ");
            fflush(stdin);
            gets (auxDni);
        }
    for (i=0;i<TAM;i++)
    {
        if (strcmp(lista[i].dni,auxDni) == 0)
        {
            rta = GetSoN("\nEsta seguro? [s|n]: ","\nRespuesta invalida, reingrese [s|n]: ");
            if (rta == 's')
            {
                printf ("\n\nPersona eliminada!");
                lista[i].estado = 0;
                break;
            }
            else
            {
                printf ("\nAccion cancelada por el usuario!");
                break;
            }
        }
        else if (i==tam-1)
        {
            printf ("\nPersona no encontrada!");
            break;
        }
    }
    printf ("\n\n");
}


void ordenarPersonas (ePersona lista[], int tam)
{
    int i, j;
    ePersona auxPersona;

    for(i=0;i<tam-1;i++)
    {
       if (lista[i].estado == 1)
       {
           for(j=i+1;j<tam;j++)
            {
                if (lista[j].estado == 1)
                {
                    if(strcmp(lista[i].nombre,lista[j].nombre) > 0)
                    {
                        auxPersona = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxPersona;
                    }
                }
            }

       }
    }
    printf ("\nListado Ordenado: \n");
}

void grafico(ePersona lista[],int tam)
{
    int i;
    printf("<18       19-35      >35");

    for(i=0; i<tam; i++)
    {

        if(lista[i].edad<=18 && lista[i].edad > 0)
            printf ("\n*");

        else if(lista[i].edad>18 && lista[i].edad<=35)
            printf ("\n            *");

        else if(lista[i].edad>35 && lista[i].edad < 150)
            printf ("\n                     *");
    }
    printf ("\n\n");
}



/** \brief Pide un numero entero, verificando que no sea flotante, que no tenga letras, caracteres y que este entre el limite del minimo y maximo
 * \param Mensaje pidiendo el numero entero
 * \param Numero minimo aceptado
 * \param Numero maximo aceptado
 * \param Mensaje de error, pide numero nuevamente
 * \return Numero entero valido
 */
 int GetInt (char mensaje[], int min, int max, char error[])
{
    float retorno = 0;
    int AuxInt, i;
    int flag = 1;
    char AuxChar[10];
    do
    {
        if (flag == 1)
            printf ("%s",mensaje);
        else
            printf ("%s",error);
        fflush(stdin);
        gets(AuxChar);
        for (i=0;i<strlen(AuxChar);i++)
        {
            if (isdigit(AuxChar[i]) || AuxChar[i] == '.')
                flag = 2;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 2)
            retorno = atof(AuxChar);
        AuxInt = (int)retorno;
    }while(retorno == 0 || retorno < min || retorno > max || retorno - AuxInt != 0);

    return retorno;
}
/** \brief Pide un numero flotante, verificando que no tenga letras, caracteres y que este entre el limite del minimo y maximo
 * \param Mensaje pidiendo el numero flotante
 * \param Numero minimo aceptado
 * \param Numero maximo aceptado
 * \param Mensaje de error, pide numero nuevamente
 * \return Numero flotante valido
 */
float GetFloat (char mensaje[], float min, float max, char error[])
{
    float retorno = 0;
    int i;
    int flag = 1;
    char AuxChar[10];
    do
    {
        if (flag == 1)
            printf ("%s",mensaje);
        else
            printf ("%s",error);
        fflush(stdin);
        gets(AuxChar);
        for (i=0;i<strlen(AuxChar);i++)
        {
            if (isdigit(AuxChar[i]) || AuxChar[i] == '.')
                flag = 2;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 2)
            retorno = atof(AuxChar);
    }while(retorno == 0 || retorno < min || retorno > max);

    return retorno;
}

/** \brief Verifica si una cadena contiene unicamente letras
 * \param Cadena a verificar
 * \return 1 si contiene solamente letras, 0 si contiene otro tipo de caracter
 */
int StringSoloLetras (char str[])
{
    int i;
    int retorno = 1;
    for (i=0;i<strlen(str);i++)
    {
            if (isalpha(str[i])==0)
            {
                retorno = 0;
                break;
            }
    }
    return retorno;
}

/** \brief Pide un DNI validando que solo se ingresen numeros y como maximo dos puntos
 * \param Cadena a validar
 * \return 1 si es un DNI valido, 0 si contiene letras o mas de 2 puntos
 */
int GetDNI (char str[])
{
    int i;
    int contpuntos = 0;
    int retorno = 0;
    for (i=0;i<strlen(str);i++)
    {
            if (isdigit(str[i]) || str[i] == '.')
            {
                retorno = 1;
                if (str[i] == '.')
                    contpuntos++;
            }
            else
            {
                retorno = 0;
                break;
            }
            if (contpuntos > 2)
            {
                retorno = 0;
                break;
            }
    }
    return retorno;
}

/** \brief Valida si la respuesta es S o N
 * \param Mensaje pidiendo la respuesta
 * \param Mensaje de error, pide la respuesta nuevamente
 * \return Char 's' o 'n'
 */
char GetSoN (char mensaje[], char error[])
{
    char AuxChar;
    printf ("%s",mensaje);
    fflush(stdin);
    AuxChar = getche();
    AuxChar = tolower (AuxChar);
    while (AuxChar != 's' && AuxChar != 'n')
    {
        printf ("%s",error);
        fflush(stdin);
        AuxChar = getche();
        AuxChar = tolower (AuxChar);
    }
    return AuxChar;
}
