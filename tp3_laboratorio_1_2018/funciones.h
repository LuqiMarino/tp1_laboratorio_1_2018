#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    char titulo[50];
    char genero[50];
    int duracion, puntaje, id, estado;
    char descripcion[500];
    char link[500];
}ePelicula;

void iniciarEstado(ePelicula*, int);
void cargarArchivoBin(ePelicula*, int);
void agregarPelicula(ePelicula*, int);
int buscarEspacio(ePelicula*, int);
void guardarDatos(ePelicula*, int, char[50], char[50], int, int, int, char[500], char[500]);
void guardarEnBinario(ePelicula*, int);
void borrarPelicula(ePelicula*, int);
void modificarPelicula(ePelicula*, int);
int noRepetirID (ePelicula*, int, int);
void generarPagWeb(ePelicula*, int);
void listado(ePelicula*, int);

#endif // FUNCIONES_H_INCLUDED
