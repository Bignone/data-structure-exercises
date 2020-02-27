#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <cstddef>
#include "Viaje.h"

class NodoLista
{
    public:
        // se pasan al constructor los punteros (por defecto NULL)
        NodoLista(Viaje *v = NULL, NodoLista *sig = NULL, NodoLista *ant = NULL);
        virtual ~NodoLista();
        void write();
        pViaje getViaje();
        NodoLista * getSiguiente();
        NodoLista * getAnterior();

    protected:

    private:
        // cada nodo tiene tres punteros, uno a un elemento, otro al nodo siguiente y otro al anterior
        pViaje viaje;
        NodoLista *siguiente;
        NodoLista *anterior;
        friend class Lista;

};
typedef NodoLista *pNodoLista;

void test_NodoLista();

#endif // NODO_H
