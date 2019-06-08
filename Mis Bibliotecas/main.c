//LIBRARIES______________________________________________________________________________________________________________________________________________________________________________
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"

//DEFINES________________________________________________________________________________________________________________________________________________________________________________
#define TAM 20
#define TAM_SECTOR 5
#define TAM_MENUES 100
#define TAM_ALMUERZOS 200

//IFNDEF_________________________________________________________________________________________________________________________________________________________________________________

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif //Input_H_INCLUDED

#ifndef arrays_H_INCLUDED
#define arrays_H_INCLUDED
#include "arrays.h"
#endif //arrays_H_INCLUDED

#ifndef employees_H_INCLUDED
#define employees_H_INCLUDED
#include "employees.h"
#endif //employees_H_INCLUDED

#ifndef lunches_H_INCLUDED
#define lunches_H_INCLUDED
#include "lunches.h"
#endif //lunches_H_INCLUDED

//MAIN___________________________________________________________________________________________________________________________________________________________________________________

int main()
{
    //TESTING_INPUT_LIBRARY______________________________________________________________________________________________________________________________________________________________

    /*MENU (INPUT)
    int menuOp;
    menuOp = menu();
    printf("Usted eligio la opcion numero %d", menuOp);*/

    /*GETINT (INPUT)
    int edad;
    getInt(&edad, "Ingrese su edad: ", "La edad que ingreso no es valida.", 18, 100);
    printf("\nSu edad es %d", edad);*/

    /*GETINT TRIES (INPUT)
    int edad;
    getIntTries(&edad, "Ingrese su edad: ", "La edad que ingreso no es valida.", 18, 100, 3);
    printf("\nSu edad es %d.", edad);*/

    /*GETFLOAT (INPUT)
    float sueldo;
    getFloat(&sueldo, "Ingrese el sueldo del empleado: ", "El sueldo no es valido.", 0, 1000000.00);
    printf("El sueldo es: %.2f", sueldo);*/

    /*GETFLOAT TRIES (INPUT)
    float precio;
    getFloatTries(&precio, "Ingrese el precio de su producto: ", "El precio ingresado no es valido.", 1, 100, 3);
    printf("Su precio es: %.2f", precio);*/

    /*GETCHAR (INPUT)
    char letra;
    getChar(&letra, "Ingrese una letra: ", "El caracter ingresado es invalido.", 'a','z');
    printf("Usted eligio: %c", letra);*/

    /*GETSPECIFICCHAR (INPUT)
    char letra;
    getSpecificChar(&letra, "Ingrese una letra: ", "El caracter ingresado es invalido.", 's','n');
    printf("Usted eligio: %c", letra);*/

    /*GETCHAR TRIES (INPUT)
    char letra;
    getCharTries(&letra, "Ingrese una letra: ", "El caracter ingresado es invalido.", 'a', 'z', 3);
    printf("Usted eligio: %c", letra);*/

    /*GETSTRING (INPUT)
    char nombreCompleto[50];
    getString(nombreCompleto, "Ingrese su nombre completo: ", "El nombre ingresado es muy largo.", 5, 49);
    printf("Su nombre es: %s", nombreCompleto);*/

    /*GETSTRING TRIES (INPUT)
    char nombreCompleto[50];
    getStringTries(nombreCompleto, "Ingrese su nombre completo: ", "El nombre ingresado es muy largo.", 5, 25, 3);
    printf("Su nombre es: %s", nombreCompleto);*/

    /*GETDATE (INPUT)
    eDate hoy;
    getDate(hoy, "FECHA DE HOY", 1900, 2030);*/

    //TESTING_ARRAY_LIBRARY______________________________________________________________________________________________________________________________________________________________

    /*INTPRINT
    int numbers[SIZE] = {7, 5, 6, 9, 8};
    intPrint(numbers, SIZE);*/

    /*INT UPSORTING
    int numbers[SIZE] = {7, 5, 6, 9, 8};
    intUpSorting(numbers, SIZE);
    intPrint(numbers, SIZE); */

    /*INT DOWNSORTING
    int numbers[SIZE] = {7, 5, 6, 9, 8};
    intDownSorting(numbers, SIZE);
    intPrint(numbers, SIZE);*/

    /*FLOATPRINT
    float numbers[SIZE] = {7.00, 5.25, 6.35, 9.12, 9.10};
    floatPrint(numbers, SIZE);*/

    /*FLOAT UPSORTING
    float numbers[SIZE] = {7.00, 5.25, 6.35, 9.12, 9.10};
    floatUpSorting(numbers, SIZE);
    floatPrint(numbers, SIZE);*/

    /*FLOAT DOWNSORTING
    float numbers[SIZE] = {7.00, 5.25, 6.35, 9.12, 9.10};
    floatDownSorting(numbers, SIZE);
    floatPrint(numbers, SIZE);*/

    /*CHARPRINT
    char letters[SIZE] = {'l', 'c', 'a', 'o', 'f'};
    charPrint(letters, SIZE);*/

    /*CHAR UPSORTING
    char letters[SIZE] = {'l', 'c', 'a', 'o', 'f'};
    charUpSorting(letters, SIZE);
    charPrint(letters, SIZE);*/

    /*CHAR DOWNSORTING
    char letters[SIZE] = {'l', 'c', 'a', 'o', 'f'};
    charDownSorting(letters, SIZE);
    charPrint(letters, SIZE);*/

    /*STRINGPRINT
    char* names[] = {"juan", "barbi", "mery", "lobito", "anita"};
    stringPrint(names, SIZE);*/

    /*STRING UPSORTING (PENDIENTE)
    char* names[] = {"juan", "barbi", "mery", "lobito", "anita"};
    stringUpSorting(names, 5, 1);
    stringPrint(names, SIZE); */

    //TESTING_EMPLOYEES_LIBRARY__________________________________________________________________________________________________________________________________________________________

   eEmployee lista[TAM]={
        {111,"Juan",'m',30000,{01,02,1999},1,1},
        {222,"Ana",'f',20000,{10,6,1980},3,1},
        {33,"Tom",'m',15000,{10,12,1999},4,1},
        {66,"Julio",'m',10000,{20,04,1972},3,1},
        {55,"Paula",'m',15000,{8,03,1990},5,1},

        };


        eSector sector[TAM_SECTOR]=
    {
        {1,"Sistemas"},
        {2,"RRHH"},
        {3,"Compras"},
        {4,"Ventas"},
        {5,"Legales"},
    };


    char seguir='s';
    char salir;
    char confirmaOrdenar;
    int mostroSector;


    //eEmpleado vecEmpleados[TAM];//creo un vector del tipo eEmpleado para cuando no hardcodee el dato

    //inicializarEstado(vecEmpleados,TAM);//Indica con 0 que la posicion esta vacia




    do
    {
        switch(menu())
        {
            case 1:
                printf("\nALTA EMPLEADO\n");
                registerEmployee(lista,TAM,sector,TAM_SECTOR);
                system("pause");
                break;

            case 2:
                printf("\nBAJA EMPLEADO\n");
                unsubscribeEmployee(lista,TAM);
                system("pause");

                break;

            case 3:
                printf ("Modificar empleado\n");
                modifyRecord(lista,TAM);
                system("pause");
                break;


            case 4:
                 //printf ("Ordenar empleados\n");
                printf ("Estas seguro que quiere ordenar? ingrese s/n:");
                fflush(stdin);
                confirmaOrdenar = getche();
                printf ("\n");
                if (tolower(confirmaOrdenar)=='s')
                {
                    confirmaOrdenar = 'n';
                    sortEmployees(lista,TAM);
                    printf ("Operacion exitosa!\n");
                }
                else
                {
                    printf ("Operacion cancelada!\n");

                }

                system("pause");
                break;

            case 5:
                printf ("Listar empleados\n");
                showEmployees(lista,TAM, sector,TAM_SECTOR);
                system("pause");

                break;

            case 6:
                printf ("Listar empleado con sector\n");
                showSectors(lista,TAM,sector,TAM_SECTOR);
                break;

            case 7:
                printf("Mostrar cantidad de empleados por sector\n");
                employeesBySector(lista,TAM,sector,TAM_SECTOR);

                break;

            case 8:
                printf ("Desea salir? Ingrese s/n: ");
                fflush(stdin);
                salir = getche();
                printf ("\n");
                system("pause");

                if (tolower(salir)=='s')
                {
                    seguir='n';
                }

                system("cls");
                break;
            default:
                printf ("\nNo es una opcion valida\n\n");
                system("break");



        }
    }while(seguir=='s');

    return 0;
}
//FIN_DEL_PROGRAMA________________________________________________________________________________________________________________________________________________________________________







