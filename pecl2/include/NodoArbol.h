#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <Vehiculo.h>

class NodoArbol
{
    public:
        NodoArbol();
        NodoArbol(pVehiculo vehiculo, NodoArbol *izquierdo = NULL, NodoArbol *derecho = NULL);
        void write();
        virtual ~NodoArbol();

    protected:

    private:
        pVehiculo vehiculo;
        NodoArbol *izquierdo;
        NodoArbol *derecho;
        friend class ArbolBB;

};

typedef NodoArbol *pNodoArbol;

void test_NodoArbol();

#endif // NODOARBOL_H
