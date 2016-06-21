#include <iostream>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculos.h"
#include "pasajeros.h"
#include "servicios.h"
#include "filtrado.h"

using namespace std;


void MostrarCarrosFiltrado(carro conchos[], int conchosTam, pasajero pasajeros[], int pasajerosTam, Servicio servs[], int ServiciosTam)
{
    char filtros;
    int id = -1;
    int anoCarro1=0, anoCarro2=0;
    char marca[20] = {'0'}, propietario[20] = {'0'};
    float pago1 = 0, pago2 = 0;
    int dia1, mes1, ano1 = -1, hora1, min1, seg1, dia2, mes2, ano2 = -2, hora2, min2, seg2;
    MostrarPasajeros(pasajeros, pasajerosTam);
    do{
        printf("\n-Id del pasajero: ");
        cin >> id;
        if(BuscarPasajero(pasajeros, pasajerosTam,id)==false)
            printf("\nERROR: INTRODUZCCA UN ID EXISTENTE");
    }while(BuscarPasajero(pasajeros, pasajerosTam,id)==false);
    do{
    printf("\n-Desea agregar filtros? (s/n): ");
    cin >> filtros;
        if(filtros!='s' && filtros!='n')
            printf("\nERROR: OPCIONES VALIDAS: s/n");
    }while(filtros!='s' && filtros!='n');
    if(filtros == 'n')
    {
        printf("--------- Carros en los que se ha montado el pasajero %d-----------", id);
        for(int i=0; i<ServiciosTam; i++)
        {
            if(servs[i].idPasajero == id)
                MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);
        }
        printf("\n-----------------------------------------------------------------");
        getch();
        return;
    }
    printf("\n-Introduzca los siguientes filtros o presione backspace para ignorar:");
    printf("\n*Desea agregar un rango del a%co del modelo del vehiculo?  ", 164);
    if(getche() != 8)
    {
        fflush(stdin);
        printf("\n-Minimo: ");
        cin >> anoCarro1;
        do{
        printf("-Maximo: ");
        cin >> anoCarro2;
        if(anoCarro2<anoCarro1 || anoCarro2 == anoCarro1)
            printf("\nERROR: EL MAXIMO DEBE SER MAYOR QUE EL MINIMO\n");
        }while(anoCarro2<anoCarro1 || anoCarro2 == anoCarro1);
    }else
        printf("***ignorar***");

    printf("\n\n*Desea agregar la marca del carro?  ");
    if(getche() != 8)
    {
        printf("\n-Marca: ");
        cin >> marca;
    }
    else
        printf("***ignorar***");

        printf("\n*Desea agregar un rango del monto con que pago?  ");
    if(getche() != 8)
    {
        fflush(stdin);
        printf("\n-Minimo: ");
        cin >> pago1;
        do{
        printf("-Maximo: ");
        cin >> pago2;
        if(pago2<pago1 || pago2 == pago1)
            printf("\nERROR: EL MAXIMO DEBE SER MAYOR QUE EL MINIMO\n");
        }while(pago2<pago1 || pago2 == pago1);
    }
    else
        printf("***ignorar***");

    printf("\n\n*Desea agregar el nombre de propietario?  ");
    if(getche() != 8)
    {
        printf("\n-Propietario: ");
        cin >> propietario;
    }
    else
        printf("***ignorar***");

    printf("\n*Desea agregar un rango de la fecha y hora del servicio?  ");
    if(getche() != 8)
    {
        fflush(stdin);
        printf("\n-Fecha Minima: ");
        printf("\n-Dia: ");
        cin >> dia1;
        printf("-Mes: ");
        cin >> mes1;
        printf("-Ano: ");
        cin >> ano1;
        printf("-Hora: ");
        cin >> hora1;
        printf("-Minuto: ");
        cin >> min1;
        printf("-Segundo: ");
        cin >> seg1;
        printf("\n-Fecha maxima: ");
        printf("\n-Dia: ");
        cin >> dia2;
        printf("-Mes: ");
        cin >> mes2;
        printf("-Ano: ");
        cin >> ano2;
        printf("-Hora: ");
        cin >> hora2;
        printf("-Minuto: ");
        cin >> min2;
        printf("-Segundo: ");
        cin >> seg2;
    }
    else
        printf("***ignorar***");

    for(int i=0; i<ServiciosTam; i++)
        {
            if(servs[i].idPasajero == id)
                {
                    for(int j=0; j<conchosTam; j++)
                        {
                            if(strncmp(servs[i].fichaVehiculo, conchos[j].ficha, 4)==0)
                                {
                                    if(anoCarro1!=anoCarro2 && (conchos[j].ano<anoCarro1 || conchos[j].ano>anoCarro2))
                                    break;
                                        else if(marca[0] != '0' && strncmp(conchos[j].marca, marca, 20)!=0)
                                            break;
                                                else if(pago1!=pago2 && (servs[i].pago<pago1 || servs[i].pago>pago2))
                                                    break;
                                                        else if(propietario[0] != '0' && strncmp(conchos[j].propietario, propietario, 20)!=0)
                                                            break;
                                                                else if(ano1>0 && ano2>0){
                                                                        if(ano1!=ano2 && (servs[i].fecha.ano>=ano1 && servs[i].fecha.ano<=ano2))
                                                                            MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);
                                                                        else if(ano1==ano2 && servs[i].fecha.ano == ano1 && (servs[i].fecha.mes>=mes1 && servs[i].fecha.mes<=mes2))
                                                                            MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);
                                                                        else if(mes1==mes2 && servs[i].fecha.mes == mes1 && (servs[i].fecha.dia>=dia1 && servs[i].fecha.dia<=dia2))
                                                                            MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);
                                                                        else if(dia1==dia2 && servs[i].fecha.dia == dia1 && (servs[i].fecha.hora>=hora1 && servs[i].fecha.hora<=hora2))
                                                                            MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);
                                                                        else if(min1==min2 && servs[i].fecha.minuto == min1 && (servs[i].fecha.minuto>=min1 && servs[i].fecha.minuto<=min2))
                                                                            MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);
                                                                        else if(servs[i].fecha.segundo>=seg1 && servs[i].fecha.segundo<=seg2)
                                                                                MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);
                                                                }else MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);

                                }
                        }
                }
        }
    getch();
    return;
}

