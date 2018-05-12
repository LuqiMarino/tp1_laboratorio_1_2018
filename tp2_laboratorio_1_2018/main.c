#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define TAM 20

int main()
{
    ePersona lista[TAM];
    iniciarEstadoyEdad (lista,TAM);
    int opcion;
    char seguir = 's';
    while (seguir == 's')
    {
        system("cls");
        printf ("1-Agregar Persona\n2-Eliminar Persona\n3-Imprimir lista ordenada por nombre\n4-Imprimir grafico de edades\n5-Salir\n");
        opcion = GetInt ("Ingrese Opcion: ",1,5,"\nOpcion invalida, reingrese: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            agregarPersona (lista,TAM);
            mostrarLista (lista,TAM);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            eliminarPersona (lista,TAM);
            mostrarLista (lista,TAM);
            system("PAUSE");
            break;
        case 3:
            system("cls");
            ordenarPersonas (lista,TAM);
            mostrarLista (lista,TAM);
            system("PAUSE");
            break;
        case 4:
            system("cls");
            grafico (lista,TAM);
            system("PAUSE");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Error, ingrese una opcion entre 1 y 5\n");
            break;
        }
    }
    return 0;
}


