#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bibliotecaParcial.h"


void listar(ePelicula listaPelicula[], int lenPelicula, eDirector listaDirector[], int lenDirec)
{

    int  opcion;
    system("cls");
    do
    {
        opcion = getIntOnly("Listar\n\n1.Listar Peliculas\n2.Listar Directores\n3.Listar Mas Vieja\n4.Regresar\nIngrese una opcion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            mostrarPeliculas(listaPelicula, lenPelicula);
            system("pause");
            break;
        case 2:
            system("cls");
            mostrarDirectores(listaDirector, lenDirec);
            system("pause");
            break;
        case 3:
            /*system("cls");
            mostrarPeliculaMasVieja(listaPelicula, lenPelicula);
            system("pause");
            break;*/
                system("cls");
                //printf("Listado de Peliculas:\n\nID\nTitulo\nNacionalidad\nAnio\nDirector\n");
                //mostrarPeliculas(listaPelicula, lenPelicula);
                //peliculaMasVieja(listaPelicula, lenPelicula, opcion);
                mostrarMasVieja(listaPelicula, lenPelicula);
                system("pause");


            //peliculaMasVieja(listaPelicula, lenPelicula, opcion);
            break;
        case 4:
            opcion = 4;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
        system("cls");
    }while(opcion != 4);
}

ePelicula setFilm(ePelicula listaPelicula[], eDirector listaDirector[], int lenDirec)
{
    ePelicula film;
    int flag = 0;

    film.id = siguienteId(listaPelicula, TAM_PELICULA);

    fflush(stdin);
    getStringOnly("Ingrese el titulo: ", film.titulo);

    fflush(stdin);
    getStringOnly("Ingrese la nacionalidad: ", film.nacionalidad);

    film.anio = validarAnio("Ingrese el anio: ");
    do
    {
    mostrarDirectores(listaDirector, lenDirec);
    film.director = getIntOnly("Ingrese ID del director: ");
    int i;
    for(i = 0; i < lenDirec; i++)
    {
        if(film.director != listaDirector[i].id || film.director == 0)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Ese director no existe\n");
    }
    system("pause");
    system("cls");
    }while(flag != 1);

    film.isEmpty = OCUPADO;

    return film;
}

int agregarPeliculas(ePelicula listaPelicula[], eDirector listaDirector[])
{
    int flag;
    int indexLugarLibre;

    indexLugarLibre = buscarLugarLibre(listaPelicula, TAM_PELICULA);
    if(indexLugarLibre == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        flag = -1;
    }
    system("cls");
    printf("ALTA\n\n");
    listaPelicula[indexLugarLibre] = setFilm(listaPelicula, listaDirector, TAM_DIRECTOR);
    flag = 0;

    return flag;
}
