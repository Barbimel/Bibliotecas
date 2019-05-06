//IFNDEF_________________________________________________________________________________________________________________________________________________________________________________
#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#endif //input_H_INCLUDED

//STRUCTS________________________________________________________________________________________________________________________________________________________________________________

typedef struct
{
    int day;
    int month;
    int year;
}eDate;

//PROTOTIPES_____________________________________________________________________________________________________________________________________________________________________________

/** \brief Despliega un menu de opciones al usuario.
 * \param void.
 * \return opcionMenu: es la opcion que el usuario ingresa por teclado. */

int menu(void);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide un numero entero al usuario, lo valida por rango y lo devuelve.
 * \param inputInt: es la variable donde almacenaremos el numero ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es el numero minimo que se puede ingresar.
 * \param max: es el numero maximo que se puede ingresar.
 * \return void */

void getInt(int* inputInt, char message[], char error[], int min, int max);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide un numero entero al usuario, lo valida por rango con intentos limitados.
 * \param inputInt: es la variable donde almacenaremos el numero ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es el numero minimo que se puede ingresar.
 * \param max: es el numero maximo que se puede ingresar.
 * \param tries: es la cantidad de intentos disponibles.
 * \return void */

void getIntTries(int* inputInt, char* message[], char* error[], int min, int max, int tries);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide un numero decimal al usuario, lo valida por rango y lo devuelve.
 * \param inputFloat: es la variable donde almacenaremos el numero ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es el numero minimo que se puede ingresar.
 * \param max: es el numero maximo que se puede ingresar.
 * \return void */

void getFloat(float* inputFloat, char message[], char error[], float min, float max);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide un numero decimal al usuario, lo valida por rango con intentos limitados.
 * \param inputFloat: es la variable donde almacenaremos el numero ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es el numero minimo que se puede ingresar.
 * \param max: es el numero maximo que se puede ingresar.
 * \param tries: es la cantidad de intentos disponibles.
 * \return void */

void getFloatTries(float* inputFloat, char* message[], char* error[], int min, int max, int tries);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide un caracter al usuario, lo valida por rango y lo devuelve.
 * \param inputChar: es la variable donde almacenaremos el caracter ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es el caracter minimo que se puede ingresar.
 * \param max: es el caracter maximo que se puede ingresar.
 * \return void */

void getChar(char* inputChar, char message[], char error[], char min, char max);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief busca una respuesta del usuario pidiendole que indique un caracter u otro.
 * \param inputChar: es la variable donde almacenaremos el caracter ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es el primer caracter valido que se puede ingresar.
 * \param max: es el segundo caracter valido que se puede ingresar.
 * \return void */

 void getSpecificChar(char* inputChar, char message[], char error[], char min, char max);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide un caracter al usuario, lo valida por rango con intentos limitados.
 * \param inputChar: es la variable donde almacenaremos el caracter ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es el caracter minimo que se puede ingresar.
 * \param max: es el caracter maximo que se puede ingresar.
 * \return void */

void getCharTries(char* inputChar, char* message[], char* error[], char min, char max, int tries);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide un texto al usuario, lo valida por rango y lo devuelve.
 * \param inputString: es la variable donde almacenaremos el texto ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es la cantidad de caracteres minima permitida.
 * \param max: es la cantidad de caracteres maxima permitida.
 * \return void */

 void getString (char* inputString, char* message[], char* error[], int min, int max);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide un texto al usuario, lo valida por rango con intentos limitados.
 * \param inputString: es la variable donde almacenaremos el texto ingresado.
 * \param message: es el mensaje a mostrar al pedir el dato.
 * \param error: es el mensaje de error a mostrar en tal caso.
 * \param min: es la cantidad de caracteres minima permitida.
 * \param max: es la cantidad de caracteres maxima permitida.
 * \return void */

 void getStringTries (char* inputString, char* message[], char* error[], int min, int max, int tries);
//_______________________________________________________________________________________________________________________________________________________________________________________

/** \brief pide el ingreso de una fecha al usuario.
 * \param toDate: es la variable tipo estructura donde alcenaremos la fecha ingresada.
 * \param typeDate: El tipo de fecha que queremos ingresar (Ej. nacimiento, casamiento, despido, etc.).
 * \param minYear: es el año minimo permitido en la fecha a ingresar.
 * \param maxYear: es el año maximo permitido en la fecha a ingresar.
 * \return 0 si el usuario esta conforme con la fecha ingresada, -1 si quiere cancelar el proceso. */

int getDate (eDate toDate, char* typeDate, int minYear, int maxYear);
//_______________________________________________________________________________________________________________________________________________________________________________________
