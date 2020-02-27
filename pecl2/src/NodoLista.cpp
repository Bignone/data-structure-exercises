#include "NodoLista.h"
#include "Viaje.h"


/** Constructor de la clase NodoLista utilizado en pilas y colas
 *  @param *v: puntero a un Viaje
 *  @param *sig: puntero al nodo siguiente en la estructura linkada
 */
NodoLista::NodoLista(Viaje *v, NodoLista *sig, NodoLista *ant)
{
    viaje = v;
    siguiente = sig;
    anterior = ant;
}

/** Destructor de la clase NodoLista
 */
NodoLista::~NodoLista()
{
    //dtor
}

/** Obtiene el puntero del viaje
 */
pViaje NodoLista::getViaje()
{
    return viaje;
}

/** Obtiene el puntero del siguiente nodo
 */
pNodoLista NodoLista::getSiguiente()
{
    return siguiente;
}

/** Obtiene el puntero del nodo anterior
 */
pNodoLista NodoLista::getAnterior()
{
    return anterior;
}

/** Imprime el nodo con un formato guay
 */
void NodoLista::write()
{
    cout << "NodoLista(viaje: " << viaje << ", siguiente: " << siguiente << ")" << endl;
}


/** Testea algunos casos de prueba de la clase NodoLista
 */
void test_NodoLista()
{
    cout << "# Test NodoLista" << endl;
    cout << "NodoLista: viaje random" << endl;
    pViaje punteroViaje = new Viaje();
    cout << "Direccion de memoria: " << punteroViaje << endl;

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

}
