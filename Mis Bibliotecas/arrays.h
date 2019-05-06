//IFNDEF_________________________________________________________________________________________________________________________________________________________________________________
#ifndef arrays_H_INCLUDED
#define arrays_H_INCLUDED
#endif //arrays_H_INCLUDED

//STRUCTS________________________________________________________________________________________________________________________________________________________________________________

//PROTOTIPES_____________________________________________________________________________________________________________________________________________________________________________

/** \brief imprime un array tipo int.
 * \param array: es el vector a imprimir.
 * \param size: es el tamaño del vector recibido.
 * \return void. */

 void intPrint (int array[], int size);
 //_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief ordena de forma ascendente un array tipo int.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector a ordenar.
 * \return void. */

 void intUpSorting (int array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief ordena de forma descendente un array tipo int.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector a ordenar.
 * \return void.
 */

void intDownSorting(int array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief imprime un array tipo float.
 * \param array: es el vector a imprimir.
 * \param size: es el tamaño del vector recibido.
 * \return void. */

 void floatPrint (float array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief ordena de forma ascendente un array tipo float.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector a ordenar.
 * \return void. */

void floatUpSorting(float array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief ordena de forma descendente un array tipo float.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector a ordenar.
 * \return void.  */

void floatDownSorting(float array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief imprime un array tipo char;
 * \param array: es el vector a imprimir.
 * \param size: es el tamaño del vector recibido.
 * \return void. */

void charPrint (char array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief ordena de forma ascendente un array tipo char.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector a ordenar.
 * \return void. */

void charUpSorting(char array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief ordena de forma descendente un array tipo char.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector a ordenar.
 * \return void. */

 void charDownSorting(char array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________
/** \brief imprime un array tipo string;
 * \param array: es el vector a imprimir.
 * \param size: es el tamaño del vector recibido.
 * \return void. */

void stringPrint (char* array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief ordena de forma ascendente un array tipo string.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector a ordenar.
 * \return void. */

void stringUpSorting(char array[], int size); //NO FUNCIONA.
//_______________________________________________________________________________________________________________________________________________________________________________________
