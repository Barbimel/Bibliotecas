//BIBLIOTECAS__________________________________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//IFNDEF_______________________________________________________________________________________________________________________________

#ifndef authors_H_INCLUDED
#define authors_H_INCLUDED
#include "authors.h"
#endif // authors_H_INCLUDED

#ifndef books_H_INCLUDED
#define books_H_INCLUDED
#include "books.h"
#endif // prestamos_H_INCLUDED

//FUNCIONES____________________________________________________________________________________________________________________________

void initializeAutores(eAutores array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].state = 0;
    }
}
//_____________________________________________________________________________________________________________________________________

void ordenarAutores(eAutores array[], int size)
{
    eAutores auxiliary;

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

void listarAutores (eAutores array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("CODIGO AUTOR    APELLIDO     NOMBRE \n");
        printf("   %d     %s    %s \n\n", array[i].codigoAutor, array[i].apellido, array[i].nombre);
    }
}
//_____________________________________________________________________________________________________________________________________

int buscarAutor(eAutores array[],int size,int id)
{
    int index = -1;

    for(int i = 0; i < size; i++)
    {
        if(array[i].state == 1 && array[i].codigoAutor == id)
        {
            index = i;
        }
    }
    return index;
}
//_____________________________________________________________________________________________________________________________________

void mostrarAutor(eAutores array[], int size, int id)
{
    printf("Registro encontrado: \n\n");
    printf("ID AUTOR  APELLIDO  NOMBRE  \n");
    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[i].codigoAutor == id)
            {
                printf("  %d       %s       %d      \n\n", array[i].codigoAutor, array[i].apellido, array[i].nombre);
            }
        }
    }
}
//_____________________________________________________________________________________________________________________________________

void mostrarAutores(eAutores array[], int size)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i].state == 1)
        {
            mostrarAutor(array, size, array[i].codigoAutor);
            counter++;
        }
    }
    if (counter == 0)
    {
        printf("No hay registros que mostrar.\n\n");
    }
}
//_____________________________________________________________________________________________________________________________________


void registroAutores(eAutores array[], int size, eLibros vector[], int vectorSize)
{
    int counter;

    for(int i = 0; i < size; i++)
    {
        counter = 0;
        printf("%s   %s\n----------\n", array[i].apellido, array[i].nombre);
        for(int j = 0; j < vectorSize; j++ )
        {
            if(vector[j].codigoAutor == array[i].codigoAutor && vector[j].state == 1)
            {
                counter++;
            }
        }
        printf("%d LIBROS.", counter);

        printf("\n\n");
    }
}
//_____________________________________________________________________________________________________________________________________

void AutorMasLibros (eAutores array[], int size, eLibros vector[], int vectorSize)
{
    int counter = 0;
    int max;
    int flag = 0;
    int maxId;
    char author[31];

    for (int i = 0; i < vectorSize; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i].codigoAutor == vector[j].codigoAutor)
            {
                counter++;

                if (counter > max || flag == 0)
                {
                    max = counter;
                    maxId = array[i].codigoAutor;
                    strcpy(author, array[i].apellido);
                    flag++;
                }
            }
        }
    }
    if (max > 0)
    {
        printf("\nEL AUTOR QUE REGISTRA MAS LIBROS ES %s, CON %d LIBROS. (ID AUTOR: %d).\n", author, max, maxId);
    }
    else
    {
        printf("\nNo hay registros que mostrar.\n\n");
    }

}
//_____________________________________________________________________________________________________________________________________

