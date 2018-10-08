#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "parcialPeliculas.h"

int inicializarPelicula(ePelicula listaPelicula[], int len)
{
    int flag = -1;
    int i;
    for(i = 0 ; i < len; i++)
    {
        listaPelicula[i].isEmpty = LIBRE;
        flag = 0;
    }

    return flag;
}




int buscarLugarLibre(ePelicula listaPelicula[], int len)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listaPelicula[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int siguienteId(ePelicula listaPelicula[],int len)
{
    int value = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        if(listaPelicula[i].isEmpty== OCUPADO)
        {
            if(listaPelicula[i].id > value)
            {
                value = listaPelicula[i].id;
            }
        }
    }
    return value + 1;
}



void mostrarUnaPelicula(ePelicula listaPelicula[], int index)
{
    if(listaPelicula[index].isEmpty == OCUPADO)
    {
        printf(" %5d| %-40s         | %5d    |  %5d  | %-20s\n", listaPelicula[index].id, listaPelicula[index].titulo,
               listaPelicula[index].director, listaPelicula[index].anio, listaPelicula[index].nacionalidad);
    }
}

void mostrarPeliculas(ePelicula listaPelicula[], int len)
{
    int i;
    printf("\n\n    Id| Titulo                  | Director |   Anio  | Nacionalidad  \n");
    for(i = 0; i < len; i++)
    {
        if(listaPelicula[i].isEmpty != LIBRE)
        {
            mostrarUnaPelicula(listaPelicula, i);
        }
    }
}

int validarAnio(char mensaje[])
{
    int anio;
   int flag = 0;
   do
   {
         anio = getIntOnly(mensaje);
        if(anio < 1600 || anio > 2018)
        {
            system("cls");
            printf("\nEl anio no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
        }
   }while(flag != 1);
return anio;
}

int modificarPelicula(ePelicula listaPelicula[])
{
    int auxId;
    int indexPosicion;
    int flag;

    system("cls");
    printf("MODIFICAR\n\n");
    mostrarPeliculas(listaPelicula, TAM_PELICULA);
    auxId = getIntOnly("Ingrese el Id a modificar: ");
    indexPosicion = encontrarPeliculaPorId(listaPelicula, TAM_PELICULA, auxId);
    if(indexPosicion == -1)
    {
        printf("\nLa Id no existe.\n");
        system("pause");
        flag = -1;
    }
    else
    {
        modificarMenu(listaPelicula, indexPosicion);
        flag = 0;
    }

    return flag;
}

int encontrarPeliculaPorId(ePelicula listaPelicula[], int len, int id)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listaPelicula[i].isEmpty != LIBRE && listaPelicula[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void modificarMenu(ePelicula listaPelicula[], int posicion)
{
    int opcion;

    do
    {
        system("cls");
        opcion = getIntOnly("MODIFICAR\n\n1.Titulo \n2.Anio \n3.Nacionalidad \n4.Director \n5.Regresar \n Ingrese una opcion: ");
        switch(opcion)
        {
        case 1: //modificar titulo
            modificarTitulo(listaPelicula, posicion);
            break;
        case 2: //modificar Anio
            modificarAnio(listaPelicula, posicion);
            break;
        case 3: //modificar nacionalidad
            modificarNacionalidad(listaPelicula, posicion);
            break;
        case 4: //modificar director
            modificarDirector(listaPelicula, posicion);
            break;
        case 5://regresar
            opcion = 5;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
    }
    while(opcion != 5);
}

void modificarTitulo(ePelicula listaPelicula[], int posicion)
{
    char auxTitulo[60];
    system("cls");
    printf("Modificacion del titulo\n\n");
    mostrarUnaPelicula(listaPelicula, posicion);
    getStringOnly("\nIngrese el nuevo titulo: ", auxTitulo);
    printf("\nEsta seguro que desea cambiar el titulo?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listaPelicula[posicion].titulo, auxTitulo);
    }
}

void modificarAnio(ePelicula listaPelicula[], int posicion)
{
    int auxAnio;
    system("cls");
    printf("Modificacion del anio\n\n");
    mostrarUnaPelicula(listaPelicula, posicion);
    auxAnio = validarAnio("\nIngrese el nuevo anio: ");
    printf("\nEsta seguro que desea cambiar el anio?(s/n): ");
    if(getch() == 's')
    {
        listaPelicula[posicion].anio = auxAnio;
    }
}

void modificarNacionalidad(ePelicula listaPelicula[], int posicion)
{
    char auxNacionalidad[100];
    system("cls");
    printf("Modificacion de nacionalidad\n\n");
    mostrarUnaPelicula(listaPelicula, posicion);
    getStringOnly("\nIngrese la nueva nacionalidad: ", auxNacionalidad);
    printf("\nEsta seguro que desea cambiar la nacionalidad?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listaPelicula[posicion].nacionalidad, auxNacionalidad);
    }
}

void modificarDirector(ePelicula listaPelicula[], int posicion)
{
    int auxDirector;
    system("cls");
    printf("Modificacion del director\n\n");
    mostrarUnaPelicula(listaPelicula, posicion);
    auxDirector = getIntOnly("\nIngrese el nuevo director: ");
    printf("\nEsta seguro que desea cambiar el director?(s/n): ");
    if(getch() == 's')
    {
        listaPelicula[posicion].anio = auxDirector;
    }
}

void inicializarHardcodeoPeliculas(ePelicula listaPelicula[])
{
    int id[4] = {100,101,102,103};
    char titulo[][50] = {"contratiempo", "love rosie", "fragmentado", "el conjuro"};
    int anio[4] = {2000,2001,2010,2018};
    int director[4] = {100,101,102,103};
    char nacionalidad[][50] = {"espana", "eeuu", "argentina", "ingles"};

    int i;

    for(i=0; i<4; i++)
    {
        listaPelicula[i].id=id[i];
        listaPelicula[i].anio=anio[i];
        listaPelicula[i].director = director[i];
        listaPelicula[i].isEmpty = OCUPADO;
        strcpy(listaPelicula[i].titulo, titulo[i]);
        strcpy(listaPelicula[i].nacionalidad, nacionalidad[i]);
    }

}

int borrarPelicula(ePelicula listaPelicula[], int len)
{
    int auxId;
    int index;
    int flag;

    system("cls");
    printf("BAJA (pelicula)\n\n");
    mostrarPeliculas(listaPelicula, len);
    auxId = getIntOnly("\nIngrese el numero de Id a dar de baja: ");
    index = encontrarPeliculaPorId(listaPelicula, len, auxId);
    if(index == -1)
    {
        printf("No se encuentra ese Id.\n");
        system("pause");
        flag = -1;
    }
    else
    {
        printf("\nEsta seguro que desea dar de baja?(s/n): ");
        if(getch() == 's')
        {
            listaPelicula[index].isEmpty = LIBRE;
            flag = 0;
        }
    }
    return flag;
}

