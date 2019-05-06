//IFNDEF_________________________________________________________________________________________________________________________________________________________________________________
#ifndef lunches_H_INCLUDED
#define lunches_H_INCLUDED
#endif //lunches_H_INCLUDED

//STRUCTS________________________________________________________________________________________________________________________________________________________________________________

typedef struct
{
    int id;
    char description[50];
    float price;
}eMenu;

typedef struct
{
    int fileNumber;
    int menuId;
    int state;
    eDate lunchDate;
}eLunch;

//PROTOTIPES_____________________________________________________________________________________________________________________________________________________________________________

/** \brief muestra un menu de opciones de comidas.
 * \param void.
 * \return void */

void lunchMenues();
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief inicia los campos "estado" del vector lunches en valor 0 indicando que ese sitio esta vacio y disponible.
 * \param lunches: es el vector tipo estructura con el que va a trabajar la funcion.
 * \param lunchesSize: es el tamaño del vector lunches.
 * \return void. */

void initializeLunches(eLunch lunches[], int lunchesSize);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief busca espacio libre en el array recibido para ingresar nueva variable tipo estructura.
 * \param lunches: es el vector tipo estructura con el que va a trabajar la funcion.
 * \param lunchesSize: es el tamaño del vector lunches.
 * \return 0 si hay espacio libre en el array, sino -1. */

int availableLunch(eLunch lunches[], int lunchesSize);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief busca un almuerzo por numero de legajo, para saber si existe en el sistema o no.
 * \param lunches: es el vector tipo estructura con el que va a trabajar la funcion.
 * \param lunchesSize: es el tamaño del vector lunches.
 * \param id: es el numero de ID del menu a buscar.
 * \return index es la ubicacion donde se encuentra registrado el almuerzo, si vale -1 entonces no existe ese empleado en el sistema.*/

int seachLunch(eLunch lunches[], int lunchesSize, int id);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief registra un nuevo almuerzo y todos sus datos en el sistema.
 * \param lunches: es el vector tipo estructura con el que va a trabajar la funcion.
 * \param lunchesSize: es el tamaño del vector lunches.
 * \param sector: es el vector de tipo estructura relacionado a los sectores de la empresa.
 * \param sectorSize: es el tamaño del vector sector.
 * \param fileNumber:
 * \return void. */

int getLunch(eLunch lunches[],int lunchesSize, eEmployee employed[], int employedSize, eSector sector[],int sectorSize, int fileNumber);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief muestra los datos de un solo almuerzo.
 * \param lunches: es una variable tipo estructura que almacena los datos del almuerzo.
 * \return void. */

void showLunch(eLunch lunches);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief muestra una lista de todos los empleados activos.
 * \param lunches: es el vector tipo estructura con el que va a trabajar la funcion.
 * \param lunchesSize: es el tamaño del vector lunches.
 * \return void.
 */

void showLunches (eLunch lunches[], int lunchesSize);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief muestra el total que debe abonar el empleado por los almuerzos consumidos.
 * \param meals: es el vector tipo estructura que almacena la informacion sobre los almuerzos de los empleados.
 * \param mealsSize: es el tamaño del vector meals.
 * \param menues: es el vector tipo estructura donde se almacena la informacion sobre los menues disponibles.
 * \param menuesSize: es el tamaño del vector menues.
 * \return void */

int lunchesPayments (eLunch meals[], int mealsSize, eMenu menues[], int menuesSize);
//_______________________________________________________________________________________________________________________________________________________________________________________


//_______________________________________________________________________________________________________________________________________________________________________________________


//_______________________________________________________________________________________________________________________________________________________________________________________


//_______________________________________________________________________________________________________________________________________________________________________________________

