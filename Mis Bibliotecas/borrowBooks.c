//BIBLIOTECAS__________________________________________________________________________________________________________________________
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

void iniciarPrestamos(ePrestamos array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].state = 0;
    }
}
//_____________________________________________________________________________________________________________________________________

int buscarPrestamo(ePrestamos array[],int size,int id)
{
    int index = -1;

    for(int i = 0; i < size; i++)
    {
        if(array[i].state == 1 && array[i].prestamoId == id)
        {
            index = i;
        }
    }
    return index;
}
//_____________________________________________________________________________________________________________________________________

void mostrarPrestamo (ePrestamos array[], int size, int id)
{
    printf("Registro encontrado: \n\n");
    printf ("ID PRESTAMO   ID LIBRO   ID SOCIO    FECHA\n");

    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[i].prestamoId == id)
            {
                printf ("   %d   %d    %d    %d/%d/%d \n", array[i].prestamoId, array[i].libroId, array[i].socioId, array[i].prestamo.dia, array[i].prestamo.mes, array[i].prestamo.anio);
            }
        }
    }
}
//_____________________________________________________________________________________________________________________________________

void mostrarPrestamos (ePrestamos array[], int size)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i].state == 1)
        {
            mostrarPrestamo(array, size, array[i].prestamoId);
            counter++;
        }
    }
    if (counter == 0)
    {
        printf("No hay registros que mostrar.\n\n");
    }
}

//_____________________________________________________________________________________________________________________________________

int prestamosLibres(ePrestamos array[],int size)
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

void altaPrestamo(ePrestamos array[], int size)
{
    int registered;
    int index;
    int id;

    index = prestamosLibres(array, size);

    if(index == -1)
    {
        printf("No hay espacio para nuevos registros.\n\n");
    }
    else
    {
        printf("INGRESE EL ID DEL PRESTAMO: ");
        scanf("%d",&id);
        printf("\n");

        registered = buscarPrestamo(array, size, id);

        if(registered != -1)
        {
            printf("El registro ingresado ya existe: \n\n");
            printf("ID PRESTAMO   ID LIBRO   ID SOCIO    FECHA\n");
            mostrarPrestamo(array, size, id);
            printf("\n\n");
        }
        else
        {
            array[index].state = 1;
            array[index].prestamoId = id;

            getInt(&array[index].libroId, "\nINGRESE EL ID DEL LIBRO PRESTADO: ", "ERROR! EL ID NO ES VALIDO. \n", 1000, 1009);
            getInt(&array[index].socioId, "\nINGRESE EL ID DEL SOCIO: ", "ERROR! EL ID NO ES VALIDO. \n", 1, 200);
            getInt(&array[index].prestamo.dia, "\nINGRESE EL DIA DEL PRESTAMO: ", "ERROR! El dia no es valido. \n", 1, 31);
            getInt(&array[index].prestamo.mes, "\nINGRESE EL MES DEL PRESTAMO: ", "ERROR! El mes no es valido. \n", 1, 12);
            getInt(&array[index].prestamo.anio, "\nINGRESE EL AÑO DEL PRESTAMO: ", "ERROR! El anio no es valido. \n", 1940, 2030);

            printf("\n El registro se realizo con exito. \n\n");
        }
    }
}
//_____________________________________________________________________________________________________________________________________

