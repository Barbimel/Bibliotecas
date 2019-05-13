#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//IFNDEF_______________________________________________________________________________________________________________________________

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif // input_H_INCLUDED

#ifndef partners_H_INCLUDED
#define partners_H_INCLUDED
#include "partners.h"
#endif // socios_H_INCLUDED

#ifndef books_H_INCLUDED
#define books_H_INCLUDED
#include "books.h"
#endif // prestamos_H_INCLUDED

#ifndef borrowBooks_H_INCLUDED
#define borrowBooks_H_INCLUDED
#include "borrowBooks.h"
#endif // borrowBooks_H_INCLUDED

#ifndef authors_H_INCLUDED
#define authors_H_INCLUDED
#include "authors.h"
#endif // authors_H_INCLUDED

//FUNCIONES____________________________________________________________________________________________________________________________

void iniciarSocios(eSocios array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].state = 0;
    }
}
//_____________________________________________________________________________________________________________________________________

int buscarSocio(eSocios array[], int size, int id)
{
    int index = -1;

    for(int i = 0; i < size; i++)
    {
        if(array[i].state == 1 && array[i].socioId == id)
        {
            index = i;
        }
    }
    return index;
}
//_____________________________________________________________________________________________________________________________________

void ordenarSocios (eSocios array[], int size)
{
    eSocios auxiliary;

    for (int i = 0; i < size-1 ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (stricmp(array[i].apellido, array[j].apellido) > 0)
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }

            if (stricmp(array[i].nombre, array[j].nombre) > 0)
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//_____________________________________________________________________________________________________________________________________

void mostrarSocio(eSocios array[], int size, int id)
{
    printf("Registro encontrado: \n\n");

    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[i].socioId == id)
            {
                printf ("  %d   %s    %s    %c    %s   %s   %d/%d/%d \n", array[i].socioId, array[i].apellido, array[i].nombre, array[i].sexo, array[i].telefono, array[i].eMail, array[i].asociado.dia, array[i].asociado.mes, array[i].asociado.anio);
            }
        }
    }
}
//_____________________________________________________________________________________________________________________________________

void mostrarSocios(eSocios array[], int size)
{
    int records = 0;
    printf("\n ID   APELLIDO    NOMBRE    SEXO    TELEFONO    EMAIL          FECHA ASOCIADO \n");
    for (int i = 0; i < size; i++)
    {
        if (array[i].state == 1)
        {
            mostrarSocio(array, size, array[i].socioId);
            records++;
        }
    }
    if (records == 0)
    {
        printf("No hay registros que mostrar.\n\n");
    }
}

//_____________________________________________________________________________________________________________________________________

int sociosLibres(eSocios array[], int size)
{
    int freeSpot = -1;

    for(int i = 0; i < size; i++)
    {
        if(array[i].state == 0)
        {
            freeSpot = i;
        }
    }
    return freeSpot;
}
//_____________________________________________________________________________________________________________________________________

