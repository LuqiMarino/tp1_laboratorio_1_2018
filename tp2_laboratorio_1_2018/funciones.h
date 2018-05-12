#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAM 20

typedef struct
{
    char nombre[50], dni[15];
    int edad, estado;
}ePersona;

void iniciarEstado(ePersona lista[], int tam);
int buscarEspacio (ePersona lista[], int tam);
void agregarPersona (ePersona lista[], int tam);
void mostrarLista (ePersona lista[], int tam);
//int buscarPersona (ePersona lista[], int DniIngresado, int);
void eliminarPersona (ePersona lista[], int tam);
//int ingresarDni (ePersona lista[], int tam);
void ordenarPersonas (ePersona lista[], int tam);
char GetSoN (char mensaje[], char error[]);
int GetDNI (char str[]);
int StringSoloLetras (char str[]);
float GetFloat (char mensaje[], float min, float max, char error[]);
int GetInt (char mensaje[], int min, int max, char error[]);
#endif // FUNCIONES_H_INCLUDED
