#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct
{
    char nacionalidad[20];
    char titulo;
    int id;
    int idDirector;
    char director[20];
    int anio;
    int isEmpty;
}ePelicula;

typedef struct
{
    int idDirector;
    char nombreDirector[40];
    char paisOrigen[20];
}eDirector;

int agregarPeliculaEmployee(ePelicula* lista, int len, char nacionalidad[], char titulo[],int anio,int id);
int buscarLibre( ePelicula* lista[], int tam);
int buscarPelicula(ePelicula lista[], int tam, int id);
void mostrarPelicula(ePelicula emp, eDirector directores[], int tamDirector);
int menuDeOpciones;
