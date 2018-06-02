#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include "funciones.h"

int main()
{
    ePelicula Peliculas[100];
    iniciarEstado(Peliculas,100);
    cargarArchivoBin(Peliculas, 100);
    int opcion;
    char seguir = 's';
    while (seguir == 's')
    {
    system("cls");
	printf("MENU\n1. AGREGAR PELICULA\n2. BORRAR PELICULA\n3. MODIFICAR PELICULA\n4. GENERAR PAGINA WEB\n5. SALIR\n");
	opcion = GetInt ("\nElija una opcion: ",1,5,"\nOpcion Invalida, reingrese: ");

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("-- AGREGAR PELICULA --\n");
            agregarPelicula(Peliculas,10);
            guardarEnBinario(Peliculas,10);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            printf("-- BORRAR PELICULA --\n");
            borrarPelicula(Peliculas, 10);
            guardarEnBinario(Peliculas,10);
            system("PAUSE");
            break;
        case 3:
            system("cls");
            printf("-- MODIFICAR PELICULA --\n");
            modificarPelicula(Peliculas, 10);
            guardarEnBinario(Peliculas, 10);
            system("PAUSE");
            break;
        case 4:
            system("cls");
            generarPagWeb(Peliculas, 10);
            system("PAUSE");
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