void altaSocio(eSocios array[], int size)
{
    int registered;
    int index;
    int id;
    int phoneOk;
    int eMailOk;
    int lastNameOk;

    index = sociosLibres(array, size);

    if(index == -1)
    {
        printf("No hay espacio para nuevos registros.\n\n");
    }
    else
    {
        printf("INGRESE EL ID DEL SOCIO: ");
        scanf("%d",&id);
        printf("\n\n");

        registered = buscarSocio(array, size, id);

        if(registered != -1)
        {
            printf("El registro ingresado ya existe: \n\n");
            printf("\n ID   APELLIDO    NOMBRE    SEXO    TELEFONO    EMAIL          FECHA ASOCIADO \n");
            mostrarSocio(array, size, id);
            printf("\n\n");
        }
        else
        {
            array[index].state = 1;
            array[index].socioId = id;

            do
            {
                getString(array[index].apellido, "INGRESE EL APELLIDO DEL SOCIO: ", "ERROR! El apellido es muy largo.", 2, 31);
                isAlphabetical(array[index].apellido);
            }while(lastNameOk != 0);


            getString(array[index].nombre, "INGRESE EL NOMBRE DEL SOCIO: ", "ERROR! El nombre es muy largo.", 2, 31);

            getSpecificChar(&array[index].sexo, "INGRESE EL SECO DEL SOCIO (F/M): ", "ERROR! Ingreso un caracter no valido.", 'f', 'm');

            do
            {
                getString(&array[index].telefono, "INGRESE EL TELEFONO DEL SOCIO (EJ. 011 6598-6589): ", "ERROR! El numero ingresado es demasido largo", 2, 16);
                phoneOk = isPhoneNumber(array[index].telefono);
            }while(phoneOk != 0);

            getString(&array[index].eMail, "INGRESE EL E-MAIL DEL SOCIO: ", "ERROR! El eMail no es valido.", 1, 31);

            getInt(&array[index].asociado.dia, "INGRESE EL DIA QUE SE ASOCIO: ", "ERROR! El dia no es valido.", 1, 31);

            getInt(&array[index].asociado.mes, "INGRESE EL MES QUE SE ASOCIO: ", "ERROR! El mes no es valido.", 1, 12);

            getInt(&array[index].asociado.anio, "INGRESE EL ANIO QUE SE ASOCIO: ", "ERROR! El anio no es valido.", 1900, 2030);

            printf("\n El registro se realizo con exito.\n\n");
        }
    }
}
//_____________________________________________________________________________________________________________________________________

void modificarSocio(eSocios array[], int size)
{
    int index;
    int id;
    char confirm;

    printf ("\n INGRESE EL ID DEL SOCIO: ");
    scanf ("%d", &id);
    printf("\n");

    index = buscarSocio(array, size, id);

    if (index == -1)
    {
        printf("\n El ID ingresado no existe en el sistema. \n\n");
    }
    else
    {
        do
        {
            printf ("Usted ingreso el ID: %d \n", id);
            getSpecificChar(&confirm, "Confirma la modificacion del registro? (S/N): ", "ERROR! Ingrese 'S' o 'N'.", 's', 'n');
            printf ("\n");

            if (toupper(confirm) == 'N')
            {
                printf ("La modificacion del registro fue cancelada.\n\n");
                break;
            }
            else
            {
                getString(array[index].apellido, "INGRESE EL APELLIDO DEL SOCIO: ", "ERROR! El nombre es muy largo.", 2, 31);
                getString(array[index].nombre, "INGREE EL NOMBRE DEL SOCIO: ", "ERROR! El nombre es muy largo.", 2, 31);
                getSpecificChar(&array[index].sexo, "INGRESE EL SECO DEL SOCIO (F/M): ", "ERROR! Ingreso un caracter no valido.", 'f', 'm');
                getString(&array[index].telefono, "INGRESE EL TELEFONO DEL SOCIO: ", "ERROR! Ingreso un telefono no valido.", 2, 16);
                getString(&array[index].eMail, "INGRESE EL E-MAIL DEL SOCIO: ", "ERROR! El eMail no es valido.", 1, 31);

                printf("\n La modificacion se realizo con exito. \n\n");
            }
        }
        while (toupper(confirm) != 'S');
    }
}
//_____________________________________________________________________________________________________________________________________

void bajaSocio(eSocios array[],int size)
{
    int id;
    int index;
    char confirm;

    printf("INGRESE EL ID DEL SOCIO: ");
    scanf("%d",&id);

    index = buscarSocio(array, size, id);

    if(index == -1)
    {
        printf("\n El registro ingresado no existe en el sistema. \n\n");
    }
    else
    {
        do
        {
            printf("\n Usted ingreso el ID: %d \n",array[index]);
            getSpecificChar(&confirm, "Confirma la modificacion del registro? (S/N): ", "ERROR! Ingrese 'S' o 'N'.", 's', 'n');
            printf ("\n");

            if(toupper(confirm) == 'N')
            {
                printf ("La gestion de baja fue cancelada.\n\n");
                break;
            }
            else
            {
                array[index].state = 0;
                printf("\n Se gestiono la baja del registro correctamente.\n\n");
            }
        }
        while(toupper(confirm) != 'S');
    }
}
//_____________________________________________________________________________________________________________________________________

