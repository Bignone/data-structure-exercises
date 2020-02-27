#include "Alumno.h"
#include <iostream>
#include <string.h>
#include <random>
#include <time.h>

using namespace std;

Alumno::Alumno()
{
    randomNombre();
    randomNota();
    randomNumero();
}

Alumno::Alumno(string nom, int nott, int num)
{
    nombre = nom;
    nota = nott;
    num = numero;
}

Alumno::~Alumno()
{
    //dtor
}

/** Imprime el vehiculo con un formato guay
 */
void Alumno::write()
{
    cout << "Alumno("<<"nombre:"<<nombre<<", "<<"nota:"<<nota<<", "<<"numero:"<<numero<<")" << endl;
}

string Alumno::getNombre()
{
    return nombre;
}

int Alumno::getNota()
{
    return nota;
}

int Alumno::getNumero()
{
    return numero;
}

/**Establece un nombre random al alumno
 */
void Alumno::randomNombre()
{
    string nombres[5] = {
        "Cesar", "Juana", "Javier", "Gabriel", "Rosa"
    };
    nombre = nombres[rand() % 5];
}

void Alumno::randomNota()
{
    nota = rand() % 11;
}

void Alumno::randomNumero()
{
    numero = rand() % 200;
}

bool Alumno::compare(Alumno a)
{
    int result = false;

    if (numero == a.getNumero())
    {
        result = true;
    }
    return result;
}
