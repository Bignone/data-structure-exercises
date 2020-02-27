#include "Nodo.h"
#include "Vehiculo.h"


/** Constructor de la clase Nodo utilizado en pilas y colas
 *  @param *v: puntero a un vehiculo
 *  @param *sig: puntero al nodo siguiente en la estructura linkada
 */
Nodo::Nodo(Vehiculo *v, Nodo *sig)
{
    vehiculo = v;
    siguiente = sig;
}

/** Destructor de la clase Nodo
 */
Nodo::~Nodo()
{
    //dtor
}

/** Obtiene el puntero del vehiculo
 */
pVehiculo Nodo::getVehiculo()
{
    return vehiculo;
}

/** Obtiene el puntero del siguiente nodo
 */
pNodo Nodo::getSiguiente()
{
    return siguiente;
}

/** Imprime el nodo con un formato guay
 */
void Nodo::write()
{
    cout << "Nodo(vehiculo: " << vehiculo << ", siguiente: " << siguiente << ")" << endl;
}


/** Testea algunos casos de prueba de la clase Nodo
 */
void test_Nodo()
{
    cout << "# Test Nodo" << endl;
    cout << "Nodo: vehiculo random" << endl;
    pVehiculo punteroVehiculo = new Vehiculo();
    cout << "Direccion de memoria: " << punteroVehiculo << endl;
    Vehiculo v3 = *punteroVehiculo;
    v3.write();

    pNodo punteroNodo;
    punteroNodo = new Nodo(punteroVehiculo);
    Nodo n1 = *punteroNodo;
    n1.write();
    // Creamos un puntero y almacenamos en el el puntero del nodo al vehiculo.
    // En el v4 almacenamos el contenido del puntero. Printeamos
    pVehiculo p1 = n1.getVehiculo();
    Vehiculo v4 = *p1;
    v4.write();
    // Lo mismo, pero nos ahorramos crear un puntero. Al vehículo se le pasa directamente el del nodo.
    Vehiculo v5 = *n1.getVehiculo();
    v5.write();

}
