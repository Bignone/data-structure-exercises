#ifndef COLA_H
#define COLA_H
#include "Nodo.h"


class Cola
{
    public:
        Cola();
        virtual ~Cola();
        void encolar(int v);
        int desencolar();

    protected:

    private:
        pNodo frente, finall;
};

#endif // COLA_H
