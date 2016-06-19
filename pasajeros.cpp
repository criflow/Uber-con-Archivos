#include <iostream>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include "vehiculos.h"
#include "pasajeros.h"
#include "servicios.h"
#include "vehiculos.h"
#include "pasajeros.h"
#include "servicios.h"

using namespace std;

pasajero Agregarpasajero()
{
    pasajero cliente;
    fflush(stdin);
    printf("\n-Nombre del pasajero: ");
    cin >> cliente.nombre;
    fflush(stdin);
    printf("\n-Lugar de trabajo del pasajero: ");
    cin >> cliente.lugarDeTrabajo;
    fflush(stdin);
    printf("\n-Numero de celular del pasajero: ");
    scanf("%lf", &cliente.celular);
    fflush(stdin);
    printf("\n-Compania de celular del pasajero: ");
    cin >> cliente.companiaCel;
    fflush(stdin);
    printf("\n-Id del pasajero: ");
    scanf("%d", &cliente.id);
    fflush(stdin);

    return cliente;

}
void AgregarPasajeros(pasajero clientes[],int tam, int cant)
{
    system("cls");
    fflush(stdin);
    printf("------------------------- pasajero/s a agregar --------------------------------");
    for(int i=tam; i<(tam+cant); i++)
    {
        printf("\n*pasajero #%d: ", i+1);
        clientes[i] = Agregarpasajero();
    }
    return;
}

void MostrarPasajeros(pasajero clientes[], int tam)
{
    printf("------------------------- pasajeros --------------------------------");
    for(int i=0; i<tam; i++)
    {
        printf("\n\n*pasajero #%d: ", i+1);
        printf("\n-Nombre del pasajero: %s", clientes[i].nombre);
        printf("\n-Lugar de Trabajo del pasajero: %s", clientes[i].lugarDeTrabajo);
        printf("\n-Numero celular del pasajero: %10.0lf", clientes[i].celular);
        printf("\n-Compania de celular del pasajero: %s", clientes[i].companiaCel);
        printf("\n-Id del pasajero: %d", clientes[i].id);
    }
    printf("\n-----------------------------------------------------------------");
    getch();
    return;
}

bool BuscarPasajero(pasajero pasajeros[], int tam, int id)
{
    for(int i=0; i<tam; i++)
    {
        if(pasajeros[i].id == id)
            return true;
    }
    return false;
}
