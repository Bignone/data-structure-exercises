#ifndef NODO_H
#define NODO_H
#include <cstddef>


class Nodo
{
    public:
        Nodo(int v, Nodo *sig = NULL);
        virtual ~Nodo();

    protected:

    private:
        int valor;
        Nodo *siguiente;
        friend class Pila;
        friend class Cola;
};
typedef Nodo *pNodo;
#endif // NODO_H
