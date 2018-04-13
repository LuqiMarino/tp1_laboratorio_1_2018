#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
   float x = 0;
   float y = 0;
   int f, opcion;
   float resultado;
   long long int numFactorial;
   char seguir = 's';

   while (seguir == 's')
{
     printf ("1-Ingresar el primer operando: (A=%.2f)\n2-Ingresar el segundo operando: (B=%.2f)\n3-Calcular la suma (A+B)\n4-Calcular la resta (A-B)\n5-Calcular la division (A/B)\n6-Calcular la multiplicacion (A*B)\n7-Calcular el factorial (A!)\n8-Calcular todas las operaciones\n9-Salir\n\nOpcion: ",x,y);
     scanf ("%d", &opcion);

        switch (opcion)
        {
        case 1:
            {
                printf ("Ingrese 1er operando: ");
                scanf ("%f",&x);
                system ("cls");
                break;
            }
        case 2:
            {
                printf ("Ingrese 2do operando: ");
                scanf ("%f",&y);
                system ("cls");
                break;
            }
        case 3:
            {
           resultado = sumar (x,y);
           printf ("La suma es: %.2f\n",resultado);
           printf ("Desea realizar otra operacion? (S/N): ");
           fflush(stdin);
           seguir = getche ();
           seguir = tolower(seguir);
           system ("cls");
           break;
            }
        case 4:
            {
           resultado = restar (x,y);
           printf ("La resta es: %.3f\n", resultado);
           printf ("Desea realizar otra operacion? (S/N): ");
           fflush(stdin);
           seguir = getche ();
           seguir = tolower(seguir);
           system ("cls");
           break;
            }
        case 5:
            {
           resultado = division (x,y);
           printf ("La division es: %.3f\n", resultado);
           printf ("Desea realizar otra operacion? (S/N): ");
           fflush(stdin);
           seguir = getche ();
           seguir = tolower(seguir);
           system ("cls");
           break;
            }
        case 6:
            {
           resultado = multiplicacion (x,y);
           printf ("El producto es: %.3f\n", resultado);
           printf ("Desea realizar otra operacion? (S/N): ");
           fflush(stdin);
           seguir = getche ();
           seguir = tolower(seguir);
           system ("cls");
           break;
            }
        case 7:

            f = x;
            {
                while ((x - f != 0) || x<0)
                {
                x = pedirEntero ();
                f = x;
                }
                numFactorial = factorial (f);
                printf ("El factorial de %d es %lld\n",f,numFactorial);
            }
            printf ("Desea realizar otra operacion? (S/N): ");
            fflush(stdin);
            seguir = getche ();
            seguir = tolower(seguir);
            system ("cls");
            break;
        case 8:
            {
           resultado = sumar (x,y);
           printf ("La suma es: %.2f\n",resultado);

           resultado = restar (x,y);
           printf ("La resta es: %.2f\n", resultado);

           resultado = multiplicacion (x,y);
           printf ("El producto es: %.2f\n", resultado);

           resultado = division (x,y);
           printf ("La division es: %.2f\n", resultado);

           f = x;
            {
                while ((x - f != 0) || x<0)
                {
                x = pedirEntero ();
                f = x;
                }
                numFactorial = factorial (f);
                printf ("El factorial de %d es %lld\n",f,numFactorial);
            }
            printf ("Desea realizar otra operacion? (S/N): ");
            fflush(stdin);
            seguir = getche ();
            seguir = tolower(seguir);
            system ("cls");
            break;
            }
         case 9:
            {
            seguir = 'n';
            }
         default:
            {
            printf ("No es una opcion valida, reingrese\n");
            system("PAUSE");
            system("cls");
            break;
            }

}
}
   return 0;
}
