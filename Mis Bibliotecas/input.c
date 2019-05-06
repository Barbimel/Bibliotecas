//LIBRARIES______________________________________________________________________________________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//IFNDEF________________________________________________________________________________________________________________________________________________________________________________
#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif //input_H_INCLUDED

//FUNCIONES_______________________________________________________________________________________________________________________________________________________________________________

int menu (void)
{
    int choice;

    printf("MENU DE OPCIONES: \n");

    printf("1. ALTA DE EMPLEADO. \n");
    printf("2. BAJA DE EMPLEADO. \n");
    printf("3. MODIFICAR REGISTRO DE EMPLEADO. \n");
    printf("4. ORDENAR LISTA DE EMPLEADOS. \n");
    printf("5. LISTAR EMPLEADOS. \n");
    printf("6. LISTAR EMPLEADOS POR SECTOR. \n");
    printf("7. ORDENAR SECTORES POR CANTIDAD DE EMPLEADOS. \n");
    printf("8. SALIR \n");

    printf("Ingrese el numero de la funcion a realizar: ");
    setbuf(stdin, NULL);
    scanf("%d",&choice);

    return choice;
}
//________________________________________________________________________________________________________________________________________________________________________________________

void getInt (int* inputInt, char message[], char error[], int min, int max)
{
    printf(message);
    scanf("%d", inputInt);

    while (*inputInt < min || *inputInt > max)
    {
        printf(error);
        printf(message);
        scanf("%d", inputInt);
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void getIntTries (int* inputInt, char* message[], char* error[], int min, int max, int tries)
{
    do
    {
        printf(message);
        scanf("%d", inputInt);

        if(*inputInt < min || *inputInt > max)
        {
            tries--;
            printf(error);
        }
        else
        {
            break;
        }
    }while (tries > 0);
}
//_______________________________________________________________________________________________________________________________________________________________________________________

void getFloat (float* inputFloat, char message[], char error[], float min, float max)
{
    printf(message);
    scanf("%f", inputFloat);

    while (*inputFloat < min || *inputFloat > max)
    {
        printf(error);
        printf("\n\n");
        printf(message);
        scanf("%f", inputFloat);
    }
}
//_______________________________________________________________________________________________________________________________________________________________________________________

void getFloatTries (float* inputFloat, char* message[], char* error[], int min, int max, int tries)
{
    do
    {
        printf(message);
        scanf("%f", inputFloat);

        if(*inputFloat < min || *inputFloat > max)
        {
            tries--;
            printf(error);
        }
        else
        {
            break;
        }
    }while (tries > 0);
}
//_______________________________________________________________________________________________________________________________________________________________________________________

void getChar (char* inputChar, char message[], char error[], char min, char max)
{
    printf(message);
    setbuf(stdin,NULL);
    scanf("%c", inputChar);

    while (*inputChar < min || *inputChar > max)
    {
        printf(error);
        printf(message);
        setbuf(stdin,NULL);
        scanf("%c", inputChar);
    }
    *inputChar = toupper(*inputChar);
}
//_______________________________________________________________________________________________________________________________________________________________________________________

void getSpecificChar (char* inputChar, char message[], char error[], char min, char max)
{
    printf(message);
    setbuf(stdin, NULL);
    scanf("%c", inputChar);
    setbuf(stdin, NULL);

    while (*inputChar != min && *inputChar != max)
    {
        printf(error);
        printf("\n\n");
        printf(message);

        scanf("%c", inputChar);
        setbuf(stdin, NULL);
    }
    *inputChar = toupper(*inputChar);
}
//_______________________________________________________________________________________________________________________________________________________________________________________

void getCharTries (char* inputChar, char* message[], char* error[], char min, char max, int tries)
{
    do
    {
        printf(message);
        setbuf(stdin, NULL);
        scanf("%c", inputChar);

        if(*inputChar < min || *inputChar > max)
        {
            tries--;
            printf(error);
        }
        else
        {
            break;
        }
    }while (tries > 0);

    *inputChar = toupper(*inputChar);
}
//_______________________________________________________________________________________________________________________________________________________________________________________

void getString (char* inputString, char* message[], char* error[], int min, int max)
{
    printf(message);
    setbuf(stdin, NULL);
    gets(inputString);
    *inputString = tolower(*inputString);

    while (strlen(inputString) < min || strlen(inputString) > max)
    {
        printf(error);
        printf("\n\n");
        printf(message);
        setbuf(stdin, NULL);
        gets(inputString);
        *inputString = tolower(*inputString);
    }
}
//_______________________________________________________________________________________________________________________________________________________________________________________

void getStringTries (char* inputString, char* message[], char* error[], int min, int max, int tries)
{
    do
    {
        printf(message);
        setbuf(stdin, NULL);
        gets(inputString);

        if(strlen(inputString) < min || strlen(inputString) > max)
        {
            tries--;
            printf(error);
            printf("\n\n");
        }
        else
        {
            *inputString = toupper(*inputString);
            break;
        }
    }while (tries > 0);
}
//_______________________________________________________________________________________________________________________________________________________________________________________

int getDate (eDate toDate, char* typeDate, int minYear, int maxYear)
{
    int ok;
    char confirm;

    printf("-");
    printf(typeDate);
    printf("-\n");
    getInt(&toDate.year, "Ingrese el numero de anio: ", "ERROR! El anio ingresado no es valido. \n\n", minYear, maxYear);
    getInt(&toDate.month, "Ingrese el numero de mes: ", "ERROR! Hay 12 meses en el calendario.\n\n", 1, 12);

    switch(toDate.month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                getInt(&toDate.day, "Ingrese el numero de dia: ", "ERRRO! El mes tiene 31 dias.\n\n", 1, 31);
                break;
        case 4:
        case 6:
        case 9:
        case 11:
                getInt(&toDate.day, "Ingrese el numero de dia: ", "ERROR! El mes tiene 30 dias. \n\n", 1, 30);
                break;
        default:
                getInt(&toDate.day, "Ingrese el numero de dia: ", "ERROR! El mes tiene 28 dias. \n\n", 1, 28);
                break;
    }

    printf("\nLa fecha ingresada es: %02d/%02d/%02d \n", toDate.day, toDate.month, toDate.year);
    getSpecificChar(&confirm, "\nEs correcta? (S/N): ", "ERROR! Debe ingresar S o N.\n", 's', 'n');

    if(confirm == 'S')
    {
        ok = 0;
    }
    else
    {
        printf("El ingreso de fecha fue cancelado.");
        ok: -1;
    }

    return ok;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
