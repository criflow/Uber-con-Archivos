#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

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
    int minutosDeViaje;
}Servicio;

#endif // SERVICIOS_H_INCLUDED
