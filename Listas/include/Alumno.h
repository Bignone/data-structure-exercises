#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <string.h>

using namespace std;

class Alumno
{
    public:
        Alumno();
        Alumno(string nombre, int nota, int numero);
        virtual ~Alumno();
        string getNombre();
        int getNota();
        int getNumero();
        void write();
        bool compare(Alumno a);

    protected:

    private:
        string nombre;
        int nota;
        int numero;
        void randomNombre();
        void randomNota();
        void randomNumero();

};

#endif // ALUMNO_H
