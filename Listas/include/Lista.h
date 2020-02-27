#ifndef LISTA_H
#define LISTA_H
#include <Nodo.h>
#include <cstddef>


class Lista
{
    public:
        Lista(pNodo primero = NULL, pNodo ultimo = NULL);
        virtual ~Lista();
        pNodo getPrimero();
        pNodo getUltimo();
        void write();
        bool listaVacia();
        void insertarNodo(Alumno a);
        void borrarNodo(Alumno a);

    protected:

    private:
        pNodo primero;
        pNodo ultimo;
        void writeNodo(Nodo *punteroNodo);
};

#endif // LISTA_H
