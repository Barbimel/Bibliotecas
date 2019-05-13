//IFNDEF________________________________________________________________________________________________________________________________
#ifndef partners_H_INCLUDED
#define partners_H_INCLUDED
#include "partners.h"
#endif // socios_H_INCLUDED

//ESTRUCTURAS___________________________________________________________________________________________________________________________

//PROTOTIPES____________________________________________________________________________________________________________________________

/** \brief recorre un vector estructura y setea los campos "state" en 0.
 * \param array[]: es el vector estructura a recorrer.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void iniciarlibros(eLibros array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre y ordena de forma ascendente la lista de registros activos.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void ordenarLibros(eLibros array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief muestra una lista de todos los libros disponibles.
 * \param array: es el vector tipo estructura que contiene a todos los libros activos.
 * \param size: es el tamaño del array antes recibido.
 * \return void.
 */
void listarLibros (eLibros array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector en busca de un registro, partiendo de su ID.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector a recorrer.
 * \param id: Nro. de legajo a buscar en el vector.
 * \return devuelve la ubicacion del registro, si no lo encuentra devuelve -1. */

int buscarLibro(eLibros array[], int size, int id);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector e imprime una registro activo.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void mostrarLibro(eLibros array[], int size, int id);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector e imprime una lista de los registros activos.
 * \param array: es el vector en el que busca los registros.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void mostrarLibros (eLibros array[], int size);
//_____________________________________________________________________________________________________________________________________

