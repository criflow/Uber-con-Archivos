#ifndef VEHICULOS_H_INCLUDED
#define VEHICULOS_H_INCLUDED

typedef struct
{
    char marca[10];
    int ano;
    char ficha[6];
    char propietario[20];
}carro;

carro AgregarCarro();
void AgregarCarros(carro[], int, int);
void MostrarCarros(carro conchos[], int tam);


#endif // VEHICULOS_H_INCLUDED
