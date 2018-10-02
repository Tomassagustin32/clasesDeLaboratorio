#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "peliculas.h"


int agregarPelicula(ePelicula lista, int len, char nacionalidad[], char titulo[],int anio,int id)
{
    ePelicula auxPelicula;
    int lugarLibre=buscarLibre(lista, len);
    int retorno=FALSE;

    if(lista!=NULL)
    {
        if(lugarLibre!= FALSE)
        {
            if(titulo!=NULL && nacionalidad!=NULL && director !=NULL && anio >0 )
            {
                strcpy(auxPelicula.titulo, titulo);
                strcpy(auxPelicula.nacionalidad, nacionalidad);
                auxPelicula.=anio;
                auxPelicula.id=generarNextId();
                auxPelicula.isEmpty = 0;//ocupado
                lista[lugarLibre]=auxPelicula; //preguntar luego

                retorno=TRUE;
            }
            else
            {
                printf("nombre apellido o salario esta mal");
            }

        }
        else
        {
            printf("No hay lugar libre\n");
            system("pause");
        }

    }
    system("cls");
    return retorno;

}

int buscarLibre( ePelicula lista[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i< tam; i++)
    {
        if( lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarPelicula(ePelicula lista[], int tam, int id)
{
    int indice = -1;
    int i;

    for(i=0; i < tam; i++)
    {

        if( lista[i].id == id && lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void cargarDirector(eDirector directores[], int tamDirector, int idDirector, char cadena[])
{
    int i;

    for(i=0; i < tamDirector; i++)
    {
        if( directores[i].idDirector == idDirector)
        {
            strcpy(cadena, directores[i].nombreDirector);
            break;
        }
    }
}

int menuDeOpciones()
{
    int opcion;
    //system("cls");
    printf("-----OPCIONES-----\n\n");
    printf("1. ALTA\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR\n");
    printf("ELIJA UNA OPCION: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

static int generarSiguienteId() //Genero un unico id por cada empleado que se ingresa
{
    static int id = -1;

    id ++;

    return id;
}

int mostrarPeliculas(ePelicula lista, int len)
{
    int retorno=FALSE;
    int i;
    if(lista!= NULL)
    {
        printf("ID\t    TITULO\t    NACIONALIDAD\t    ANIO\t    IdDIRECTOR\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnaPelicula(lista, i);
                retorno=TRUE;
            }
        }
    }
    return retorno;
}

int mostrarUnaPelicula(ePelicula lista, int indice)
{
    int retorno=FALSE;
    if(lista!=NULL)
    {
        if(lista[indice].isEmpty == 0)
        {
            printf("%d\t    %s\t    %s\t    %.3f\t    %d \n",lista[indice].id, lista[indice].nombre, lista[indice].nacionalidad, lista[indice].anio, lista[indice].idDirector);
            retorno=TRUE;
        }

    }
    return retorno;
}


