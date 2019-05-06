//LIBRARIES______________________________________________________________________________________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"
#include "arrays.h"
#include "employees.h"

//IFNDEF________________________________________________________________________________________________________________________________________________________________________________
#ifndef lunches_H_INCLUDED
#define lunches_H_INCLUDED
#include "lunches.h"
#endif //lunches_H_INCLUDED

//FUNCIONES_______________________________________________________________________________________________________________________________________________________________________________

void lunchMenues()
{
    printf("-MENUES PARA ALMUERZOS-\n");
    printf("1. PIZZA $130.00\n");
    printf("2. ARROZ $55.50\n");
    printf("3. POLLO $140.25\n");
    printf("4. PANCHO $35.75\n");
    printf("5. MILANESA $150.50\n");
    printf("6. RAVIOLES $115.25\n");
    printf("7. PESCADO $70.00\n");
    printf("8. EMPANADAS $30.25\n");
    printf("9. HAMBURGUESA $120.00\n");
    printf("10. ENSALADA $85.25\n");
    printf("11. PAPAS FRITAS $60.50\n");
}
//________________________________________________________________________________________________________________________________________________________________________________________

void initializeLunches(eLunch lunches[], int lunchesSize)
{
    for(int i=0; i < lunchesSize; i++)
    {
        lunches[i].state = 0;
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

int availableLunch(eLunch lunches[], int lunchesSize)
{

    int index = -1;

    for(int i = 0; i < lunchesSize; i++)
    {
        if(lunches[i].state == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}
//________________________________________________________________________________________________________________________________________________________________________________________

int seachLunch(eLunch lunches[], int lunchesSize, int id)
{

    int index = -1;

    for(int i = 0; i < lunchesSize; i++)
    {
        if(lunches[i].state == 1 && lunches[i].menuId == id)
        {
            index = i;
            break;
        }
    }

    return index;
}
//________________________________________________________________________________________________________________________________________________________________________________________

int getLunch(eLunch lunches[],int lunchesSize, eEmployee employed[], int employedSize, eSector sector[],int sectorSize, int fileNumber)
{
    int index;
    int fileNumberAux;
    int option;
    int ok = 0;
    int index2;

    index = availableLunch(lunches,lunchesSize);

    if(index == -1)
    {
        printf("\nNo queda lugar disponible para nuevos registros.\n");
    }
    else
    {
        lunches[index].menuId = fileNumber++;

        showEmployees(employed, employedSize, sector, sectorSize);
        getInt(&fileNumberAux,"\nIngrese el legajo de su empleado: ","ERROR! Ingreso un legajo no valido.",1,200);

        if(employed[fileNumberAux].state != 1)
        {
            printf("\nERROR! El legajo no se encuentra en el sistema\n");
        }
        else
        {
            lunches[index].fileNumber = &fileNumberAux;
            lunchMenues();
            getInt(&option,"Ingrese el menuID de su opcion elegida: ","ERROR! Ingreso un ID no valido.",1,11);
            lunches[index].menuId = &option;
            getInt(&lunches[index].lunchDate.day,"Ingrese el dia del almuerzo: ", "ERROR! El dia ingresado no es valido", 1, 31);
            getInt(&lunches[index].lunchDate.month,"Ingrese el mes del almuerzo: ", "ERROR! El mes ingresado no es valido", 1, 12);
            getInt(&lunches[index].lunchDate.year,"Ingrese el anio del almuerzo: ", "ERROR! El mes ingresado no es valido", 2000, 2030);
            lunches[index].state = 1;

            printf("\nSE REGISTRO EL ALMUERZO CON EXISTO.\n");
            ok = 1;
        }
    }
    return ok;
}
//________________________________________________________________________________________________________________________________________________________________________________________

void showLunch(eLunch lunches)
{
    printf("\n %d\t  %d\t  %d\t  %02d/%o2d/%d\t\ ",lunches.menuId, lunches.fileNumber, lunches.lunchDate.day, lunches.lunchDate.month, lunches.lunchDate.year);
    printf("\n");
}
//________________________________________________________________________________________________________________________________________________________________________________________

void showLunches (eLunch lunches[], int lunchesSize)
{
    int counter = 0;
     printf("\n MENU ID    LEGAJO    FECHA\n");

    for(int i=0; i < lunchesSize; i++)
    {
        if(lunches[i].state == 1)
        {
            showLunch(lunches[i]);
            counter++;
        }
    }

    if(counter == 0)
    {
        printf("\nNO EXISTEN ALMUERZOS REGISTRADOS.\n");
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

int lunchesPayments (eLunch lunches[], int lunchesSize, eMenu menues[], int menuesSize)
{
    float finalPayment = 0;
    int choice;

    for(int i = 0; i < lunchesSize; i++)
    {
        if(lunches[i].state == 1)
        {
            choice = lunches[i].menuId;
            for(int j = 0; j < lunchesSize; j++)
            {
                if(choice == menues[j].id)
                {
                    finalPayment = finalPayment + menues[j].price;
                }
            }
        }
    }
}
