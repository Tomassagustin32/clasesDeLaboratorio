#include "bibliotecaGetsYComprobaciones.h"
#define TAM_DIRECTOR 500
#define FREE 1
#define OCUPADO 0

typedef struct
{
    char dia[3];
    char mes[3];
    char anio[5];
    char fecha[11];
}eFecha;

typedef struct
{
    int id;
    char nombre[51];
    eFecha fechaNacimiento;
    char paisOrigen[51];
    int isEmpty;
}eDirector;

/** \brief add a director in array of directores
 *
 * \param listaDirector[] eDirector array of directores
 * \return int return (-1) si error, (0) si ok
 *
 */
int agregarDirector(eDirector listaDirector[]);

/** \brief carga la informacion de un director
 *
 * \param listaDirector[] eDirector array de directores
 * \return eDirector data set de director
 *
 */
eDirector setDirec(eDirector listaDirector[]);

/** \brief busca lugar libre en la bandera(isEmpty)
 *
 * \param listaDirector[] eDirector array de directores
 * \param len int array longitud
 * \return int index de lugar libre
 *
 */
int buscarLugarLibreDirector(eDirector listaDirector[], int len);

/** \brief buscar lugar libre en flag(isEmpty)
 *
 * \param listaDirector[] eDirector array de directores
 * \param len int array longitud
 * \return int index para lugar libre
 *
 */
int siguienteIdDirector(eDirector listaDirector[],int len);

/*
eFecha getFecha(eDirector listaDirector[]);

char validDia(char mensaje[]);

char validMes(char mensaje[]);

char validAnioDirec(char mensaje[]);
*/

/** \brief muestra array de directores
 *
 * \param listaDirector[] eDirector array de directores
 * \param len int array longitud
 * \return void
 *
 */
void mostrarDirectores(eDirector listaDirector[], int len);

/** \brief muestra la informacion de un director
 *
 * \param listaDirector[] eDirector array de directores
 * \param index int posicion de director
 * \return void
 *
 */
void mostrarUnDirector(eDirector listaDirector[], int index);

/** \brief Inicializa todas las banderas (isEmpty) en true
 *
 * \param listaDirector eDirector array de directores
 * \param len int array longitud
 * \return int  Return (-1) si Error - (0) si Ok
 *
 */
int inicializarDirector(eDirector listaDirector[], int len);

/** \brief busca los directores por nombre y retorna la posicion en array
 *
 * \param listaDirector[] eDirector array de directores
 * \param len int array longitud
 * \param name[] char nombre para buscar
 * \return int (-1) si error o director index posicion
 *
 */
int encontrarDirectorPorNombre(eDirector listaDirector[], int len, char name[]);

/** \brief borra la interfaz del director
 *
 * \param listaDirector[] eDirector array de directores
 * \param len int array longitud
 * \return int (-1) si error, (0) si ok
 *
 */
int borrarDirector(eDirector listaDirector[], int len);

/** \brief validar si el dia esta entre 1 y 31
 *
 * \param mensaje[] char mensaje para mostrar
 * \param day[] char dia para modsiicar
 * \return void
 *
 */
void validarDia(char mensaje[], char dia[]);

/** \brief validar si el mes esta entre 1 y 12
 *
 * \param mensaje[] char mensaje para mostrar
 * \param month[] char mes para modificar
 * \return void
 *
 */
void validarMes(char mensaje[], char mes[]);

/** \brief validar si el anio esta entre 1600 y 2018
 *
 * \param mensaje[] char mensaje para mostrar
 * \param year[] char anio para mo0dsiicar
 * \return void
 *
 */
void validarAnioDirector(char mensaje[], char anio[]);

/** \brief set de dia, mes y anio en variable fecha
 *
 * \param void
 * \return eFecha fecha
 *
 */
eFecha setDate(void);

/** \brief inicializo harcode de directores
 *
 * \param listaDirector[] eDirector array de directores
 * \return void
 *
 */
void inicializarDirectortorHardCode(eDirector listaDirector[]);

int ordenarDirectores(eDirector listaDirector[], int len);
