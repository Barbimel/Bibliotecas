//BIBLIOTECAS__________________________________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//IFNDEF_______________________________________________________________________________________________________________________________

#ifndef books_H_INCLUDED
#define books_H_INCLUDED
#include "books.h"
#endif //prestamos_H_INCLUDED

//FUNCIONES____________________________________________________________________________________________________________________________

void iniciarlibros(eLibros array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].state = 0;
    }
}
//_____________________________________________________________________________________________________________________________________

void listarLibros (eLibros array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("CODIGO AUTOR    CODIGO LIBRO    TITULO \n");
        printf("  %d          %d           %s \n\n", array[i].codigoAutor, array[i].codigoLibro, array[i].titulo);
    }
}
//_____________________________________________________________________________________________________________________________________

int buscarLibro(eLibros array[],int size,int id)
{
    int index = -1;

    for(int i = 0; i < size; i++)
    {
        if(array[i].state == 1 && array[i].codigoLibro == id)
        {
            index = i;
        }
    }
    return index;
}

//_____________________________________________________________________________________________________________________________________

void mostrarLibro(eLibros array[], int size, int id)
{
    printf("Registro encontrado: \n\n");

    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[i].codigoLibro == id)
            {
                printf("  %d       %s       %d      \n\n", array[i].codigoLibro, array[i].titulo, array[i].codigoAutor);
            }
        }
    }
}
//_____________________________________________________________________________________________________________________________________

void mostrarLibros(eLibros array[], int size)
{
    int counter = 0;
    printf("ID LIBRO  TITULO  ID AUTOR  \n");

    for (int i = 0; i < size; i++)
    {
        if (array[i].state == 1)
        {
            mostrarLibro(array, size, array[i].codigoLibro);
            counter++;
        }
    }
    if (counter == 0)
    {
        printf("No hay registros que mostrar.\n\n");
    }
}
//_____________________________________________________________________________________________________________________________________

void ordenarLibros (eLibros array[], int size)
{
    eLibros auxiliary;

    for (int i = 0; i < size-1 ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (stricmp(array[i].titulo, array[j].titulo) > 0)
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }

            if (array[i].codigoLibro > array[j].codigoLibro)
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }

            if (array[i].codigoAutor > array[j].codigoAutor)
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//_____________________________________________________________________________________________________________________________________

