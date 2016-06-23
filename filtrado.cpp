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
    char filtro;
    int id = -1;
    rango ano;
    char marca[20] = {'0'}, propietario[20] = {'0'};
    rango tiempoViaje, pago, total;
    tiempo fecha1, fecha2;
    string nombreFiltros[6] = {"Marca", "Año", "Tiempo de viaje", "Monto de pago", "Monto de total", "Fecha de viaje"};
    bool filtrosBool[6];
    void *filtros[7] = {&marca, &ano, &tiempoViaje, &pago, &total, &fecha1, &fecha2};


    MostrarPasajeros(pasajeros, pasajerosTam);

    do{
        printf("\n-Id del pasajero: ");
        cin >> id;
        if(BuscarPasajero(pasajeros, pasajerosTam,id)==false)
            printf("\nERROR: INTRODUZCCA UN ID EXISTENTE");
    }while(BuscarPasajero(pasajeros, pasajerosTam,id)==false);
    do{
    printf("\n-Desea agregar filtros? (s/n): ");
    cin >> filtro;
        if(filtro!='s' && filtro!='n')
            printf("\nERROR: OPCIONES VALIDAS: s/n");
    }while(filtro!='s' && filtro!='n');
    if(filtro == 'n')
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

 cout << "Presione espacio para seleccionar o otra letra para ignorar\n";
    for(int i=0; i<6; i++)
    {
        cout << "Desea agregar un filtro de: " << nombreFiltros[i] << "? ";
        if(getche() == 32)
        {
            filtrosBool[i] = true;
            cout << "*SELECCIONADO*";
        }
        else
        {
            filtrosBool[i] = false;
            cout << "*Ignorar*";
        }
        cout << endl;
    }
        for (int i=0; i<2; i++)
    {
        if(filtrosBool[i] == true)
        {
            cout << nombreFiltros[i] << ": ";
            cin >> (char*)(filtros[i]);
        }

    }
    for (int i=2; i<5; i++)
    {
        if(filtrosBool[i] == true)
        {
        cout << nombreFiltros[i] << ": " << endl;
        cout << "-Rango mayor: ";
        cin >> (((rango*)(filtros[i]))->mayor);
        cout << "-Rango menor: ";
        cin >> (((rango*)(filtros[i]))->menor);
        }
    }

    if(filtrosBool[5]==true)
        printf("Ingrese los datos del rango para la fecha 1 y fecha 2 en el siguiente formato: \n");
    for(int i=5; i<7; i++)
    {
        if(filtrosBool[5]==true)
        {
            printf("Fecha %d:\n", i-4);
            do
            {
                printf("(dia mes a%co) sin parentesis: ", 164);
                cin >> (((tiempo*)(filtros[i]))->dia);
                cin >> (((tiempo*)(filtros[i]))->mes);
                cin >> (((tiempo*)(filtros[i]))->ano);

            }while((fecha1.ano*10000 + fecha1.mes * 100 + fecha1.dia)>99991231 || (fecha1.ano*10000 + fecha1.mes * 100 + fecha1.dia)<0);
            do
            {
                printf("(hora minuto segundo) sin parentresis: ");
                cin >> (((tiempo*)(filtros[i]))->hora);
                cin >> (((tiempo*)(filtros[i]))->minuto);
                cin >> (((tiempo*)(filtros[i]))->segundo);
            }while((fecha1.hora*10000 + fecha1.minuto * 100 + fecha1.segundo) > 245959 || (fecha1.hora*10000 + fecha1.minuto * 100 + fecha1.segundo) < 0);
        }
    }
    printf("\n-----------------------------------------------------------------\n");
        for(int i=0; i<ServiciosTam; i++)
        {
            if(servs[i].idPasajero == id)
                {
                    for(int j=0; j<conchosTam; j++)
                    {
                        if(strncmp(servs[i].fichaVehiculo, conchos[j].ficha, 4)==0)
                        {
                            bool aux = true;
                            void *current[6] = {&conchos[j].marca, &conchos[j].ano, &servs[i].minutosDeViaje, &servs[i].pago, &servs[i].devuelta, &servs[i].fecha};

                            for(int k=0; k<2; k++)
                                {
                                    if(filtrosBool[k]==true && strncmp(((char*)(current[k])), ((char*)(filtros[k])), 4)!=0)
                                        aux = false;
                                }
                            for(int k=2; k<4; k++)
                                {
                                    if(filtrosBool[k]==true && (*(float*)(current[k])) < (((rango*)(filtros[k]))->menor) && (*(float*)(current[k])) > (((rango*)(filtros[k]))->mayor))
                                        aux = false;
                                }
                            if(filtrosBool[5]==true)
                            {
                                aux = CompararFechas((*(tiempo*)(current[5])),(*(tiempo*)(filtros[5])), (*(tiempo*)(filtros[6])));
                            }
                            if(aux==true)
                                    MostrarCarro(conchos, conchosTam, servs[i].fichaVehiculo);
                        }
                    }
                }
        }

    getch();
    return;


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
