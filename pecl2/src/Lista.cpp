#include "Lista.h"
#include <Viaje.h>

Lista::Lista(pNodoLista prim, pNodoLista ult)
{
    primero = prim;
    ultimo = ult;
}

Lista::~Lista()
{
    //dtor
}

/** Imprime la Lista con un formato guay
 */
void Lista::write()
{
    bool vac = listaVacia();
    cout << "Lista(vacia: " << vac << ")" << endl;
    cout << "[...........................<" << endl;
    writeNodo(primero);
    cout << "<...........................]" << endl;
}

/** Metodo de ayuda para imprimir el contenido de la Lista
 * Utiliza la recursividad y los punteros
 *  @param *punteroNodo: puntero a un nodo de la Lista
 */
void Lista::writeNodo(NodoLista *punteroNodo)
{
    if (punteroNodo)
    {
        // imprimir utilizando los punteros (->) sin traer los objetos a memoria
        punteroNodo->getViaje()->write();
        writeNodo(punteroNodo->siguiente);

    }

}
pNodoLista Lista::getPrimero()
{
    return primero;
}

pNodoLista Lista::getUltimo()
{
    return ultimo;
}

bool Lista::listaVacia()
{
    return primero == NULL && ultimo == NULL;
}

void Lista::insertarNodo(pViaje v)
{   pNodoLista aux;
    if(listaVacia())
    {
        primero = new NodoLista(v, NULL);
        ultimo = primero;
    }
    else
    {
        aux = new NodoLista(v, NULL);
        ultimo->siguiente = aux;
        ultimo = aux;
    }
}

/** Testea algunos casos de prueba de la clase Lista
 */
void test_Lista()
{
    cout << "# Test Lista" << endl;
    cout << "Lista: viaje random" << endl;
    pVehiculo punteroVehiculo = new Vehiculo();
    pViaje punteroViaje = new Viaje(punteroVehiculo);

    pNodoLista punteroNodo;
    punteroNodo = new NodoLista(punteroViaje);
    NodoLista n1 = *punteroNodo;
    n1.write();
    // Creamos un puntero y almacenamos en el el puntero del nodo al vehiculo.
    // En el v4 almacenamos el contenido del puntero. Printeamos
    pViaje p1 = n1.getViaje();
    Viaje v4 = *p1;
    v4.write();
    // Lo mismo, pero nos ahorramos crear un puntero. Al vehículo se le pasa directamente el del nodo.
    Viaje v5 = *n1.getViaje();
    v5.write();

    pLista l1 = new Lista();
    Lista l2 ;

    l1->insertarNodo(punteroViaje);
    l1->write();

    l2.insertarNodo(punteroViaje);
    l2.write();
}
