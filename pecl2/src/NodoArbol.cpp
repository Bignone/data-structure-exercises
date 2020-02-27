#include "NodoArbol.h"
#include <Vehiculo.h>
#include <Viaje.h>
#include <Lista.h>
#include <stdio.h>

using namespace std;

NodoArbol::NodoArbol()
{
    vehiculo = NULL;
    izquierdo = NULL;
    derecho = NULL;
}

NodoArbol::NodoArbol(pVehiculo vehi, pNodoArbol izq, pNodoArbol der)
{
    vehiculo = vehi;
    izquierdo = izq;
    derecho = der;
}


NodoArbol::~NodoArbol()
{
    //dtor
}


void NodoArbol::write()
{
    string mat = "null";
    if (vehiculo)
    {
        mat = vehiculo->getMatricula();
    }
    cout << "NodoArbol(matricula: " << mat << ", raiz: " << this << ", izquierdo: " << izquierdo << ", derecho: " << derecho << ")" << endl;
}

void test_NodoArbol()
{
    pVehiculo punteroVehiculo1 = new Vehiculo();
    pVehiculo punteroVehiculo2 = new Vehiculo();

    pNodoArbol NA1 = new NodoArbol();
    pNodoArbol NA2 = new NodoArbol(punteroVehiculo1);
    pNodoArbol NA3 = new NodoArbol(punteroVehiculo2);

    NA1->write();
    NA2->write();
    NA3->write();
}
