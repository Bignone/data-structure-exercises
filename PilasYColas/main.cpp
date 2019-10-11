#include <iostream>
#include <Pila.h>
#include <Cola.h>

using namespace std;

int main_pila()
{
    cout << "Testing Pila program" << endl;
    Pila pila; //Se instancia un objeto de la clase Pila.
    pila.apilar(20); //Se añade un nodo
    cout << "Apilar(20)" << endl;
    pila.apilar(10); //Se añade un nodo
    cout << "Apilar(10)" << endl;
    //Se saca un nodo (10)
    cout << "Desapilar() = " << pila.desapilar() << endl;
    pila.apilar(40); //Se añade un nodo
    cout << "Apilar(40)" << endl;
    pila.apilar(30); //Se añade un nodo
    cout << "Apilar(30)" << endl;
    //Se saca un nodo (30)
    cout << "Desapilar() = " << pila.desapilar() << endl;
    //Se saca un nodo (40)
    cout << "Desapilar() = " << pila.desapilar() << endl;
    pila.apilar(90); //Se añade un nodo
    cout << "Apilar(90)" << endl;
    //Se saca un nodo (90)
    cout << "Desapilar() = " << pila.desapilar() << endl;
    //Se saca un nodo (20)
    cout << "Desapilar() = " << pila.desapilar() << endl;
    return 0;
}

int main_cola()
{
    cout << "Testing Cola program" << endl;
    Cola cola;
    cola.encolar(20);
    cout << "Encolar(20)" << endl;
    cola.encolar(10);
    cout << "Encolar(10)" << endl;
    cout << "Leer: " << cola.desencolar() << endl;
    cola.encolar(40);
    cout << "Encolar(40)" << endl;
    cola.encolar(30);
    cout << "Encolar(30)" << endl;
    cout << "Leer: " << cola.desencolar() << endl;
    cout << "Leer: " << cola.desencolar() << endl;
    cola.encolar(90);
    cout << "Encolar(90)" << endl;
    cout << "Leer: " << cola.desencolar() << endl;
    cout << "Leer: " << cola.desencolar() << endl;
    return 0;
}

int main()
{
    main_pila();
    main_cola();
    return 0;
}
