#include <iostream>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include "vehiculos.h"
#include "pasajeros.h"
#include "servicios.h"

using namespace std;


Servicio RegistrarServicio(carro conchos[], int conchosTam, pasajero pasajeros[], int pasajerosTam)
{
    Servicio serv;
    fflush(stdin);
    MostrarPasajeros(pasajeros, pasajerosTam);
    do{
    printf("\n-Id del pasajero: ");
    cin >> serv.idPasajero;
    if(BuscarPasajero(pasajeros, pasajerosTam, serv.idPasajero)==false)
        printf("\nERROR: INTRODUZCCA UN ID EXISTENTE");
    }while(BuscarPasajero(pasajeros, pasajerosTam, serv.idPasajero)==false);
    MostrarCarros(conchos, conchosTam);
    do{
    printf("\n-Ficha del carro: ");
    cin >> serv.fichaVehiculo;
        if(BuscarVehiculo(conchos, conchosTam, serv.fichaVehiculo)==false)
            printf("\nERROR: INTRODUZCCA UNA FICHA EXISTENTE");
    }while(BuscarVehiculo(conchos, conchosTam, serv.fichaVehiculo)==false);
    printf("\n-*Fecha: ");
    printf("\n-Dia: ");
    scanf("%d", &serv.fecha.dia);
    fflush(stdin);
    printf("\n-Mes: ");
    scanf("%d", &serv.fecha.mes);
    fflush(stdin);
    printf("\n-A%co: ", 164);
    scanf("%d", &serv.fecha.ano);
    fflush(stdin);
    printf("\n-Hora: ");
    scanf("%d", &serv.fecha.hora);
    fflush(stdin);
    printf("\n-Minuto: ");
    scanf("%d", &serv.fecha.minuto);
    fflush(stdin);
    printf("\n-Segundo: ");
    scanf("%d", &serv.fecha.segundo);
    fflush(stdin);
    printf("\n-Cantidad de minutos que duro el viaje: ");
    scanf("%d", &serv.minutosDeViaje);
    fflush(stdin);
    printf("\n***El viaje fue de %d pesos***", serv.minutosDeViaje*5);
    do
    {
    printf("\n-Monto con que pago: ");
    cin >> serv.pago;
    fflush(stdin);
    if(serv.pago<(serv.minutosDeViaje*5))
        printf("\nERROR: EL MONTO NO ES SUFICIENTE");
    }while(serv.pago<(serv.minutosDeViaje*5));
    serv.devuelta = (serv.pago-(serv.minutosDeViaje*5));
    printf("\n-Su devuelta fue de: %.2f", serv.devuelta);
    getch();
    return serv;
}

void RegistrarServicios(Servicio servs[], int tam, int cant, carro conchos[], int conchosTam, pasajero pasajeros[], int pasajerosTam)
{
    system("cls");
    printf("------------------------- Servicio/s a agregar --------------------------------");
    for(int i=tam; i<(tam+cant); i++)
    {
        printf("\n*Servicio #%d: \n", i+1);
        servs[i] = RegistrarServicio(conchos, conchosTam, pasajeros, pasajerosTam);
    }
}

void MostrarServicios(Servicio servs[], int tam, carro conchos[], int conchosTam, pasajero pasajeros[], int pasajerosTam)
{
    printf("\n------------------------ Servicios ------------------------------");
    for(int i=0; i<tam; i++)
    {
        printf("\n*Servicio #%d: ", i+1);
        printf("\n-Id del pasajero: %d", servs[i].idPasajero);
        printf("\n-Ficha del carro: %s", servs[i].fichaVehiculo);
        printf("\n-Fecha: %d/%d/%d", servs[i].fecha.dia, servs[i].fecha.mes, servs[i].fecha.ano);
        printf("\n-Hora: %d:%d y %d segundos", servs[i].fecha.hora, servs[i].fecha.minuto, servs[i].fecha.segundo);
        printf("\n-Cantidad de minutos que duro el viaje: %d", servs[i].minutosDeViaje);
        printf("\n-Monto con que pago: %.2f", servs[i].pago);
        printf("\n-Devuelta: %.2f\n", servs[i].devuelta);
    }
    printf("\n-----------------------------------------------------------------");
    getch();
    return;
}
