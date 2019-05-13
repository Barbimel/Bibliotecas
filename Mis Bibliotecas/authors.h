//IFNDEF_______________________________________________________________________________________________________________________________

#ifndef partners_H_INCLUDED
#define partners_H_INCLUDED
#include "partners.h"
#endif // socios_H_INCLUDED

#ifndef books_H_INCLUDED
#define books_H_INCLUDED
#include "books.h"
#endif // prestamos_H_INCLUDED

//ESTRUCTURAS___________________________________________________________________________________________________________________________

//PROTOTIPES____________________________________________________________________________________________________________________________

/** \brief inicia los campos "state" del array estructura en valor 0 indicando que ese sitio esta vacio y disponible.
 * \param array[]: es el vector tipo estructura con el que va a trabajar la funcion.
 * \param size: es una variable tipo int que indica el tamaño del array recibido.
 * \return void. */
void initializeAutores(eAutores array[], int size);
//______________________________________________________________________________________________________________________________________

/** \brief muestra una lista de todos los autores.
 * \param array: es el vector tipo estructura que contiene a todos los autores.
 * \param size: es el tamaño del array antes recibido.
 * \return void.
 */
void listarAutores (eAutores array[], int size);
//______________________________________________________________________________________________________________________________________

/** \brief recorre un vector en busca de un registro, partiendo de su ID.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector a recorrer.
 * \param id: Nro. de legajo a buscar en el vector.
 * \return devuelve la ubicacion del registro, si no lo encuentra devuelve -1. */

 int buscarAutor(eAutores array[], int size, int id);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector e imprime una registro activo.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void mostrarAutor(eAutores array[], int size, int id);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector e imprime una lista de los registros activos.
 * \param array: es el vector en el que busca los registros.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void mostrarAutores(eAutores array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre y ordena de forma ascendente la lista de registros activos.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void ordenarAutores(eAutores array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief muestra el autor con mas libros registrados.
 * \param array: es el vector estructura donde se guardan los datos sobre los autores
 * \param size: es el tamaño del vector antes ingresado.
 * \param vector: es el arreglo estructura que guarda la informacion sobre los libr
 * \param vectorSize: es el tamaño del parametro "vector".
 * \return void. */

void AutorMasLibros (eAutores array[], int size, eLibros vector[], int vectorSize);
//_____________________________________________________________________________________________________________________________________

/** \brief muestra el registro de todos los autores.
 * \param array: es el vector estructura donde se guardan los datos sobre los autores
 * \param size: es el tamaño del vector antes ingresado.
 * \param vector: es el arreglo estructura que guarda la informacion sobre los libros.
 * \param vectorSize: es el tamaño del parametro "vector".
 * \return void. */

void registroAutores(eAutores array[], int size, eLibros vector[], int vectorSize);
//_____________________________________________________________________________________________________________________________________

