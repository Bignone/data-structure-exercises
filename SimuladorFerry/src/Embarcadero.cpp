#include "Embarcadero.h"


/** Constructor de la clase Embarcadero que hereda de Cola
 *  @param nom: nombre del emparcadero
 */
Embarcadero::Embarcadero(string nom)
{
    nombre = nom;
}

/** Destructor de la clase Embarcadero
 */
Embarcadero::~Embarcadero()
{
    //des
}

/** Imprime el embarcadero con un formato guay
 */
void Embarcadero::write()
{
    cout << "Embarcadero(nombre:" << nombre << ", vehiculos:" << getNumVehiculos() << ")" << endl;
    cout << "[...........................<" << endl;
    writeNodo(frente);
    cout << "<...........................]" << endl;
}

/** Mete un puntero de tipo vehiculo en el embarcadero
 * Si no esta lleno. Utiliza encolar() de la clase padre
 *  @param *v: puntero a un vehiculo
 */
void Embarcadero::entrar(Vehiculo *v)
{
    encolar(v);
}

/** Saca un puntero de tipo vehiculo del embarcadero
 * si no esta vacia. Utiliza desencolar() de la clase padre
 */
pVehiculo Embarcadero::salir()
{
    pVehiculo punteroVehiculo;
    if (!esVacia())
    {
        punteroVehiculo = desencolar();
    }

    return punteroVehiculo;
}


/** Testea algunos casos de prueba de la clase Embarcadero
 */
void test_Embarcadero()
{
    cout << "# Test Embarcadero" << endl;
    pVehiculo pv1 = new Vehiculo();
    pVehiculo pv2 = new Vehiculo();
    pVehiculo pv3 = new Vehiculo();
    pVehiculo pv4 = new Vehiculo();
    //pVehiculo pv5 = new Vehiculo();

    cout << "Embarcadero: embarcadero vacia" << endl;
    Embarcadero embarcadero("A");
    embarcadero.write();

    cout << "Embarcadero: embarcadero entrar vehiculo" << endl;
    embarcadero.entrar(pv1);
    embarcadero.entrar(pv2);
    embarcadero.entrar(pv3);
    embarcadero.entrar(pv4);
    //embarcadero.entrar(pv5);
    cout << "embarcadero vacia: " << embarcadero.esVacia() << endl;
    cout << "embarcadero llena: " << embarcadero.esLlena() << endl;
    embarcadero.write();

    cout << "Embarcadero: embarcadero salir vehiculo" << endl;
    Vehiculo pv6 = *embarcadero.salir();
    //embarcadero.entrar(pv5);
    pv6.write();
    embarcadero.write();
    cout << "Embarcadero: Numero vehiculos recursivo: " << embarcadero.getNumVehiculos() << endl;

}
