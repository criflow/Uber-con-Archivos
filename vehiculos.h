#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED

typedef struct
{
    char marca[20];
    int ano;
    char ficha[4];
    char propietario[20];
}carro;

carro AgregarCarro();
void AgregarCarros(carro[], int, int);
void MostrarCarros(carro [], int );
bool BuscarVehiculo(carro[], int, char[]);


#endif // VEHICULOS_H_INCLUDED
