#include "Configuracion.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <algorithm>

using namespace std;

Configuracion::Configuracion()
{
    //pedirDatos();
    //total de coches
    n1 = 2;
    n2 = 2;

}

Configuracion::~Configuracion()
{
    //dtor
}

void Configuracion::write()
{
    cout << "Configuracion:" << endl;
    cout << "    n1 (generados):" << n1 << endl;
    cout << "    n2 (viajes aleatorios):" << n2 << endl;
}

//Geters
int Configuracion::getN1()
{
    return n1;
}

int Configuracion::getN2()
{
    return nAleatorio(1, n1);
}

int Configuracion::nAleatorio(int a, int b)
{
    int num;
    //srand(time(NULL));
    num = a + rand() % (b+1 -a);
    return num;
}

void Configuracion::pedirDatos()
{
    cout << "¿Cuantos coches iniciales deseas?"<< endl;
    cin >> n1;
    if ( n1 <= 0)
    {
        cout << "Numero invalido, tomando el valor por defecto (1)"<< endl;
        n1 = 1;
    }
}
