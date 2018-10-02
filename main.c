#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "peliculas.h"
#include "utn.h"
#define MAX 1000

int main()
{
    char seguir = 's';
    int flag=0;
    int lugarLibre;
    int id;
    char titulo[40];
    char nacionalidad[20];
    int anio;
    char director [40];
    int opcion;

    ePelicula peliculas[MAX];
    eDirector directores[MAX];

    do
    {
        printf("-----OPCIONES-----\n\n");
        printf("1. ALTA\n");
        printf("2. MODIFICAR\n");
        printf("3. BAJA\n");
        printf("4. INFORMAR\n");
        printf("5. SALIR\n");
        printf("ELIJA UNA OPCION: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            flag=1;
            lugarLibre=buscarLibre(peliculas, MAX);
            if(lugarLibre!= -1)
            {

                getValidString("Ingrese nacionalidad: ", "No VALIDO. Ingrese nuevamente: \n", nacionalidad);
                getValidString("Ingrese titulo: ", "No valido. Ingrese nuevamente: \n", titulo);
                anio=getValidInt("Ingrese anio: ","No valido. Ingrese nuevamente \n", 0, 1000000);
                getValidString("Ingrese director: ","No valido. Ingrese nuevamente \n", director);
                id=getValidInt("Ingrese el id: ", "No valido. Ingrese nuevamente \n", 0, 1000000);
                agregarPelicula(peliculas, MAX, nacionalidad, titulo, anio, id);

            }
            else
            {
                printf("Aun no hay datos para mostrar\n");
                system("pause");
                system("cls");
            }

            break;

        case 4:
            if(flag == 0)
            {
                printf("Aun no hay datos para mostrar\n");
            }
            else
            {
                mostrarPeliculas(, len);
            }

            system("pause");
            system("cls");
            break;
        case 5:
            seguir='n';
            break;
        default :
            printf("Error. Dato no valido\n");
            system("pause");
            system("cls");
        }


    }while(seguir == 's');

    return 0;
}


