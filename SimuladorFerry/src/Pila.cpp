#include "Pila.h"
#include <cstddef>
#include "Vehiculo.h"
#include "Nodo.h"


/** Constructor de la clase Pila
 *  @param lim: limite de capacidad de la pila
 */
Pila::Pila(int lim)
{
    cima = NULL;
    limite = lim;
}

/** Destructor de la clase Pila
 * Saca todos los nodos de la pila antes de borrarla
 */
Pila::~Pila()
{
    while(cima) desapilar();
}

/** Chequea si la la pila esta llena; si el total de vehículos coincide con el límite, está llena
 */
bool Pila::esLlena()
{
    return getNumVehiculos() == limite;
}

/** Chequea si la la pila esta vacia
 */
bool Pila::esVacia()
{
    return getNumVehiculos() == 0;
}

/** Devuelve el numero de vehiculos
 */
int Pila::getNumVehiculos()
{
    return recursiveNumVehiculos(cima);
}

/** Metodo de ayuda para obtener el numero de vehiculos
 * Utiliza la recursividad
 *  @param *punteroNodo: puntero a un nodo de la cola
 */
int Pila::recursiveNumVehiculos(Nodo *punteroNodo)
{
    if (punteroNodo) //Si hay un nodo, por tanto no está vacía
    {
        Nodo nodo = *punteroNodo;
        return 1 + recursiveNumVehiculos(nodo.getSiguiente());
    }
    return 0;
}

/** Imprime el nodo con un formato guay
 */
void Pila::write()
{
    cout << "Pila(limite:" << limite << ", vehiculos:" << getNumVehiculos() << ", llena:" << esLlena() << ", vacia:" << esVacia() << ")" << endl;
    cout << "[...................." << endl;
    writeNodo(cima);
    cout << "...........................]" << endl;
}

/** Metodo de ayuda para imprimir el contenido de la pila
 * Utiliza la recursividad y los punteros
 *  @param *punteroNodo: puntero a un nodo de la pila
 */
void Pila::writeNodo(Nodo *punteroNodo)
{
    // comprueba si el puntero existe (ultimo es null)
    if (punteroNodo)
    {
        punteroNodo->getVehiculo()->write();
        writeNodo(punteroNodo->getSiguiente());
    }

}

/** Mete un puntero de tipo vehiculo en la pila
 * Crea un nodo en memoria y le asigna el puntero del vehiculo
 *  @param *v: puntero a un vehiculo
 */
void Pila::apilar(Vehiculo *v)
{
    if (!esLlena())
    {
        pNodo punteroNodo;
        // si esa vacia se crea un nodo con siguiente == NULL (por defecto)
        if (esVacia())
        {
            punteroNodo = new Nodo(v);
        } else
        {
            // si no esta vacia se crea un nodo apuntando a la cima anterior
            punteroNodo = new Nodo(v, cima);
        }
        // se actualiza la cima
        cima = punteroNodo;
    }
}

/** Saca un puntero de tipo vehiculo de la pila
 * Saca un nodo en memoria y devuelve el puntero del vehiculo
 */
pVehiculo Pila::desapilar()
{
    pVehiculo punteroVehiculo; //Var aux para el retorno del valor del nodo
    if (!esVacia())
    {
        pNodo nodo; //Var aux para manipular el nodo
        // Nodo apunta al primer elemento de la pila
        nodo = cima;
        if(!cima) return NULL; // Si no hay nodos en la pila se devuelve 0
        //Se asigna a pila toda la pila menos el primer elemento
        cima = nodo->siguiente;
        //Se guarda el retorno del valor del nodo
        punteroVehiculo = nodo-> vehiculo;
        //Se borra el nodo
        delete nodo;
    }

    return punteroVehiculo;
}


/** Testea algunos casos de prueba de la clase Pila
 */
void test_Pila()
{
    cout << "# Test Pila" << endl;
    pVehiculo pv1 = new Vehiculo();
    pVehiculo pv2 = new Vehiculo();
    pVehiculo pv3 = new Vehiculo();
    pVehiculo pv4 = new Vehiculo();
    pVehiculo pv5 = new Vehiculo();

    cout << "Pila: pila vacia" << endl;
    Pila pila;
    pila.write();

    cout << "Pila: pila vacia apilar desapilar" << endl;
    pila.apilar(pv1);
    pila.desapilar();
    pila.write();

    cout << "Pila: pila apilada vehiculo" << endl;
    pila.apilar(pv1);
    pila.apilar(pv2);
    pila.apilar(pv3);
    pila.apilar(pv4);
    pila.apilar(pv5);
    cout << "pila vacia: " << pila.esVacia() << endl;
    cout << "pila llena: " << pila.esLlena() << endl;
    pila.write();

    cout << "Pila: pila desapilar vehiculo" << endl;
    Vehiculo pv6 = *pila.desapilar();
    //pila.apilar(pv5);
    pv6.write();
    pila.write();
    cout << "Pila: Numero vehiculos recursivo: " << pila.getNumVehiculos() << endl;

}