void MostrarPasajerosFiltrado(carro conchos[], int conchosTam, pasajero pasajeros[], int pasajerosTam, Servicio servs[], int ServiciosTam)
{
    char filtros;
    char ficha[4], trabajo[20] = {'0'};
    double cell = 0;
    int tiempo1 = 0, tiempo2 = 0;
    float pago1 = 0, pago2 = 0, total1 = 0, total2 = 0;
    int dia1, mes1, ano1 = -1, hora1, min1, seg1, dia2, mes2, ano2 = -2, hora2, min2, seg2;

    MostrarCarros(conchos, conchosTam);
    do{
    printf("\n-Ficha del carro: ");
    cin >> ficha;
    if(BuscarVehiculo(conchos, conchosTam, ficha)==false)
        printf("\nERROR: INTRODUZCCA UNA FICHA EXISTENTE");
    }while(BuscarVehiculo(conchos, conchosTam, ficha)==false);
    do{
    printf("\n-Desea agregar filtros? (s/n): ");
    cin >> filtros;
        if(filtros!='s' && filtros!='n')
            printf("\nERROR: OPCIONES VALIDAS: s/n");
    }while(filtros!='s' && filtros!='n');
    if(filtros == 'n')
    {
        printf("----------- pasajeros que vieajaron en el carro %s------------", ficha);
        for(int i=0; i<ServiciosTam; i++)
        {
            if(strncmp(servs[i].fichaVehiculo, ficha, 4)==0)
                MostrarPasajero(pasajeros, pasajerosTam, servs[i].idPasajero);
        }
        printf("\n-----------------------------------------------------------------");
        getch();
        return;
    }
    printf("\n-Introduzca los siguientes filtros o presione backspace para ignorar:");
    printf("\n\n*Desea agregar un lugar de trabajo?  ");
    if(getche() != 8)
    {
        printf("\n-Trabajo: ");
        cin >> trabajo;
    }
    else
        printf("***ignorar***");

    printf("\n*Desea agregar un numero de celular?  ");
    if(getche() != 8)
    {
        printf("\n-celular: ");
        cin >> cell;
    }
    else
        printf("***ignorar***");

    printf("\n*Desea agregar un rango de tiempo de viaje?  ");
    if(getche() != 8)
    {
        fflush(stdin);
        printf("\n-Minimo: ");
        cin >> tiempo1;
        do{
        printf("-Maximo: ");
        cin >> tiempo2;
        if(tiempo2<tiempo1 || tiempo2 == tiempo1)
            printf("\nERROR: EL MAXIMO DEBE SER MAYOR QUE EL MINIMO\n");
        }while(tiempo2<tiempo1 || tiempo2 == tiempo1);
    }
    else
        printf("***ignorar***");

    printf("\n*Desea agregar un rango del monto con que pago?  ");
    if(getche() != 8)
    {
        fflush(stdin);
        printf("\n-Minimo: ");
        cin >> pago1;
        do{
        printf("-Maximo: ");
        cin >> pago2;
        if(pago2<pago1 || pago2 == pago1)
            printf("\nERROR: EL MAXIMO DEBE SER MAYOR QUE EL MINIMO\n");
        }while(pago2<pago1 || pago2 == pago1);
    }
    else
        printf("***ignorar***");

    printf("\n*Desea agregar un rango del monto total del servicio?  ");
    if(getche() != 8)
    {
        fflush(stdin);
        printf("\n-Minimo: ");
        cin >> total1;
        do{
        printf("-Maximo: ");
        cin >> total2;
        if(total2<total1 || total2 == total1)
            printf("\nERROR: EL MAXIMO DEBE SER MAYOR QUE EL MINIMO\n");
        }while(total2<total1 || total2 == total1);
    }
    else
        printf("***ignorar***");

    printf("\n*Desea agregar un rango de la fecha y hora del servicio?  ");
    if(getche() != 8)
    {
        fflush(stdin);
        printf("\n-Fecha Minima: ");
        printf("\n-Dia: ");
        cin >> dia1;
        printf("-Mes: ");
        cin >> mes1;
        printf("-Ano: ");
        cin >> ano1;
        printf("-Hora: ");
        cin >> hora1;
        printf("-Minuto: ");
        cin >> min1;
        printf("-Segundo: ");
        cin >> seg1;
        printf("\n-Fecha maxima: ");
        printf("\n-Dia: ");
        cin >> dia2;
        printf("-Mes: ");
        cin >> mes2;
        printf("-Ano: ");
        cin >> ano2;
        printf("-Hora: ");
        cin >> hora2;
        printf("-Minuto: ");
        cin >> min2;
        printf("-Segundo: ");
        cin >> seg2;
}
    else
        printf("***ignorar***");

        for(int i=0; i<ServiciosTam; i++)
        {
            if(strncmp(servs[i].fichaVehiculo, ficha, 4)==0)
                {
                    for(int j=0; j<pasajerosTam; j++)
                    {
                        if(pasajeros[j].id == servs[i].idPasajero)
                        {
                            if(trabajo[0] != '0' && strncmp(pasajeros[j].lugarDeTrabajo, trabajo, 20)!=0)
                            break;
                                else if(cell != 0 && pasajeros[j].celular != cell)
                                    break;
                                        else if(tiempo1!=tiempo2 && (servs[i].minutosDeViaje<tiempo1 || servs[i].minutosDeViaje>tiempo2))
                                            break;
                                                else if(pago1!=pago2 && (servs[i].pago<pago1 || servs[i].pago>pago2))
                                                    break;
                                                        else if(total1!=total2 && ((servs[i].pago-servs[i].devuelta)<total1 || (servs[i].pago-servs[i].devuelta)>total2))
                                                            break;
                                                                else if(ano1>0 && ano2>0){
                                                                        if(ano1!=ano2 && (servs[i].fecha.ano>=ano1 && servs[i].fecha.ano<=ano2))
                                                                            MostrarPasajero(pasajeros, pasajerosTam, servs[i].idPasajero);
                                                                        if(ano1==ano2 && servs[i].fecha.ano == ano1 && (servs[i].fecha.mes>=mes1 && servs[i].fecha.mes<=mes2))
                                                                            MostrarPasajero(pasajeros, pasajerosTam, servs[i].idPasajero);
                                                                        if(mes1==mes2 && servs[i].fecha.mes == mes1 && (servs[i].fecha.dia>=dia1 && servs[i].fecha.dia<=dia2))
                                                                            MostrarPasajero(pasajeros, pasajerosTam, servs[i].idPasajero);
                                                                        if(dia1==dia2 && servs[i].fecha.dia == dia1 && (servs[i].fecha.hora>=hora1 && servs[i].fecha.hora<=hora2))
                                                                            MostrarPasajero(pasajeros, pasajerosTam, servs[i].idPasajero);
                                                                        if(min1==min2 && servs[i].fecha.minuto == min1 && (servs[i].fecha.minuto>=min1 && servs[i].fecha.minuto<=min2))
                                                                            MostrarPasajero(pasajeros, pasajerosTam, servs[i].idPasajero);
                                                                        if(servs[i].fecha.segundo>=seg1 && servs[i].fecha.segundo<=seg2)
                                                                                MostrarPasajero(pasajeros, pasajerosTam, servs[i].idPasajero);
                                                                }else MostrarPasajero(pasajeros, pasajerosTam, servs[i].idPasajero);
                    }
                }
            }
        }

    getch();
    return;
}
