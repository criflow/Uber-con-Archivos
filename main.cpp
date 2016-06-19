#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include "vehiculos.h"
#include "pasajeros.h"
#include "servicios.h"

using namespace std;

void MostrarMenu();

    carro conchos[50] = {
        {"toyota", 2002, "21i", "juan"},
        {"nissan", 2005, "437", "pedro"},
        {"mitsubishi", 2006, "iud", "carlos"},
        {"chevrolet", 2000, "p5l", "angel"},
        {"honda", 1999, "dkj", "sebastian"}};
    int conchosLenght = 5;
    pasajero cliente[50] = {
        {"pablo", 001, "mcdonalds", 8295743644, "claro"},
        {"maria", 002, "banco central", 8094237824, "claro"},
        {"patricia", 003, "hospital", 8095780426, "orange"},
        {"marco", 004, "mercado", 8294287648, "viva"},
        {"carmen", 005, "tienda", 8495230873, "tricom"},
        {"laura", 006, "escuela", 8095832746, "tmobile"}
    };
    int pasajerosLenght = 6;
    Servicio servicios[50] = {
        {"iud", 002, 50, 15, 24, 5, 1993, 4, 5, 30, 7},
        {"dkj", 005, 100, 50, 15, 7, 2000, 10, 25, 22, 10},
        {"p5l", 001, 150, 60, 6, 1, 2002, 15, 48, 50, 18},
        {"2li", 002, 25, 5, 28, 12, 2005, 1, 29, 36, 4},
        {"iud", 003, 500, 350, 16, 9, 2010, 18, 10, 3, 30},
    };
    int serviciosLenght = 5;

int main()
{
    int opcion;

    do{
        MostrarMenu();
        printf("\n\n*Opcion: ");
        cin >> opcion;

        switch(opcion)
        {
            int cant;
            case 1:
                    do
                    {
                    printf("\n*Cuantos vehiculos desea registrar: ");
                    cin >> cant;
                    if(cant<1) printf("ERROR: EL NUMERO DEBE SER MAYOR QUE 0\n");
                    }while(cant<1);
                    fflush(stdin);
                    AgregarCarros(conchos, conchosLenght, cant);
                    conchosLenght+=cant;
                    MostrarCarros(conchos, conchosLenght);
                    break;
            case 2:
                    do
                    {
                    printf("\n*Cuantos pasajeros desea registrar: ");
                    cin >> cant;
                    if(cant<1) printf("ERROR: EL NUMERO DEBE SER MAYOR QUE 0\n");
                    }while(cant<1);
                    fflush(stdin);
                    AgregarPasajeros(cliente, pasajerosLenght, cant);
                    pasajerosLenght+=cant;
                    MostrarPasajeros(cliente, pasajerosLenght);
                    break;
            case 3:
                    do
                    {
                    printf("\n*Cuantos servicios desea registrar: ");
                    cin >> cant;
                    if(cant<1) printf("ERROR: EL NUMERO DEBE SER MAYOR QUE 0\n");
                    }while(cant<1);
                    fflush(stdin);
                    RegistrarServicios(servicios, serviciosLenght, cant, conchos, conchosLenght, cliente, pasajerosLenght);
                    serviciosLenght+=cant;
                    MostrarServicios(servicios, serviciosLenght, conchos, conchosLenght, cliente, pasajerosLenght);
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
    printf("\n\t\t\t\t\t\t\t-------------------");
    printf("\n*Seleccione una de las siguientes opciones:\t\t|# de vehiculos: %d|", conchosLenght);
    printf("\t\t\t\t\t\t\t\t|# de pasajeros: %d|", pasajerosLenght);
    printf("\n1. Registrar uno o mas vehiculos\t\t\t|# de servicios: %d|", serviciosLenght);
    printf("\n2. Registrar uno o mas pasajeros\t\t\t-------------------");
    printf("\n3. Registrar uno o mas servicios");
    printf("\n4. Mostrar pasajeros que han viajado en cierto concho");
    printf("\n5. Mostrar conchos en los cuales ha viajado cierto pasajero");
    printf("\n6. Mostrar los servicios registrados en el sistema");
    printf("\n\n----------------------------------------------------------------------------");
    return;
}
