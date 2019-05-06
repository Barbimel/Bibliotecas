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

//FUNCIONES_______________________________________________________________________________________________________________________________________________________________________________

void InitializeStates (eEmployee array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].state = 0;
    }
}
//________________________________________________________________________________________________________________________________________________________________________________________

void showEmployee (eEmployee employed, eSector sector[], int sectorSize)
{
    char sectorName[20];
    getSector(sectorName, sector, sectorSize, employed.sectorId);
    printf ("   %d       %s       %c       %.2f   %.02d/%d/%d   %s\n", employed.fileNumber, employed.fullName, employed.sex, employed.salary, employed.birth.day, employed.birth.month, employed.birth.year, sectorName);
}
//________________________________________________________________________________________________________________________________________________________________________________________

void showEmployees (eEmployee array[],int size,eSector sector[],int sectorSize)
{
    int counter = 0;
    printf ("\n Legajo     Nombre      Sexo     Sueldo     Nacimiento     Sector\n");

    for (int i = 0; i < size; i++)
    {
        if (array[i].state == 1)
        {
            showEmployee(array[i], sector, sectorSize);
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

int searchEmployee(eEmployee array[],int size,int fileNumber)
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
    eDate birth;

    index = freeState(array, size);

    if(index == -1)
    {
        printf("\nNo queda espacio suficiente para nuevos registros.\n");
    }
    else
    {
        printf("Ingrese el numero de legajo: ");
        scanf("%d",&fileNumber);
        printf("\n\n");

        registered = searchEmployee(array, size, fileNumber);

        if(registered != -1)
        {
            printf("\n El numero de legago ingresado ya se encuentra registrado: \n");
            printf(" LEGAJO      NOMBRE    SEXO      SUELDO       NACIMIENTO\n");
            showEmployee(array[registered], sector, sectorSize);
            printf("\n");
        }
        else
        {
            array[index].fileNumber = fileNumber;
            getString(array[index].fullName, "Ingrese el nombre completo de su empleado: ", "ERROR! El nombre es muy largo.", 2, 50);
            getSpecificChar(&array[index].sex, "Ingrese el sexo de su empleado (F/M): ", "ERROR! Ingreso un caracter no valido.", 'f', 'm');
            getFloat(&array[index].salary, "Ingrese el sueldo bruto de su empleado: ", "ERROR! Ingreso un importe no valido.", 0, 1000000);
            getInt(&array[index].birth.day, "Ingrese el dia de nacimiento de su empleado: ", "ERROR! El dia no es valido.", 1, 31);
            getInt(&array[index].birth.month, "Ingrese el mes de nacimiento de su empleado: ", "ERROR! El mes no es valido.", 1, 12);
            getInt(&array[index].birth.year, "Ingrese el anio de nacimiento de su empleado: ", "ERROR! El anio no es valido.", 1940, 2019);
            getInt(&array[index].sectorId, "Ingrese el SectorID de su empleado: ", "ERROR! El ID no es valido.", 1, 5);
            array[index].state = 1;
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
            printf("confirma la baja definitiva de su empleado? (S/N): ");
            setbuf(stdin, NULL);
            confirm = getche();
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

void modifyRecord (eEmployee array[], int size)
{
    int indexFile;
    int fileNumber;
    char confirm;
    int salary;

    printf ("\n Ingrese el numero de legajo correspondiente a su empleado: ");
    scanf ("%d", &fileNumber);

    indexFile = searchEmployee(array, size, fileNumber);

    if (indexFile == -1)
    {
        printf("\n El numero de legajo ingresado no existe en el sistema. \n\n");
    }
    else
    {
        do
        {
            printf ("Usted ingreso el legajo numero: %d \n", fileNumber);
            printf ("Confirma que desea modificar el registro de su empleado? (S/N): \n");
            setbuf(stdin, NULL);
            confirm = getche();
            printf ("\n");
            system("pause");

            if (toupper(confirm) == 'N')
            {
                printf ("Se ha cancelado el proceso de baja en curso.\n\n");
                break;
            }
            else
            {
                getFloat(&array[indexFile].salary, "Ingrese el nuevo sueldo bruto de su empleado: ", "ERROR! Ingreso un importe no valido.", 0, 1000000);
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
            if (stricmp(array[i].fullName, array[j].fullName) > 0)
            {
                auxiliary = array[i];
                array[i] = array[j];
                array[j] = auxiliary;
            }

            if (array[i].salary > array[j].salary)
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
            if( (array[j].sectorId == sector[i].id) && array[j].state == 1) //CUAL ES EL ERROR?
            {
                showEmployee(array[j], sector, sectorSize);
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

/*int employeesDates (eEmployee array[], char* typeDate, int minYear, int maxYear) //NO FUNCIONA.
{
    int ok;
    char confirm;

    printf("-");
    printf(typeDate);
    printf("-\n");
    getInt(&array.birth.year, "Ingrese el numero de anio: ", "ERROR! El anio ingresado no es valido. \n\n", minYear, maxYear);
    getInt(&array.birth.month, "Ingrese el numero de mes: ", "ERROR! Hay 12 meses en el calendario.\n\n", 1, 12);

    switch(array.birth.month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                getInt(&array.birth.day, "Ingrese el numero de dia: ", "ERRRO! El mes tiene 31 dias.\n\n", 1, 31);
                break;
        case 4:
        case 6:
        case 9:
        case 11:
                getInt(&array.birth.day, "Ingrese el numero de dia: ", "ERROR! El mes tiene 30 dias. \n\n", 1, 30);
                break;
        default:
                getInt(&array.birth.day "Ingrese el numero de dia: ", "ERROR! El mes tiene 28 dias. \n\n", 1, 28);
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
}*/
