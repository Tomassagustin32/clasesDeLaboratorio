#include "parcialDirectores.h"
#include "parcialPeliculas.h"

/** \brief list interface
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \param lenPelicula int array peliculas longitud
 * \param listaDirector[] eDirector array de directores
 * \param lenDirec int array directores longitud
 * \return void
 *
 */
void listar(ePelicula listaPelicula[], int lenPelicula, eDirector listaDirector[], int lenDirec);

/** \brief muestra informacion de la pelicula
 *
 * \param listaPelicula ePelicula array de peliculas
 * \return ePelicula data set de pelicula
 *
 */
ePelicula setpeliculas(ePelicula listaPelicula[], eDirector listaDirector[], int lenDirec);

/** \brief agrega peliculas en array de peliculas
 *
 * \param listaPelicula[] ePelicula array de peliculas
 * \return int return (-1) si error, (0) si ok
 *
 */
int agregarPeliculas(ePelicula listaPelicula[], eDirector listaDirector[]);
