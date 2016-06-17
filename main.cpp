#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include "vehiculos.h"
#include "pasajeros.h"
#include "servicios.h"

using namespace std;

void MostrarMenu();

int main()
{
    carro conchos[50];
    int conchosLenght = 0;
    int opcion;

    do{
        MostrarMenu();
        printf("\n\n*Opcion: ");
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                    int cant;
                    printf("\n\n*Cuantos vehiculos desea registrar: ");
                    cin >> cant;
                    fflush(stdin);
                    AgregarCarros(conchos, conchosLenght, cant);
                    conchosLenght+=cant;
                    MostrarCarros(conchos, conchosLenght);
                    break;
            case 2:

                    break;
            case 3:

                    break;
            case 4:

                    break;
            case 5:

                    break;
            case 6:

                    break;
            case 7:
                    printf("BYE =P");
                    break;
            default:
                    printf("***ERROR: SELECCIONE UNA OPCION CORRECTA***");
                    getch();
                    break;
        }
    }while(opcion!=7);
}

void MostrarMenu()
{
    system("cls");
    printf("----------------------------------------------------------------------------");
    printf("\n|                    Sistema de Conchado Inteligente                       |");
    printf("\n----------------------------------------------------------------------------");
    printf("\n\n*Seleccione una de las siguientes opciones:");
    printf("\n\n1. Registrar uno o mas vehiculos");
    printf("\n2. Registrar uno o mas pasajeros");
    printf("\n3. Registrar uno o mas servicios");
    printf("\n4. Mostrar pasajeros que han viajado en cierto concho");
    printf("\n5. Mostrar conchos en los cuales ha viajado cierto pasajero");
    printf("\n6. Mostrar los servicios registrados en el sistema");
    printf("\n\n----------------------------------------------------------------------------");
    return;
}
