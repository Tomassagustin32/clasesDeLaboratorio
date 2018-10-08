#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaParcial.h"
#include "bibliotecaGetsYComprobaciones.h"

int main()
{
    ePelicula listaPelicula[TAM_PELICULA];
    eDirector listaDirector[TAM_DIRECTOR];
    int opcion;
    int peliculaMain;
    int directorMain;
    int agregarPeliculasMain;
    int borrarPeliculasMain;
    int flagCargada = 1;
    int modificarPeliculaMain;
    int agregarPeliculasMainDirec;
    int borrarPeliculasMainDirec;

    do
    {
        peliculaMain = inicializarPelicula(listaPelicula, TAM_PELICULA);
        directorMain = inicializarDirector(listaDirector, TAM_DIRECTOR);
        inicializarHardcodeoPeliculas(listaPelicula);
        inicializarDirectortorHardCode(listaDirector);
    }while(peliculaMain == -1 || directorMain == -1);

    do
    {
        opcion = getIntOnly("Ficha tecnica\n\n1.ALTAS PELICULAS\n2.MODIFICAR DATOS DE UNA PELICULA\n3.BAJA DE PELICULA\n4.NUEVO DIRECTOR\n5.ELIMINAR DIRECTOR\n6.LISTAR\n7.SALIR\nIngrese una opcion: ");

        switch(opcion)
        {
        case 1://alta pelicula
            agregarPeliculasMain = agregarPeliculas(listaPelicula, listaDirector);
                if(agregarPeliculasMain == 0)
                {
                    flagCargada = 1;
                    system("cls");
                    printf("\nSe cargo correctamente.\n");
                }
            break;
        case 2://modif
                if(flagCargada != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado peliculas.\n");
                    break;
                }
                modificarPeliculaMain = modificarPelicula(listaPelicula);
                if(modificarPeliculaMain == 0)
                {
                    system("cls");
                    printf("\nSe modifico correctamente.\n");
                }
                 else
                {
                    system("cls");
                    printf("\n No se ha podido modificar el empleado.\n");
                }
            break;
        case 3://baja
            if(flagCargada != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado empleados.\n");
                    break;
                }
               borrarPeliculasMain = borrarPelicula(listaPelicula, TAM_PELICULA);
               if(borrarPeliculasMain == 0)
                {
                    system("cls");
                    printf("\nSe dio de baja correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido dar de baja la pelicula.\n");
                }
            break;
        case 4: //alta director
                agregarPeliculasMainDirec = agregarDirector(listaDirector);
                if(agregarPeliculasMainDirec == 0)
                {
                    flagCargada = 1;
                    system("cls");
                    printf("\nSe cargo correctamente.\n");
                }
            break;
        case 5: //elminar director
                borrarPeliculasMainDirec = borrarDirector(listaDirector, TAM_DIRECTOR);
               if(borrarPeliculasMainDirec == 0)
                {
                    system("cls");
                    printf("\nSe dio de baja correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido dar de baja el director.\n");
                }

            break;
        case 6:
            if(flagCargada != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado peliculas.\n");
                    break;
                }
            listar(listaPelicula, TAM_PELICULA, listaDirector, TAM_DIRECTOR);
            break;
        case 7:
            opcion = 7;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
        system("pause");
        system("cls");
    }while(opcion != 7);
    return 0;
}
