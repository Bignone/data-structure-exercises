#ifndef NODO_H
#define NODO_H
#include <cstddef>
#include <Alumno.h>


class Nodo
{
    public:
        Nodo(Alumno v, Nodo *sig = NULL);
        virtual ~Nodo();
        Alumno getAlumno();

    protected:

    private:
        Alumno valor;
        Nodo *siguiente;
        friend class Lista;
};
typedef Nodo *pNodo;
#endif // NODO_H
