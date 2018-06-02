#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include "funciones.h"
/** \brief Inicializa el estado a 0 del array
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return void
 *
 */

void iniciarEstado(ePelicula* pelis, int tam)
{
    int i;
    if (pelis!=NULL && tam>0)
    {
        for (i=0;i<tam;i++)
        {
            pelis[i].estado = 0;
        }
    }
}

/** \brief La primera vez, crea un archivo binario, luego sirve para cargarlo
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return void
 *
 */

void cargarArchivoBin(ePelicula* pelis, int tam)
{
    FILE* pFile;
    pFile = fopen("bin.dat","rb");
      if(pFile==NULL)
      {
          pFile=fopen("bin.dat","wb");
          if(pFile==NULL)
          {
              printf("No se pudo abrir el archivo");
          }
      }
      fread(pelis,sizeof(ePelicula),tam,pFile);
      fclose(pFile);
}

/** \brief Agrega una pelicula al array
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return void
 *
 */

void agregarPelicula(ePelicula* pelis, int tam)
{
    int AuxDuracion, AuxPuntaje, AuxId, VerifId;
    char AuxTitulo[50], AuxDescripcion[500], AuxGenero[50], AuxLink[500];

     printf("\nIngrese el titulo: ");
     fflush(stdin);
     gets(AuxTitulo);
     while(strlen(AuxTitulo)>50)
     {
         printf("\nTitulo muy largo, reingrese: ");
         fflush(stdin);
         gets(AuxTitulo);
     }
     printf("\nIngrese el genero: ");
     fflush(stdin);
     gets(AuxGenero);
     while(strlen(AuxGenero)>50 || StringSoloLetras(AuxGenero) == 0)
     {
         printf("\nGenero muy largo o con numeros, reingrese: ");
         fflush(stdin);
         gets(AuxGenero);
     }
     AuxId = GetInt ("\nIngrese el ID (1-100): ",1,100,"\nID Invalido, reingrese: ");
     VerifId = noRepetirID(pelis, tam, AuxId);
     while (VerifId != -1)
     {
         AuxId = GetInt ("\nEl ID ya esta ocupado, reingrese: (1-100): ",1,100,"\nID Invalido, reingrese: ");
         VerifId = noRepetirID(pelis, tam, AuxId);
     }
     AuxDuracion = GetInt ("\nIngrese la duracion (1-180): ",1,180,"\nDuracion invalida, reingrese: ");
     AuxPuntaje = GetInt ("\nIngrese puntaje (1-100): ",1,100,"\nPuntaje invalido, reingrese: ");

     printf("\nIngrese el link: ");
     fflush(stdin);
     gets(AuxLink);
     while(strlen(AuxLink)>500)
     {
         printf("\nLink muy largo, reingrese: ");
         fflush(stdin);
         gets(AuxLink);
     }

     printf("\nIngrese la descripcion: ");
     fflush(stdin);
     gets(AuxDescripcion);
     while(strlen(AuxDescripcion)>500)
     {
         printf("\nDescripcion muy larga, reingrese: ");
         fflush(stdin);
         gets(AuxDescripcion);
     }

    guardarDatos(pelis, tam, AuxTitulo, AuxGenero, AuxPuntaje, AuxDuracion, AuxId, AuxLink, AuxDescripcion);
}

/** \brief busca la primer posicion donde el estado sea 0
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return si encuentra lugar, devuelve la primer posicon encontrada, en su defecto, devuelve -1
 *
 */

int buscarEspacio(ePelicula* pelis, int tam)
{
    int i, posicion;
    if (pelis!=NULL && tam>0)
    {
        for (i=0;i<tam;i++)
        {
            if (pelis[i].estado == 0)
            {
                posicion = i;
                break;
            }
            else
            {
                posicion = -1;
            }
        }
    }
    return posicion;
}
/** \brief Guarda los datos ingresados en agregarPelicula
 *
 * \param pelis puntero al array y todos los campos de la estructura ePelicula
 * \param tam longitud del array
 * \return void
 *
 */

void guardarDatos(ePelicula* pelis, int tam, char titulo[50], char genero[50], int puntaje, int duracion, int id, char link[500], char descripcion[500])
{
    int posicion;
    if (pelis!=NULL && tam>0)
    {
        posicion = buscarEspacio(pelis, tam);
        if (posicion==-1)
        {
            printf ("\nNo hay mas espacio");
            system("pause");
        }
        else
        {
            pelis[posicion].estado = 1;
            pelis[posicion].id = id;
            strcpy(pelis[posicion].titulo,titulo);
            strcpy(pelis[posicion].genero,genero);
            pelis[posicion].duracion=duracion;
            strcpy(pelis[posicion].descripcion,descripcion);
            pelis[posicion].puntaje=puntaje;
            strcpy(pelis[posicion].link,link);
        }
    }
}
/** \brief Guarda todos los datos en el archivo binario
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return void
 *
 */

