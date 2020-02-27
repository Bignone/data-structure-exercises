#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include "Vehiculo.h"


class Pila
{
    public:
        Pila(int limite = 5);
        virtual ~Pila();
        void apilar(Vehiculo *v);
        pVehiculo desapilar();
        bool esLlena();
        bool esVacia();
        void write();
        int getNumVehiculos();

    protected:


    private:
        pNodo cima;
        int limite;
        int numVehiculos;
        void writeNodo(Nodo *punteroNodo);
        int recursiveNumVehiculos(Nodo *punteroNodo);
        friend class Barco;

};
typedef Pila *pPila;

void test_Pila();

#endif // PILA_H
