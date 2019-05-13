//LIBRARIES_______________________________________________________________________________________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"

//IFNDEF__________________________________________________________________________________________________________________________________________________________________________________
#ifndef employees_H_INCLUDED
#define employees_H_INCLUDED
#include "employees.h"
#endif //employees_H_INCLUDED

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif //_H_INCLUDED

//FUNCIONES_______________________________________________________________________________________________________________________________________________________________________________

void InitializeStates (eEmployee array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].state = 0;
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void showEmployee(eEmployee array[], int size, int id)
{
    for(int i = 0; i < size-1; i++)
    {
        if(array[i].fileNumber == id)
        {
            printf ("  %d          %s      %s    %.2f     %d \n", array[i].fileNumber, array[i].lastName, array[i].name, array[i].salary, array[i].sectorId);
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void showEmployees (eEmployee array[], int size, eSector sector[], int sectorSize)
{
    int counter = 0;
    printf ("\n Legajo     Apellido     Nombre     Sueldo     Sector\n");

    for (int i = 0; i < size; i++)
    {
        if (array[i].state == 1)
        {
            showEmployee(array, size, array[i].fileNumber);
            counter++;
        }
    }
    if (counter == 0)
    {
        printf("No hay empleados que mostrar.\n\n");
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

int incrementalFileNumber (eEmployee employed[], int size, int* lastRecord)
{
    for (int i = 0; i < size; i++)
    {
        if (employed[i].state == 1 && *lastRecord < employed[i].fileNumber)
        {
            *lastRecord = employed[i].fileNumber;
        }

    }
    return *lastRecord + 1;
}
//________________________________________________________________________________________________________________________________________________________________________________________

int freeState(eEmployee array[],int size)
{
    int free = -1;

    for(int i = 0; i < size; i++)
        {
            if(array[i].state == 0)
                {
                    free = i;
                }
        }
        return free;
}
//________________________________________________________________________________________________________________________________________________________________________________________

int searchEmployee(eEmployee array[], int size, int fileNumber)
{
    int indexFile = -1;

    for(int i = 0; i < size; i++)
        {
            if(array[i].state == 1 && array[i].fileNumber == fileNumber)
                {
                    indexFile = i;
                }
        }
        return indexFile;
}
//________________________________________________________________________________________________________________________________________________________________________________________

void registerEmployee (eEmployee array[], int size, eSector sector[], int sectorSize)
{
    int registered;
    int index;
    int fileNumber;
    char sectorAux[3];

    index = freeState(array, size);

    if(index == -1)
    {
        printf("\nNo queda espacio suficiente para nuevos registros.\n");
    }
    else
    {
        printf("Ingrese el numero de legajo: ");
        scanf("%d",&fileNumber);
        printf("\n");

        registered = searchEmployee(array, size, fileNumber);

        if(registered != -1)
        {
            printf("\n El numero de legago ingresado ya se encuentra registrado: \n");
            printf(" LEGAJO    APELLIDO     NOMBRE     SUELDO    SECTOR\n");
            showEmployee(array, size, fileNumber);
            printf("\n");
        }
        else
        {
            array[index].fileNumber = fileNumber;
            array[index].state = 1;
            getString(array[index].lastName, "Ingrese el apellido de su empleado: ", "ERROR! El apellido es muy largo.", 2, 50);
            getString(array[index].name, "Ingrese el nombre de su empleado: ", "ERROR! El nombre es muy largo.", 2, 50);
            getFloat(&array[index].salary, "Ingrese el sueldo bruto de su empleado: ", "ERROR! Ingreso un importe no valido.", 0, 1000000);
            getInt(&array[index].sectorId, "Ingrese el SectorID de su empleado: ", "ERROR! El ID no es valido.", 1, sectorSize);

            printf("\n EL REGISTRO SE REALIZO CON EXITO.\n\n");
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void unsubscribeEmployee(eEmployee array[],int size)
{
    int fileNumber;
    int indexFile;
    char confirm;

    printf("Ingrese el numero de legajo correspondiente a su empleado: ");
    scanf("%d",&fileNumber);

    indexFile = searchEmployee(array, size, fileNumber);

    if(indexFile == -1)
    {
        printf("\n El numero de legajo ingresado no existe en el sistema. \n\n");
    }
    else
    {
        do
        {
            printf("\n Ingreso el legajo numero: %d \n",array[indexFile]);
            setbuf(stdin, NULL);
            getSpecificChar(&confirm, "Confirma la baja definitiva de su empleado? (S/N)", "ERROR! El caracter ingresado no es valido", 's', 'n');
            printf("\n");
            system("pause");

            if(toupper(confirm) == 'N')
            {
                printf ("Se ha cancelado el proceso de baja en curso.\n\n");
                break;
            }
            else
            {
                array[indexFile].state = 0;
                printf("\n Se ha dado la baja a su empleado correctamnete.\n\n");
            }
        }
        while(toupper(confirm) != 'S');
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void modifyRecord (eEmployee array[], int size, eSector vector[], int vectorSize)
{
    int index;
    int fileNumber;
    char confirm;
    int salary;

    printf ("\n Ingrese el numero de legajo correspondiente a su empleado: ");
    scanf ("%d", &fileNumber);

    index = searchEmployee(array, size, fileNumber);

    if (index == -1)
    {
        printf("\n El numero de legajo ingresado no existe en el sistema. \n\n");
    }
    else
    {
        do
        {
            printf ("Usted ingreso el legajo numero: %d \n", fileNumber);
            setbuf(stdin, NULL);
            getSpecificChar(&confirm, "Confirma la modificacion de este registro? (S/N)", "ERROR! El caracter ingresado no es valido", 's', 'n');
            printf ("\n");
            system("pause");

            if (toupper(confirm) == 'N')
            {
                printf ("Se ha cancelado el proceso de baja en curso.\n\n");
                break;
            }
            else
            {
                getString(array[index].lastName, "Ingrese el apellido de su empleado: ", "ERROR! El apellido es muy largo.", 2, 50);
                getString(array[index].name, "Ingrese el nombre de su empleado: ", "ERROR! El nombre es muy largo.", 2, 50);
                getFloat(&array[index].salary, "Ingrese el sueldo bruto de su empleado: ", "ERROR! Ingreso un importe no valido.", 0, 1000000);
                getInt(&array[index].sectorId, "Ingrese el SectorID de su empleado: ", "ERROR! El ID no es valido.", 1, vectorSize);
                printf ("SE MODIFICO EL REGISTRO CON EXITO.\n\n");
            }

        }while (toupper(confirm) != 'S');
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void sortEmployees (eEmployee array[], int size)
{
    eEmployee auxiliary;

    for (int i = 0; i < size-1 ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (stricmp(array[i].lastName, array[j].lastName) > 0)
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }

            if (array[i].sectorId > array[j].sectorId)
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void getSector(char array[],eSector sector[],int sectorSize,int id)
{
    for(int i = 0; i < sectorSize; i++)
    {
        if(id == sector[i].id)
        {
            strcpy(array, sector[i].description);
            break;
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void showSectors (eEmployee array[], int size, eSector sector[], int sectorSize)
{
    system("cls");

    for (int i = 0; i < sectorSize; i++)
    {
        printf ("Sector: %s\n\n", sector[i].description);
        for (int j = 0; j < size; j++)
        {
            if( (array[j].sectorId == sector[i].id) && array[j].state == 1)
            {
                showEmployee(array, size, array[i].fileNumber);
            }
        }
    }

    printf ("\n\n");
}
//________________________________________________________________________________________________________________________________________________________________________________________

void employeesBySector(eEmployee array[], int size, eSector sector[], int sectorSize)
{
    int counter;
    system("cls");

    for (int i = 0; i < sectorSize; i++)
    {
        printf ("Sector: %s\n\n", sector[i].description);

        for (int j = 0; j < size; j++)
        {
            if( (array[j].sectorId == sector[i].id) && array[j].state == 1)
            {
                counter++;
            }
        }
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void salariesReport(eEmployee array[], int size)
{
    int counter = 0;
    float total = 0;
    float average = 0;
    int aboveAverage = 0;

    for (int i = 0; i < size; i++)
    {
        if(array[i].state == 1)
        {
            counter++;
            total = total + array[i].salary;
            average = total / counter;

            if(array[i].salary > average)
            {
                aboveAverage++;
            }
        }
    }

    if(counter == 0)
    {
        printf("ERROR! No hay empleados activos para calcular informes. \n\n");
    }
    else
    {
        printf("\nINFORME DE SUELDOS:\n");
        printf("El total invertido en salarios es de: $ %.2f \n", total);
        printf("El salario promedio es de: $ %.2f \n", average);
        printf("Un total de %d empleados superan el salario promedio \n\n", aboveAverage);
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________


