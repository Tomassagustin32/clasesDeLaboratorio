#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#include "ArrayEmployees.h"
#include "utn.h"

//INICIA EL PROGRAMA

int main()
{

    //DECLARAMOS VARIABLES A USAR

    char seguir= 's';

    eEmployee empleados[MAX];

    initEmployees( empleados, MAX );

    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int lugarLibre;
    int flag=0;

    //MENU DE OPCIONES

    do
    {

        switch(menuDeOpciones())
        {
        //ESPECIFICO CADA CASO
        case 1:
            flag=1;
            lugarLibre=buscarLugarLibre(empleados, MAX);
            if(lugarLibre!= -1)
            {
                printf("Lugares ocupados = %d/1000\n",lugarLibre);
                getValidString("Ingrese nombre: ", "No valido. Ingrese nuevamente: ", name);
                getValidString("Ingrese apellido: ", "No valido. Ingrese nuevamente: ", lastName);
                salary=getValidFloat("Ingrese salario: ","No valido. Ingrese nuevamente \n", 0, 1000000);
                sector=getValidInt("Ingrese sector: ","No valido. Ingrese nuevamente \n", 0, 200);
                addEmployee(empleados, MAX, lugarLibre,  name, lastName, salary, sector);

            }
            else
            {
                printf("Aun no hay datos para mostrar\n");
                system("pause");
                system("cls");
            }

            break;
        case 2:
            if(flag==0)
            {

                printf("Aun no hay datos para mostrar\n");
            }
            else
            {
                modifyEmployee(empleados,MAX, lugarLibre);

            }

            system("pause");
            system("cls");
            break;
        case 3:
            if(flag == 0)
            {
                printf("Aun no hay datos para mostrar\n");
            }
            else
            {
               removeEmployee( empleados, MAX, empleados[MAX].id);
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(flag == 0)
            {
                printf("Aun no hay datos para mostrar\n");
            }
            else
            {
                sortEmployees(empleados, MAX);
            }

            system("pause");
            system("cls");
            break;
        case 5:
            seguir='n';
            break;
        default :
            printf("Error. Dato no valido\n");
            system("pause");
            system("cls");
        }


    }while(seguir == 's');

    return 0;
}
//FIN DEL PROGRAMA
