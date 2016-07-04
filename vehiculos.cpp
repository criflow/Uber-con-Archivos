#include <iostream>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculos.h"
#include "pasajeros.h"
#include "servicios.h"
#include <fstream>

using namespace std;

carro AgregarCarro()
{
    carro concho;
    ofstream carro ("Vehiculo.txt", ios::app | ios::in | ios::out);
    string getcontent;
    int c, id;
    ifstream cant ("cantidad.txt");
    cant >> id;
    c= id;

    fflush(stdin);
    printf("\n-Nombre del propietario: ");
    cin >> concho.propietario;
    fflush(stdin);
    printf("\n-Ficha del carro: ");
    cin >> concho.ficha;
    fflush(stdin);
    printf("\n-Marca del carro: ");
    cin >> concho.marca;
    fflush(stdin);
    printf("\n-A%co del carro: ", 164);
    scanf("%d", &concho.ano);
    fflush(stdin);

    carro << "-------- Carro #: "<< c+1 <<" --------" << endl
    << "Propietario: " << concho.propietario << endl
    << "Ficha: " << concho.ficha <<endl
    << "Marca: " << concho.marca <<endl
    << "Ano: " << concho.ano <<endl<<endl;;
    ofstream num ("cantidad.txt");
    num << c+1;
    num.close();
    c++;

    return concho;

}
void AgregarCarros(carro conchos[],int tam, int cant)
{
    system("cls");
    fflush(stdin);
    printf("------------------------- Carro/s a agregar --------------------------------");
    for(int i=tam; i<(tam+cant); i++)
    {
        printf("\n*Carro #%d: ", i+1);
        conchos[i] = AgregarCarro();
    }
    return;
}

void MostrarCarros(carro conchos[], int tam)
{
    printf("\n------------------------- Carros --------------------------------");
    string getcontent;
    ifstream carro ("Vehiculo.txt");
     while(getline(carro, getcontent))
        {
                cout << getcontent << endl;
        }
    /*
    for(int i=0; i<tam; i++)
    {
        printf("\n\n*Carro #%d: ", i+1);
        printf("\n-Nombre del propietario: %s", conchos[i].propietario);
        printf("\n-Ficha del carro: %s", conchos[i].ficha);
        printf("\n-Marca del carro: %s", conchos[i].marca);
        printf("\n-A%co del carro: %d", 164, conchos[i].ano);
    }*/
    printf("\n-----------------------------------------------------------------");
    getch();
    return;
}


void MostrarCarro(carro conchos[], int tam, char ficha[])
{
    for(int i=0; i<tam; i++)
    {
        if(strncmp(conchos[i].ficha, ficha, 4)==0)
        {
            printf("\n\n*Carro #%d: ", i+1);
            printf("\n-Nombre del propietario: %s", conchos[i].propietario);
            printf("\n-Ficha del carro: %s", conchos[i].ficha);
            printf("\n-Marca del carro: %s", conchos[i].marca);
            printf("\n-A%co del carro: %d", 164, conchos[i].ano);
            return;
        }
    }
    return;
}

bool BuscarVehiculo(carro conchos[], int tam, char ficha[])
{
    for(int i=0; i<tam; i++)
    {
        if(strncmp(conchos[i].ficha, ficha, 4)==0)
            return true;
    }
    return false;
}