void guardarEnBinario(ePelicula* pelis,int tam)
{
    FILE* pFile;
    pFile=fopen("bin.dat","wb");
    if(pFile==NULL)
    {
        printf("Error al abrir el archivo binario\n");
        exit(1);
    }
    fwrite(pelis,sizeof(ePelicula),tam,pFile);
    printf("\nDatos guardados correctamente en el archivo binario!\n\n");
    fclose(pFile);
}
/** \brief Elimina una pelicula del array, cambiando su estado a 0
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return void
 *
 */

void borrarPelicula(ePelicula* pelis, int tam)
{
        int i, AuxId, flag=0;
        listado(pelis,tam);
        AuxId = GetInt ("\nIngrese el ID de la pelicula a borrar: ",1,999999,"\nNo es un numero entero, reingrese: ");
        for(i=0;i<tam;i++)
        {
            if (AuxId == pelis[i].id)
            {
                flag = 1;
                pelis[i].estado = 0;
                printf ("\nPelicula: ''%s'' eliminada exitosamente",pelis[i].titulo);
            }
        }
        if (flag==0)
        {
            printf("\nID no encontrado!");
        }
}


/** \brief Modifica cualquier campo de una pelicula
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return void
 *
 */
void modificarPelicula(ePelicula* pelis, int tam)
{
        int i, AuxDuracion, AuxPuntaje, AuxId, AuxId2, flag = 0;
        char AuxTitulo[50], AuxDescripcion[500], AuxGenero[50], AuxLink[500], opcion;
        char rta = 's';
        listado(pelis,tam);
        AuxId2 = GetInt ("\n\nIngrese el ID de la pelicula a modificar: ",1,9999999,"\nNo es un numero entero, reingrese: ");
        system("cls");
        while (rta == 's')
    {
        for (i=0;i<tam;i++)
        {
            if (AuxId2 == pelis[i].id)
            {
                flag = 1;
                printf ("Pelicula a modificar: %s",pelis[i].titulo);
                printf ("\n\n1. ID\n2. TITULO\n3. GENERO\n4. PUNTAJE\n5. DESCRIPCION\n6. LINK\n7. DURACION\n8. SALIR");
                printf ("\n\nIngrese una opcion: ");
                fflush(stdin);
                opcion = getche();

                switch(opcion)
                {
                case '1':
                    system("cls");
                    printf("ID Actual: %d",pelis[i].id);
                    AuxId = GetInt ("\nIngrese nuevo ID (1-100): ",1,100,"\nID Invalido, reingrese: ");
                    for (i=0;i<tam;i++)
                    {
                        while (pelis[i].estado == 1 && pelis[i].id == AuxId)
                        {
                            AuxId = GetInt ("\nEse ID ya esta ocupado, ingrese otro: ",1,100,"\nID invalido, reingrese: ");
                        }
                    }
                    pelis[i].id = AuxId;
                    printf("\nID MODIFICADO!!\n");
                    system("PAUSE");
                    system("cls");
                    printf ("Desea modificar otro dato? (s/n): ");
                    fflush(stdin);
                    rta = getche();
                    printf("\n");
                    break;
                case '2':
                    system("cls");
                    printf("TITULO ACTUAL: %s",pelis[i].titulo);
                    printf("\nIngrese nuevo titulo: ");
                    fflush(stdin);
                    gets(AuxTitulo);
                    strcpy(pelis[i].titulo, AuxTitulo);
                    printf("\n TITULO MODIFICADO!!\n");
                    system("PAUSE");
                    system("cls");
                    printf ("Desea modificar otro dato? (s/n): ");
                    fflush(stdin);
                    rta = getche();
                    printf("\n");
                    break;
                case '3':
                    system("cls");
                    printf("GENERO ACTUAL: %s",pelis[i].genero);
                    printf("\nIngrese nuevo genero: ");
                    fflush(stdin);
                    gets(AuxGenero);
                    while (strlen(AuxGenero)>50 || StringSoloLetras(AuxGenero)==0)
                    {
                        printf("\nGenero muy largo o con numeros, reingrese: ");
                        fflush(stdin);
                        gets(AuxGenero);
                    }
                    strcpy(pelis[i].genero, AuxGenero);
                    printf("\n GENERO MODIFICADO!!\n");
                    system("PAUSE");
                    system("cls");
                    printf ("Desea modificar otro dato? (s/n): ");
                    fflush(stdin);
                    rta = getche();
                    printf("\n");
                    break;
                case '4':
                    system("cls");
                    printf("Puntaje Actual: %d",pelis[i].puntaje);
                    AuxPuntaje = GetInt ("\nIngrese nuevo Puntaje (1-100): ",1,100,"\nPuntaje Invalido, reingrese: ");
                    pelis[i].puntaje = AuxPuntaje;
                    printf("\n PUNTAJE MODIFICADO!!\n");
                    system("PAUSE");
                    system("cls");
                    printf ("Desea modificar otro dato? (s/n): ");
                    fflush(stdin);
                    rta = getche();
                    printf("\n");
                    break;
                case '5':
                    system("cls");
                    printf("DESCRIPCION ACTUAL: %s",pelis[i].descripcion);
                    printf("\nIngrese nueva descripcion: ");
                    fflush(stdin);
                    gets(AuxDescripcion);
                    strcpy(pelis[i].descripcion, AuxDescripcion);
                    printf("\n DESCRIPCION MODIFICADA!!\n");
                    system("PAUSE");
                    system("cls");
                    printf ("Desea modificar otro dato? (s/n): ");
                    fflush(stdin);
                    rta = getche();
                    printf("\n");
                    break;
                case '6':
                    system("cls");
                    printf("LINK ACTUAL: %s",pelis[i].link);
                    printf("\nIngrese nuevo link: ");
                    fflush(stdin);
                    gets(AuxLink);
                    strcpy(pelis[i].link, AuxLink);
                    printf("\n LINK MODIFICADO!!\n");
                    system("PAUSE");
                    system("cls");
                    printf ("Desea modificar otro dato? (s/n): ");
                    fflush(stdin);
                    rta = getche();
                    printf("\n");
                    break;
                case '7':
                    system("cls");
                    printf("Duracion Actual: %d",pelis[i].duracion);
                    AuxDuracion = GetInt ("\nIngrese nueva Duracion (1-180): ",1,180,"\nDuracion invalida, reingrese: ");
                    pelis[i].duracion = AuxDuracion;
                    printf("\n DURACION MODIFICADO!!\n");
                    system("PAUSE");
                    system("cls");
                    printf ("Desea modificar otro dato? (s/n): ");
                    fflush(stdin);
                    rta = getche();
                    printf("\n");
                    break;
                case '8':
                    rta = 'n';
                    break;
                default:
                    printf ("\nOpcion Erronea!\n");
                    system("PAUSE");
                    system("cls");
                }
            }
        }
        if (flag == 0)
        {
            printf("\nID no encontrado!");
        }
    }
}

