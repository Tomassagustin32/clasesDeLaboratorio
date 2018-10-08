#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bibliotecaGetsYComprobaciones.h"
#include "parcialDirectores.h"

int agregarDirector(eDirector listaDirector[])
{
    int flag;
    int indexFreeSlot;

    indexFreeSlot = buscarLugarLibreDirector(listaDirector, TAM_DIRECTOR);
    if(indexFreeSlot == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        flag = -1;
    }
    system("cls");
    printf("ALTA\n\n");
    listaDirector[indexFreeSlot]= setDirec(listaDirector);
    flag = 0;

    return flag;
}

eDirector setDirec(eDirector listaDirector[])
{
    eDirector director;

    director.id = siguienteIdDirector(listaDirector, TAM_DIRECTOR);

    fflush(stdin);
    getStringOnly("Ingrese el nombre: ", director.nombre);

    fflush(stdin);
    getStringOnly("Ingrese el pais origen: ", director.paisOrigen);

    director.fechaNacimiento = setDate();

    director.isEmpty = OCUPADO;

    return director;
}

eFecha setDate()
{
    eDirector direc;
    char barra[2] = {"/"};

    validarDia("Ingrese el dia: ", direc.fechaNacimiento.dia);
    validarMes("Ingrese el mes: ", direc.fechaNacimiento.mes);
    validarAnioDirector("Ingrese el anio: ", direc.fechaNacimiento.anio);
    strcpy(direc.fechaNacimiento.fecha, direc.fechaNacimiento.dia);
    strcat(direc.fechaNacimiento.fecha, barra);
    strcat(direc.fechaNacimiento.fecha, direc.fechaNacimiento.mes);
    strcat(direc.fechaNacimiento.fecha, barra);
    strcat(direc.fechaNacimiento.fecha, direc.fechaNacimiento.anio);

    return direc.fechaNacimiento;
}
int buscarLugarLibreDirector(eDirector listaDirector[], int len)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listaDirector[i].isEmpty == FREE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int siguienteIdDirector(eDirector listaDirector[],int len)
{
    int value = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        if(listaDirector[i].isEmpty== OCUPADO)
        {
            if(listaDirector[i].id > value)
            {
                value = listaDirector[i].id;
            }
        }
    }
    return value + 1;
}

