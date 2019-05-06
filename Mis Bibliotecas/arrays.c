//LIBRARIES______________________________________________________________________________________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"

//IFNDEF________________________________________________________________________________________________________________________________________________________________________________
#ifndef arrays_H_INCLUDED
#define arrays_H_INCLUDED
#include "arrays.h"
#endif //arrays_H_INCLUDED

//FUNCIONES_______________________________________________________________________________________________________________________________________________________________________________

void intPrint (int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

//________________________________________________________________________________________________________________________________________________________________________________________

void intUpSorting(int array[], int size)
{
    int auxiliary;

    for (int i = 0; i < size ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void intDownSorting(int array[], int size)
{
    int auxiliary;

    for (int i = 0; i < size ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void floatPrint (float array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%.2f ", array[i]);
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void floatUpSorting(float array[], int size)
{
    float auxiliary;

    for (int i = 0; i < size ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void floatDownSorting(float array[], int size)
{
    float auxiliary;

    for (int i = 0; i < size ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void charPrint (char array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%c ", (toupper(array[i])) );
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void charUpSorting(char array[], int size)
{
    char auxiliary;

    for (int i = 0; i < size ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void charDownSorting(char array[], int size)
{
    char auxiliary;

    for (int i = 0; i < size ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void stringPrint (char* array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%s ", array[i]);
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

/*void stringUpSorting (char* array[], int size) //NO FUNCIONA.
{
    char auxiliary[255];

    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if( (stricmp(array[i], array[j])) > 0)
            {
                strcpy(auxiliary, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], auxiliary);
            }
        }
    }
}*/
//________________________________________________________________________________________________________________________________________________________________________________________