/** \brief Verifica que cuando se ingresa el ID de una pelicula, no haya sido ingresado anteriormente
 *
 * \param pelis puntero al array
 * \param tam longitud del array
  * \param id ingresado
 * \return void
 *
 */

int noRepetirID (ePelicula* pelis, int tam, int id)
{
    int retorno=-1, i;
    if (pelis!=NULL && tam >0)
    {
        for (i=0;i<tam;i++)
        {
            if(pelis[i].id == id && pelis[i].estado == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Muestra el listado de todas las peliculas que tengan estado = 1
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return void
 *
 */

void listado(ePelicula* pelis, int tam)
{
    int i;
     if (pelis!=NULL && tam>0)
    {
        printf("\n\nID  TITULO \n");
        for(i=0;i<tam;i++)
        {
            if (pelis[i].estado == 1)
            {
                printf("\n%d   %s",pelis[i].id,pelis[i].titulo);
            }
        }
    }
}
/** \brief Crea un archivo html y guarda datos para las peliculas con estado = 1
 *
 * \param pelis puntero al array
 * \param tam longitud del array
 * \return void
 *
 */

void generarPagWeb(ePelicula* pelis,int tam)
{
    int i;
    FILE* pFile;
    pFile=fopen("web.html","w");
    if(pFile==NULL)
    {
        printf("\nNo se pudo abrir el archivo!!");
        exit(1);
    }
    for(i=0;i<tam;i++)
    {
        if(pelis[i].estado==1)
        {
            fprintf(pFile,"<article class='col-md-4 article-intro'> <a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>",pelis[i].link);
            fprintf(pFile,"</a><h3><a href='#'> %s</a></h3><ul>",pelis[i].titulo);
            fprintf(pFile,"<li>ID: %d</li><li>Genero: %s</li><li>Puntaje: %d/100</li><li>Duracion: %d min</li></ul>",pelis[i].id,pelis[i].genero,pelis[i].puntaje,pelis[i].duracion);
            fprintf(pFile,"<p>Descripcion: %s</p></article>",pelis[i].descripcion);
        }
    }
    fclose(pFile);
    printf("Archivo creado!!\n");
}

//*********************************** I N P U T S ******************************************
//*********************************** I N P U T S ******************************************
//*********************************** I N P U T S ******************************************

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
            if (isalpha(str[i])==0 && str[i] != ' ')
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