void validarDia(char mensaje[], char day[])
{
    int flag;
    int auxDia;

    do
   {
        auxDia = getIntOnly(mensaje);
        if(auxDia < 1 || auxDia  > 31)
        {
            system("cls");
            printf("\nEl dia no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
            itoa(auxDia, day, 10);
        }
   }while(flag != 1);
}

void validarMes(char mensaje[], char mes[])
{
    int flag;
    int auxMes;

    do
   {
        auxMes = getIntOnly(mensaje);
        if(auxMes < 1 || auxMes > 12)
        {
            system("cls");
            printf("\nEl mes no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
            itoa(auxMes, mes, 10);
        }
   }while(flag != 1);

}

void validarAnioDirector(char mensaje[], char anio[])
{
    int flag;
    int auxanio;

    do
   {
        auxanio = getIntOnly(mensaje);
        if(auxanio < 1600 || auxanio > 2018)
        {
            system("cls");
            printf("\nEl anio no es valido.\n");
            flag = 0;
        }
        else
        {
            flag = 1;
            itoa(auxanio, anio, 10);
        }
   }while(flag != 1);

}

void mostrarUnDirector(eDirector listaDirector[], int index)
{
    if(listaDirector[index].isEmpty == OCUPADO)
    {
        printf(" %5d| %-20s       | %-20s         | %s \n", listaDirector[index].id, listaDirector[index].nombre,
               listaDirector[index].paisOrigen, listaDirector[index].fechaNacimiento.fecha);
    }
}

void mostrarDirectores(eDirector listaDirector[], int len)
{
    int i;
    printf("\n\n    Id| Nombre                | Pais de origen     |Fecha de nacimiento\n");
    for(i = 0; i < len; i++)
    {
        if(listaDirector[i].isEmpty != FREE)
        {
            mostrarUnDirector(listaDirector, i);
        }
    }
}

int inicializarDirector(eDirector listaDirector[], int len)
{
    int flag = -1;
    int i;
    for(i = 0 ; i < len; i++)
    {
        listaDirector[i].isEmpty = FREE;
        flag = 0;
    }

    return flag;
}

int borrarDirector(eDirector listaDirector[], int len)
{
    char auxNombre[256];
    int index;
    int flag;

    system("cls");
    printf("BAJA(director)\n\n");
    mostrarDirectores(listaDirector, len);
    getStringOnly("\nIngrese el nombre del director a dar de baja: ", auxNombre);
    index = encontrarDirectorPorNombre(listaDirector, len, auxNombre);
    if(index == -1)
    {
        printf("No se encuentra ese nombre.\n");
        system("pause");
        flag = -1;
    }
    else
    {
        printf("\nEsta seguro que desea dar de baja?(s/n): ");
        if(getch() == 's')
        {
            listaDirector[index].isEmpty = FREE;
            flag = 0;
        }
    }
    return flag;
}

int encontrarDirectorPorNombre(eDirector listaDirector[], int len, char nombre[])
{
    int index = -1;
    int i;
    for(i = 0; i < len; i ++)
    {
        if(listaDirector[i].isEmpty != FREE && strcmp(listaDirector[i].nombre, nombre) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void inicializarDirectortorHardCode(eDirector listaDirector[])
{
    int id[4] = {100,101,102,103};
    char nombre[][50] = {"Oscar", "Ana", "Juan", "Jose"};
    char fecha[][11] = {"22/2/2000","10/11/1801","6/5/1978","30/8/2008"};
    char paisOrigen[][50] = {"argentina", "eeuu", "espana", "inglaterra"};

    int i;

    for(i=0; i<4; i++)
    {
        listaDirector[i].id = id[i];
        listaDirector[i].isEmpty = OCUPADO;
        strcpy(listaDirector[i].nombre, nombre[i]);
        strcpy(listaDirector[i].paisOrigen, paisOrigen[i]);
        strcpy(listaDirector[i].fechaNacimiento.fecha, fecha[i]);
    }
}
/*
int ordenarDirectores(eDirector listaDirector, int len)
{
    int retorno=-1;
    eDirector auxDirector;
    int i, j ;
    int opcion;
    mostrarDirectores(listaDirector, len);
    //int FLAG=0;
    if(listaDirector!= NULL)
    {
        //FLAG=1;
        printf("\n1.Ordenar alfabeticamente  de manera ascendente");
        printf("\n2.Ordenar alfabeticamente  de manera descendente");
        printf("\nElija la opcion :\n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1://ASCENDENTE
            for( i =0 ; i<len -1 ; i ++)
            {
                for(j= i+1 ; j<len; j++)
                {

                    if(strcmp(listaDirector[j].nombre,listaDirector[i].nombre)<0)
                    {
                        auxDirector = listaDirector[i];    mostrarDirectores(listaDirector, len);

                        listaDirector[i] = listaDirector[j];
                        listaDirector[j] = auxDirector;
                    }
                    else if(strcmp(listaDirector[j].nombre,listaDirector[i].nombre)==0 && listaDirector[j].id<listaDirector[i].id)
                    {
                        auxDirector = listaDirector[i];
                        listaDirector[i] = listaDirector[j];
                        listaDirector[j] = auxDirector;
                    }
                }
            }
            printf("\nOpcion completada con exito.\n");
            break;

        case 2://DESCENDENTE

            for( i =0 ; i<len -1 ; i ++)
            {
                for(j= i+1 ; j<len; j++)
                {
                    if(strcmp(listaDirector[i].nombre,listaDirector[j].nombre)<0)
                    {
                        auxDirector = listaDirector[i];
                        listaDirector[i] = listaDirector[j];
                        listaDirector[j] = auxDirector;
                    }
                    else if(strcmp(listaDirector[i].nombre,listaDirector[j].nombre)==0 && listaDirector[j].id>listaDirector[i].id)
                    {
                        auxDirector = listaDirector[i];
                        listaDirector[i] = listaDirector[j];
                        listaDirector[j] = auxDirector;
                    }
                }
            }
            printf("\nOpcion completada con exito.\n");
            break;

        }

        retorno=TRUE;
    }

    return retorno;

}
*/
