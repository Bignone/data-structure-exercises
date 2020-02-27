#ifndef LISTA_H
#define LISTA_H
#include <NodoLista.h>
#include <Viaje.h>
#include <cstddef>


class Lista
{
    public:
        Lista(pNodoLista primero = NULL, pNodoLista ultimo = NULL);
        virtual ~Lista();
        pNodoLista getPrimero();
        pNodoLista getUltimo();
        void write();
        bool listaVacia();
        void insertarNodo(pViaje v);

    protected:

    private:
        pNodoLista primero;
        pNodoLista ultimo;
        pViaje valor;
        void writeNodo(pNodoLista punteroNodo);
};

typedef Lista *pLista;
void test_Lista();
#endif // LISTA_H
