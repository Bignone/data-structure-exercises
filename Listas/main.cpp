#include <iostream>
#include <Lista.h>
#include <Alumno.h>

using namespace std;

void test_Alumno()
{
    Alumno a;
    Alumno a2;
    a.write();
    a2.write();
    bool dif = a.compare(a2);
    cout << dif << endl;
    bool eq = a.compare(a);
    cout << eq << endl;
}

void test_Nodo()
{
    Alumno a;
    a.write();
    Nodo nodo(a);
    nodo.getAlumno().write();
}

void test_Lista()
{
    Alumno a;
    Alumno a2;
    a.write();
    a2.write();
    Lista lista;
    lista.insertarNodo(a);
    lista.insertarNodo(a2);
    lista.write();

    lista.borrarNodo(a);
    lista.write();
}

int test()
{
    Alumno a1;
    Alumno a2;
    Alumno a3;
    Alumno a4;
    Alumno a5;

    a1.write();

    Lista lista;
    lista.insertarNodo(a1);
    lista.insertarNodo(a2);
    lista.insertarNodo(a3);
    lista.insertarNodo(a4);
    lista.write();

    lista.borrarNodo(a1);
    //lista.borrarNodo(a2);
    //lista.borrarNodo(a3);
    //lista.borrarNodo(a4);
    lista.write();

    return 0;
}

int main()
{
    //test_Alumno();
    //test_Nodo();
    //test_Lista();
    test();
    return 0;
}
