#include "Cola.h"
#include <cstddef>
#include "Vehiculo.h"
#include "Nodo.h"


/** Constructor de la clase Cola
 * Es una cola sin limitacion
 */
Cola::Cola()
{
    frente = NULL;
    finall = NULL;
}

/** Destructor de la clase Cola
 * Saca todos los nodos de la cola antes de borrarla
 */
Cola::~Cola()
{
    while(frente) desencolar();
}

/** Chequea si la la cola esta vacia
 */
bool Cola::esVacia()
{
    return frente == NULL && finall == NULL;
}

/** Chequea si la la cola esta llena
 */
bool Cola::esLlena()
{
    return false; // cola sin limite
}

/** Devuelve el numero de vehiculos
 */
int Cola::getNumVehiculos()
{
    return recursiveNumVehiculos(frente);
}

/** Metodo de ayuda para obtener el numero de vehiculos
 * Utiliza la recursividad
 *  @param *punteroNodo: puntero a un nodo de la cola
 */
int Cola::recursiveNumVehiculos(Nodo *punteroNodo)
{
    if (punteroNodo)
    {
        Nodo nodo = *punteroNodo; // Almacenamos en ese nodo el contenido del puntero que le hemos pasado
        return 1 + recursiveNumVehiculos(nodo.getSiguiente());
    }
    return 0;
}

/** Imprime la cola con un formato guay
 */
void Cola::write()
{
    cout << "Cola(vehiculos:" << getNumVehiculos() << ")" << endl;
    cout << "[...........................<" << endl;
    writeNodo(frente);
    cout << "<...........................]" << endl;
}

/** Metodo de ayuda para imprimir el contenido de la cola
 * Utiliza la recursividad y los punteros
 *  @param *punteroNodo: puntero a un nodo de la cola
 */
void Cola::writeNodo(Nodo *punteroNodo)
{
    if (punteroNodo)
    {
        // imprimir utilizando los punteros (->) sin traer los objetos a memoria
        punteroNodo->getVehiculo()->write();
        writeNodo(punteroNodo->getSiguiente());

    }

}

/** Mete un puntero de tipo vehiculo en la cola
 * Crea un nodo en memoria y le asigna el puntero del vehiculo
 *  @param *v: puntero a un vehiculo
 */
void Cola::encolar(Vehiculo *v)
{
    pNodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
    // Si cola no vacía, se añade el nuevo a continuación de ultimo
    if(finall)
    {
        finall -> siguiente = nuevo;
    }

    //El último elemento de la cola es el nuevo nodo
    finall = nuevo;
    // Si 1º es NULL, la cola vacía, 1º apunta al nuevo nodo
    if(!frente)
    {
        frente = nuevo;
    }
}

/** Saca un puntero de tipo vehiculo de la cola
 * Saca un nodo en memoria y devuelve el puntero del vehiculo
 */
pVehiculo Cola::desencolar()
{
    pVehiculo punteroVehiculo; //Var aux para manipular vehiculo
    if (!esVacia())
    {
        pNodo nodo; //Var aux para manipular nodo
        // Nodo apunta al primer elemento de la pila
        nodo = frente;
        if(!nodo) return NULL; // Si no hay nodos en la pila se devuelve 0
        //Se asigna a 1º la dirección del segundo nodo
        frente = nodo->siguiente;
        //Se guarda el valor de retorno
        punteroVehiculo = nodo->vehiculo;
        delete nodo; // Se borra el nodo
        // Si cola vacía, ultimo debe ser NULL también
        if(!frente)
        {
            finall = NULL;
        }

    }
    return punteroVehiculo;
}


/** Testea algunos casos de prueba de la clase Cola
 */
void test_Cola()
{
    cout << "# Test Cola" << endl;
    pVehiculo pv1 = new Vehiculo();
    pVehiculo pv2 = new Vehiculo();
    pVehiculo pv3 = new Vehiculo();
    pVehiculo pv4 = new Vehiculo();
    //pVehiculo pv5 = new Vehiculo();

    cout << "Cola: cola vacia" << endl;
    Cola cola;
    cola.write();
    cout << "cola vacia: " << cola.esVacia() << endl;

    cout << "Cola: cola llenada y vaciada" << endl;
    cola.encolar(pv1);
    cola.desencolar();
    cout << "cola vacia: " << cola.esVacia() << endl;

    cout << "Cola: cola apilada vehiculo" << endl;
    cola.encolar(pv1);
    cola.encolar(pv2);
    cola.encolar(pv3);
    cola.encolar(pv4);
    //cola.encolar(pv5);
    cout << "cola vacia: " << cola.esVacia() << endl;
    cout << "cola llena (nunca): " << cola.esLlena() << endl;
    cola.write();

    cout << "Cola: cola desencolar vehiculo" << endl;
    Vehiculo pv6 = *cola.desencolar();
    //cola.encolar(pv5);
    pv6.write();
    cola.write();
    cout << "Cola: Numero vehiculos recursivo: " << cola.getNumVehiculos() << endl;

}
