#ifndef ARBOLBB_H
#define ARBOLBB_H
#include <iostream>
#include "NodoArbol.h"
#include <Vehiculo.h>


class ArbolBB
{

    public:
       // Constructor y destructor b�sicos:
       ArbolBB();
       ~ArbolBB();
       // Insertar en �rbol ordenado:
       void insertar(pVehiculo vehiculo);
       // Borrar un elemento del �rbol:
       void borrar(pVehiculo vehiculo);
       // Funci�n de b�squeda:
       bool buscar(pVehiculo vehiculo);
       // Comprobar si el �rbol est� vac�o:
       bool vacio(NodoArbol *r);
       // Comprobar si es un nodo hoja:
       bool esHoja(NodoArbol *r);
       // Contar n�mero de nodos:
       const int numeroNodos();
       const int alturaArbol();
       // Calcular altura de un int:
       int getAltura(pVehiculo vehiculo);
       // Devolver referencia al int del nodo actual:
       pNodoArbol getRaiz();
       pNodoArbol getValorActual();
       pVehiculo getActualVehiculo();
       // Moverse al nodo raiz:
       void raizActual();
       // Aplicar una funci�n a cada elemento del �rbol:
       void inOrden(void (*func)(pVehiculo) , NodoArbol *nodo=NULL, bool r=true);
       void preOrden(void (*func)(pVehiculo) , NodoArbol *nodo=NULL, bool r=true);
       void postOrden(void (*func)(pVehiculo) , NodoArbol *nodo=NULL, bool r=true);
       void write();
       void writeNodoArbol(pNodoArbol n);

    protected:

    private:
        pNodoArbol raiz;
        pNodoArbol actual;
        int contador;
        int altura;
        // Funciones auxiliares
        void podar(NodoArbol* &);
        void auxContador(NodoArbol*);
        void auxAltura(NodoArbol*, int);

};

void test_ArbolBB();

#endif // ARBOLABB_H
