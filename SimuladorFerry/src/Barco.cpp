#include "Barco.h"
#include "Vehiculo.h"
#include "Nodo.h"
#include <random>


/** Constructor de la clase Barco que hereda de Pila
 *  @param lim: limite de capacidad de la pila
 *  @param puedeDesembarcar: booleano que deja prefijado un permiso para desembarcar
 */
Barco::Barco(int lim)
{
    limite = lim;
    puedeDesembarcar = false;
    randomMatricula();
    randomEstadoInicial();
}

/** Destructor de la clase Barco
 */
Barco::~Barco()
{

}

/** Imprime el barco con un formato guay
 */
void Barco::write()
{
    cout << "Barco(matricula:" << matricula << ", estado:" << estado << ", limite:" << limite << ", vehiculos:" << getNumVehiculos() << ", lleno:" << esLlena() << ")" << endl;
    cout << "[.........................." << endl;
    writeNodo(cima);
    cout << "...........................]" << endl;
}

string Barco::getEstado()
{
    return estado;
}

/** Asigna una matricula random al barco
 */
void Barco::randomMatricula()
{
    string random_matricula = "AA0000AA";
    char nums[] = "0123456789";
    char chars[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    for (int i = 0; i < 2; ++i) {
        random_matricula[i] = chars[rand() % (sizeof(chars) - 2)];
    };

    for (int i = 2; i < 6; ++i) {
        random_matricula[i] = nums[rand() % (sizeof(nums) - 2)];
    };

    for (int i = 6; i < 8; ++i) {
        random_matricula[i] = chars[rand() % (sizeof(chars) - 2)];
    };

    matricula = random_matricula;
}

/** Asigna un estado inicial random al barco entre OrillaA y OrillaB
 * Los barcos siempre empiezan en una orilla
 */
void Barco::randomEstadoInicial()
{
    string estados[2] = {
        "OrillaA", "OrillaB"
    };
    string random_estado = estados[rand() % 2];
    estado = random_estado;
}

/** Introduce un puntero de un vehiculo en el barco (pila)
 * Si esta en una de las dos orillas
 * @param *v: puntero al vehiculo v
 */
void Barco::embarcar(Vehiculo *v)
{
    if (estado == "OrillaA" || estado == "OrillaB")
    {
        if (!esLlena())
            apilar(v);
    }
}

bool Barco::permitidoDesembarcar()
{
    return puedeDesembarcar;
}

/** Implementa el comportamiento y cambios de estado del barco
 * estado: OrillaA -> NavegandoAB
 * estado: NavegandoAB -> OrillaB
 * estado: OrillaB -> NavegandoBA
 * estado: NavegandoBA -> OrillaA
 */
void Barco::navegar(bool force)
{
    if (estado == "OrillaA")
    {
        if (esLlena())
        {
            estado = "NavegandoAB";
        }
        else if (force)
        {
            estado = "NavegandoAB";
        }
        puedeDesembarcar = false;

    }
    else if (estado == "OrillaB")
    {
         if (esLlena())
        {
            estado = "NavegandoBA";
        }
        else if (force)
        {
            estado = "NavegandoBA";
        }
        puedeDesembarcar = false;
    }
    else if (estado == "NavegandoBA")
    {
        puedeDesembarcar = true;
        estado = "OrillaA";
    }
    else if (estado == "NavegandoAB")
    {
        puedeDesembarcar = true;
        estado = "OrillaB";
    }

}

/** Saca un puntero de un vehiculo en el barco (pila)
 * Si esta en una de las dos orillas
 */
pVehiculo Barco::desembarcar()
{
    pVehiculo punteroVehiculo;
    if ((estado == "OrillaA" || estado == "OrillaB" ) && (!esVacia()))
    {
        punteroVehiculo = desapilar();
    }
    return punteroVehiculo;

}


/** Testea algunos casos de prueba de la clase Barco
 */
void test_Barco()
{
    cout << "# Test Barco" << endl;
    pVehiculo pv1 = new Vehiculo();
    pVehiculo pv2 = new Vehiculo();
    pVehiculo pv3 = new Vehiculo();
    pVehiculo pv4 = new Vehiculo();
    //pVehiculo pv5 = new Vehiculo();

    cout << "Barco: barco vacia" << endl;
    Barco barco;
    barco.write();

    cout << "Barco: barco apilada vehiculo" << endl;
    barco.embarcar(pv1);
    barco.apilar(pv2);
    barco.apilar(pv3);
    barco.embarcar(pv4);
    //barco.apilar(pv5);
    cout << "barco vacia: " << barco.esVacia() << endl;
    cout << "barco llena: " << barco.esLlena() << endl;
    barco.write();

    cout << "Barco: barco desapilar vehiculo" << endl;
    Vehiculo pv6 = *barco.desapilar();
    //barco.apilar(pv5);
    pv6.write();
    barco.write();

    cout << "Barco: navegar" << endl;
    barco.navegar();
    barco.write();
    barco.navegar();
    barco.write();
}
