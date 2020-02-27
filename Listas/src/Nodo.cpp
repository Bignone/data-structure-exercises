#include "Nodo.h"

Nodo::Nodo(Alumno v, Nodo *sig)
{
    valor = v;
    siguiente = sig;
}

Nodo::~Nodo()
{
    //dtor
}

Alumno Nodo::getAlumno()
{
    return valor;
}


