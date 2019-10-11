#ifndef PILA_H
#define PILA_H
#include "Nodo.h"

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        void apilar(int v);
        int desapilar();

    protected:

    private:
        pNodo cima;
};

#endif // PILA_H
