//IFNDEF_______________________________________________________________________________________________________________________________
#ifndef partners_H_INCLUDED
#define partners_H_INCLUDED
#include "partners.h"
#endif // socios_H_INCLUDED

//ESTRUCTURAS__________________________________________________________________________________________________________________________

//PROTOTIPOS___________________________________________________________________________________________________________________________
/** \brief recorre un vector estructura y setea los campos "state" en 0.
 * \param array[]: es el vector estructura a recorrer.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void iniciarPrestamos(ePrestamos array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector en busca de un registro, partiendo de su ID.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector a recorrer.
 * \param id: Nro. de legajo a buscar en el vector.
 * \return devuelve la ubicacion del registro, si no lo encuentra devuelve -1. */

int buscarPrestamo(ePrestamos array[], int size, int id);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector e imprime una registro activo.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void mostrarPrestamo (ePrestamos array[], int size, int id);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector e imprime una lista de los registros activos.
 * \param array: es el vector en el que busca los registros.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void mostrarPrestamos (ePrestamos array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector buscando espacio disponible para un nuevo registro.
 * \param array: es el vector en el que busca espacio.
 * \param size: es el tamaño del vector a recorrer.
 * \return devuelve 0 cuando encuentra un espacio libre, si no lo hay retorna -1. */

int prestamosLibres(ePrestamos array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief gestiona el alta de un nuevo registro.
 * \param array: es el vector donde almacenaremos la informacion del nuevo registro.
 * \param size: es el tamaño vector antes recibido.
 * \return void. */

void altaPrestamo(ePrestamos array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief gestiona la modificacion de un registro activo.
 * \param array: es el vector que recorre en busca del registro a modificar.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void modificarPrestamo(ePrestamos array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief gestiona la baja de un registro activo.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void bajaPrestamo(ePrestamos array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief muestra los prestamos que registra un socio.
 * \param array: es el vector que guarda la informacion sobre los registros.
 * \param size: es el tamaño de vector antes recibido.
 * \param vector: es el arreglo que guarda la informacion sobre las personas.
 * \param size: es el tamaño del arreglo antes recibido.
  * \return void. */

void prestamosXSocio(eSocios array[], int size, ePrestamos vector[], int vectorSize);
//_____________________________________________________________________________________________________________________________________

/** \brief muestra los prestamos que registran los socios activos.
 * \param array: es el vector que guarda la informacion sobre los registros.
 * \param size: es el tamaño de vector antes recibido.
 * \param vector: es el arreglo que guarda la informacion sobre las personas.
 * \param size: es el tamaño del arreglo antes recibido.
  * \return void. */

void prestamosXSocios(ePrestamos array[], int size, eSocios vector[], int vectorSize);
//_____________________________________________________________________________________________________________________________________

/** \brief imprime los prestamos de un determinado libro.
 * \param array: es el vector estructura donde se guardan los datos sobre los libros.
 * \param size: es el tamaño del vector antes ingresado.
 * \param vector: es el arreglo estructura que guarda la informacion sobre los prestamos registrados.
 * \param vectorSize: es el tamaño del parametro "vector".
 * \return void. */

void prestamosXLibro(eLibros array[], int size, ePrestamos vector[],int vectorSize);
//_____________________________________________________________________________________________________________________________________

