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
    n3 = nAleatorio(80, 120); //80 + (rand() % 40);
    n9 = n3; //vehiculos restantes en el simulador

}

Configuracion::~Configuracion()
{
    //dtor
}

void Configuracion::write()
{
    cout << "Configuracion(" << endl;
    cout << "    n1 (generados taquilla A):" << n1 << endl;
    cout << "    n2 (generados taquilla B):" << n2 << endl;
    cout << "    n3 (restantes totales):" << n3 << endl;
    cout << "    n4 (limite taquillas a embarcaderos):" << n4 << endl;
    cout << "    n5 (limite embarcaderos a barcos):" << n5 << endl;
    cout << "    n6 (capacidad barcos):" << n6 << endl;
    cout << "    n9 (retantes por acabar):" << n9 << endl;
    cout << "    )" << endl;
}

//Geters
int Configuracion::getN1()
{
    // Calculamos un aleatorio que sea menor al numero de coches que quedan
    n1 = min (n3, nAleatorio(2, 6));
    n3 = n3 - n1;
    return n1;
}

int Configuracion::getN2()
{
    // Calculamos un aleatorio que sea menor al numero de coches que quedan
    n2 = min(n3, nAleatorio(2, 6));
    n3 = n3 - n2;
    return n2;
}

int Configuracion::getN3()
{
    return n3;
}

int Configuracion::getN4()
{

    return n4;
}

int Configuracion::getN5()
{
    return n5;
}

int Configuracion::getN6()
{
    return n6;
}

int Configuracion::getN9()
{
    return n9;
}

void Configuracion::minusN9(int n)
{
    n9 = n9 - n;
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
    cout << "¿Cuantos coches de taquillas a embarcaderos deseas?"<< endl;
    cin >> n4;
    if ( n4 <= 0)
    {
        cout << "Numero invalido, tomando el valor por defecto (20)"<< endl;
        n4 = 20;
    }
    cout << "¿Cuantos coches de embarcaderos al barco deseas?"<< endl;
    cin >> n5;
    if ( n5 <= 0)
    {
        cout << "Numero invalido, tomando el valor por defecto (20)"<< endl;
        n5 = 20;
    }
    cout << "¿Que capacidad quieres que tenga el barco?"<< endl;
    cin >> n6;
    if ( n6 <= 0)
    {
        cout << "Numero invalido, tomando el valor por defecto (25)"<< endl;
        n6 = 20;
    }
}
