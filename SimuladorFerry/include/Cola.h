#ifndef COLA_H
#define COLA_H
#include "Nodo.h"
#include "Vehiculo.h"



class Cola
{
    public:
        Cola();
        virtual ~Cola();
        void write();
        void encolar(Vehiculo *v);
        pVehiculo desencolar();
        bool esLlena();
        bool esVacia();
        int getNumVehiculos();


    protected:

    private:
        pNodo frente;
        pNodo finall;
        int numVehiculos;
        void writeNodo(Nodo *punteroNodo);
        int recursiveNumVehiculos(Nodo *punteroNodo);
        friend class Embarcadero;
        friend class Taquilla;
};
typedef Cola *pCola;

void test_Cola();

#endif // COLA_H
