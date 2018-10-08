#include "bibliotecaGetsYComprobaciones.h"
#define TAM_PELICULA 1000
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    int id;
    char titulo[51];
    char nacionalidad[51];
    int director;
    int anio;
    int isEmpty;
}ePelicula;

/** \brief Inicializar las banderas (isEmpty) en TRUE
 *
 * \param listaPelicula ePelicula array de peliculas
 * \param len int array longitud
 * \return int  Return (-1) si error - (0) si Ok
 *
 */
int inicializarPelicula(ePelicula listaPelicula[], int len);



/** \brief busca lugar libre en bandera(isEmpty)
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param len int array longitud
 * \return int index de lugar LIBRE
 *
 */
int buscarLugarLibre(ePelicula listaPelicula[], int len);


/** \brief busca lugar libre para el siguiente id
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param len int array longitud
 * \return int valor de la siguiente id
 *
 */
int siguienteId(ePelicula listaPelicula[],int len);

/** \brief muestra informacion de una pelicula
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param index int posicion de peliculas
 * \return void
 *
 */
void mostrarUnaPelicula(ePelicula listaPelicula[], int index);

/** \brief muestra array de peliculas
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param len int array longitud
 * \return void
 *
 */
void mostrarPeliculas(ePelicula listaPelicula[], int len);

/** \brief comprueba si el número de entrada es un anio lógico
 *
 * \param mensaje[] char
 * \return int anio
 *
 */
int validarAnio(char mensaje[]);

/** \brief busca pelicula por id y retorna la posicion en array
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param len int array longitud
 * \param id int id para buscar
 * \return int (-1) si error o film index posicion
 *
 */
int encontrarPeliculaPorId(ePelicula listaPelicula[], int len, int id);

/** \brief menu para seleccioanr que modificar
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param posicion int film posicion in array
 * \return void
 *
 */
void modificarMenu(ePelicula listaPelicula[], int posicion);

/** \brief modificar el titulo de una pelicula
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param posicion int film posicion in array
 * \return void
 *
 */
void modificarTitulo(ePelicula listaPelicula[], int posicion);

/** \brief modificar el anio de la pelicula
*
 * \param listaPelicula[] ePelicula array de peliculas
 * \param posicion int film posicion in array
 * \return void
 *
 */
void modificarAnio(ePelicula listaPelicula[], int posicion);

/** \brief modificar el director de la pelicula
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param posicion int film posicion in array
 * \return void
 *
 */
void modificarDirector(ePelicula listaPelicula[], int posicion);

/** \brief modificar la nacionalidad de la pelicula
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param posicion int film posicion in array
 * \return void
 *
 */
void modificarNacionalidad(ePelicula listaPelicula[], int posicion);


/** \brief modificar interfaz de pelicula
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \return int (-1) si error, (0) si ok
 *
 */
int modificarPelicula(ePelicula listaPelicula[]);

/** \brief inicializar harcode de peliculass
 *
 * \param listaPelicula[] ePelicula array de peliculass
 * \return void
 *
 */
void inicializarHardcodeoPeliculas(ePelicula listaPelicula[]);

/** \brief remove film interface
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param len int array longitud
 * \return int (-1) si error, (0) si ok
 *
 */
int borrarPelicula(ePelicula listaPelicula[], int len);

//int peliculaMasVieja(ePelicula listaPelicula[], int len);

//int mostrarPeliculaMasVieja(ePelicula listaPelicula[], int len);

void peliculaMasVieja(ePelicula listaPelicula[], int len);

void mostrarMasVieja(ePelicula listaPelicula[], int len);

