#include <iostream>
#include <cstdio>
//pepito
using namespace std;

typedef struct
{
    string marca;
    int ano;
    char ficha[6];
    string propietario;
}carro;

typedef struct
{
    string nombre; //nombre completo
    int id;
    string lugarDeTrabajo;
    int celular;
    string companiaCel;
}pasajero;

typedef struct
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
}tiempo;

typedef struct
{
    char fichaVehiculo[6];
    int idPasajero;
    float pago;
    float devuelta;
    tiempo fecha;
}transportePrestado;

int main()
{
    printf("----------------------------------------------------------------------------");
    printf("\n|                    Sistema de Conchado Inteligente                       |");
    printf("\n----------------------------------------------------------------------------");
    printf("\n\n*Seleccione una de las siguientes opciones:");
    printf("\n\n1. Solicitar un concho");
    printf("\n2. Solicitar un vehiculo prestado");
    printf("\n3. Registrar un vehiculo");
    printf("\n4. Registrar un pasajero");
    printf("\n5. Mostrar pasajeros que han viajado en cierto concho");
    printf("\n6. Mostrar conchos en los cuales ha viajado cierto pasajero");
    printf("\n\n----------------------------------------------------------------------------");
}
