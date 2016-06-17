#ifndef PASAJEROS_H_INCLUDED
#define PASAJEROS_H_INCLUDED

typedef struct
{
    char nombre[20]; //nombre completo
    int id;
    char lugarDeTrabajo[10];
    int celular;
    char companiaCel[10];
}pasajero;

#endif // PASAJEROS_H_INCLUDED