void modificarPrestamo(ePrestamos array[], int size)
{
    int index;
    int id;
    char confirm;

    printf ("\n INGRESE EL ID DEL PRESTAMO: ");
    scanf ("%d", &id);
    printf("\n");

    index = buscarPrestamo(array, size, id);

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
                getInt(&array[index].libroId, "\nINGRESE EL ID DEL LIBRO PRESTADO: ", "ERROR! EL ID NO ES VALIDO. \n", 1000, 1009);
                //BUSCAR LIBRO
                getInt(&array[index].socioId, "\nINGRESE EL ID DEl SOCIO: ", "ERROR! EL ID NO ES VALIDO. \n", 1, 200);
                //BUSCAR SOCIO
                getInt(&array[index].prestamo.dia, "\nINGRESE EL DIA DEL PRESTAMO: ", "ERROR! El dia no es valido. \n", 1, 31);
                getInt(&array[index].prestamo.mes, "\nINGRESE EL MES DEL PRESTAMO: ", "ERROR! El mes no es valido. \n", 1, 12);
                getInt(&array[index].prestamo.anio, "\nINGRESE EL AÑO DEL PRESTAMO: ", "ERROR! El anio no es valido. \n", 1940, 2030);

                printf("\n La modificacion se realizo con exito. \n\n");
            }
        }
        while (toupper(confirm) != 'S');
    }
}
//_____________________________________________________________________________________________________________________________________

void bajaPrestamo(ePrestamos array[],int size)
{
    int id;
    int index;
    char confirm;

    printf("INGRESE EL ID DEL PRESTAMO: ");
    scanf("%d",&id);

    index = buscarPrestamo(array, size, id);

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

void PrestamosXSocio(eSocios array[], int size, ePrestamos vector[],int vectorSize)
{
    int counter = 0;
    int id;
    int index;

    getInt(&id, "\nINGRESE EL ID DEL SOCIO: ", "ERROR! El codigo ingresado no es valido.",0,200);
    index = buscarSocio(array, size, id);

    if(array[index].state != 1)
    {
        printf("\n]ERROR! El ID ingresado no existe.\n");
    }
    else
    {
        printf("\n ID PRESTAMO    ID SOCIO      ID LIBRO      FECHA PRESTAMO\n");

        for(int i = 0; i < vectorSize; i++)
        {
            if(vector[i].state == 1 && vector[i].socioId == id)
            {
                mostrarPrestamo(vector, size, vector[i].prestamoId);
                counter++;
            }
        }
        printf("SU SOCIO TIENE %d PRESTAMOS ACTIVOS.", counter);
    }

    if(counter == 0)
    {
        printf("\nSU SOCION NO TIENE PRESTAMOS ACTIVOS.");
    }
}
//_____________________________________________________________________________________________________________________________________

void prestamosXSocios(ePrestamos array[], int size, eSocios vector[], int vectorSize)
{
    int counter;
    system("cls");

    for (int i = 0; i < vectorSize; i++)
    {
        printf("ID PRESTAMO    ID LIBRO       FECHA RETIRO:");
        printf ("   %d    %d     %02d/&02d/%2 \n\n", array[i].prestamoId, array[i].libroId, array[i].prestamo.dia, array[i].prestamo.mes, array[i].prestamo.anio);

        for (int j = 0; j < size; j++)
        {
            if( (array[j].prestamoId == vector[i].socioId) && array[j].state == 1)
            {
                counter++;
            }
        }
    }
}
//_____________________________________________________________________________________________________________________________________

void prestamosXLibro(eLibros array[], int size, ePrestamos vector[],int vectorSize)
{
    int counter = 0;
    int id;
    int index;

    getInt(&id,"\nINGRESE EL ID DEL LIBRO:","ERROR! el codigo ingresado no es valido.",1000, 1009);
    index = buscarLibro(array,size,id);

    if(array[index].state != 1)
    {
        printf("\nERROR! El ID ingresado no existe.\n");
    }
    else
    {
        printf("\n ID PRESTAMO  ID SOCIO  ID LIBRO  FECHA PRESTAMO \n");

        for(int i = 0; i < vectorSize; i++)
        {
            if(vector[i].state == 1 && vector[i].libroId == id)
            {
                mostrarPrestamo(vector, size, i);
                counter++;
            }

        }
        printf("EL LIBRO TIENE %d PRESTAMOS: ", counter);
    }

    if(counter == 0)
    {
        printf("\nEL LIBRO NO REGISTRA PRESTAMOS");
    }
}
//_____________________________________________________________________________________________________________________________________

