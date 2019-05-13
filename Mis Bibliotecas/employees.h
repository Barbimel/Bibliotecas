//IFNDEF_________________________________________________________________________________________________________________________________________________________________________________
#ifndef employees_H_INCLUDED
#define employees_H_INCLUDED
#include "employees.h"
#endif //employees_H_INCLUDED

//STRUCTS________________________________________________________________________________________________________________________________________________________________________________

typedef struct
{
    int id;
    char description[20];
}eSector;

typedef struct
{
    char name[51];
    char lastName[51];
    float salary;
    int sectorId;
    int fileNumber;
    int state;
}eEmployee;

//PROTOTIPES_____________________________________________________________________________________________________________________________________________________________________________

/** \brief inicia los campos "estado" del array estructura en valor 0 indicando que ese sitio esta vacio y disponible.
 * \param array[]: es el vector tipo estructura con el que va a trabajar la funcion.
 * \param size: es una variable tipo int que indica el tamaño del array recibido.
 * \return void. */

 void InitializeStates(eEmployee array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief muestra los datos de un solo empleado.
 * \param employed: es una variable tipo estructura con la que trabaja la funcion.
 * \param sector: es un array tipo estructura con el que trabaja la funcion.
 * \param sectorSize: es el tamaño del array recibido.
 * \return void. */

void showEmployee(eEmployee array[], int size, int id);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief muestra una lista de todos los empleados activos.
 * \param array: es el vector tipo estructura que contiene a todos los empleados activos.
 * \param size: es el tamaño del array antes recibido.
 * \param sector: es un vector tipo estructura relacionado al sector empresarial donde trabaja el empleado.
 * \param sectorSize: es el tamaño del vector sector recibido.
 * \return void.
 */

void showEmployees(eEmployee array[],int size,eSector sector[],int sectorSize);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief muestra el numero de legajo del ultimo empleado registrado.
 * \param employed: es el vector tipo estructura a recorrer.
 * \param size: es el tamaño del vector recibido.
 * \param lastRecord: es la variable donde almacenaremos el ultimo legajo ingresado.
 * \return lastRecord + 1: es el ultimo legajo + 1. */

int incrementalFileNumber (eEmployee employed[], int size, int* lastRecord);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief busca espacio libre en el array recibido para ingresar nueva variable tipo estructura.
 * \param array: es el vector tipo estructura con que el que trabaja la funcion.
 * \param size: es el tamaño del vector antes recibido.
 * \return 0 si hay espacio libre en el array, sino -1. */

int freeState(eEmployee array[],int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief busca un empleado por numero de legajo, para saber si existe en el sistema o no.
 * \param array: es el vector tipo estructura a recorrer.
 * \param size: es el tamaño del vector ingresado.
 * \param fileNumber: Nro. de legajo a buscar en el vector.
 * \return indexFile es la ubicacon dele empleado, si vale -1 entonces no existe ese empleado en el sistema.*/

int searchEmployee(eEmployee array[],int size,int fileNumber);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief registra un nuevo empleado y todos sus datos en el sistema.
 * \param array: es el vector tipo estructura donde almacenaremos al nuevo empleado.
 * \param size: es el tamaño del vector antes recibido.
 * \param sector: es el vector de tipo estructura relacionado a los sectores de la empresa.
 * \param sectorSize: es el tamaño del vector sector.
 * \return void. */

void registerEmployee (eEmployee array[], int size, eSector sector[], int sectorSize);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief Da la baja a un registro de empleado activo.
 * \param array: es el vector de tipo estructura con el que trabaja la funcion.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void unsubscribeEmployee(eEmployee array[],int size);
//_______________________________________________________________________________________________________________________________________________________________________________________
/** \brief modifica el registro de un empleado activo.
 * \param array: es el vector de tipo estructura con el que trabaja la funcion.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void modifyRecord (eEmployee array[], int size, eSector vector[], int vectorSize);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief Ordena de forma ascendente o descendente la lista de empleados activos.
 * \param array: es el vector de tipo estructura con el que trabaja la funcion.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void sortEmployees (eEmployee array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief Asocia la descripcion de cada sector de la empresa con un id y lo almacena es una vector char.
 * \param array: es el vector tipo char en que se almacena la informacion ingresada.
 * \param sector: es el vector tipo estructura que almacena los distintos sectores de la empresa.
 * \param sectorSize: es el tamaño del vector sector que es igual a la cantidad de sectores en la empresa.
 * \param id: es un dato de tipo entero que representa el numero con el que se identifica a cada sector.
 * \return void. */

void getSector(char array[],eSector sector[],int sectorSize,int id);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief muestra los sectores de la empresa.
 * \param array: es el vector de tipo estructura donde se almacena la informacion de los empleados.
 * \param size: es el tamaño del vector antes recibido.
 * \param sector: es el vector de tipo estructura que almacena la informacion de los sectores de la empresa.
 * \param sectorSize: es el tamaño del vector sector que equivale a la cantidad de sectores en la empresa.
 * \return void. */

void showSectors (eEmployee array[], int size, eSector sector[], int sectorSize);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief desubscribe a todos los empleados de la empresa y dispone de los lugares ocupados en sistema.
 * \param array: es el vector de tipo estructura donde se almacena la informacion de los empleados.
 * \param size: es el tamaño del vector recibido.
 * \return void */

void cleanDataBase (eEmployee array[], int size);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief brinda un informe sobre el dinero que se invierte en salarios, el promedio de los mismos y cuantos empleados superan ese promedio.
 * \param array es el vector de tipo estructura donde se almacena la informacion de los empleados.
 * \param size: es el tamaño del vector recibido.
 * \return void. */

 void salariesReport(eEmployee array[], int size);
 //_______________________________________________________________________________________________________________________________________________________________________________________
