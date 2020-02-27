#include "Taquilla.h"
#include <time.h>
#include <random>


/** Constructor de la clase Taquilla que hereda de Cola
 *  @param nom: nombre del emparcadero
 */
Taquilla::Taquilla(string nom)
{
    nombre = nom;
}

/** Destructor de la clase Taquilla
 */
Taquilla::~Taquilla()
{
    //dtor
}

/** Imprime el taquilla con un formato guay
 */
void Taquilla::write()
{
    cout << "Taquilla(nombre:" << nombre << ", vehiculos:" << getNumVehiculos() << ")" << endl;
    cout << "[...........................<" << endl;
    writeNodo(frente);
    cout << "<...........................]" << endl;
}

/** Mete un puntero de tipo vehiculo en la taquilla
 * Si no esta lleno. Utiliza encolar() de la clase padre
 *  @param *v: puntero a un vehiculo
 */
void Taquilla::entrar(Vehiculo *v)
{
    encolar(v); // no limite
}

/** Saca un puntero de tipo vehiculo de la taquilla
 * si no esta vacia. Utiliza desencolar() de la clase padre
 */
pVehiculo Taquilla::salir()
{
    pVehiculo punteroVehiculo;
    if (!esVacia())
    {
        punteroVehiculo = desencolar();
        punteroVehiculo->setEntrada(randomEntrada());
    }

    return punteroVehiculo;
}

/**Genera una entrada random de la taquilla
 */
string Taquilla::randomEntrada()
{

    string random_entrada = "-----";
    char nums[] = "0123456789";

    for (int i = 0; i < 5; ++i) {
        random_entrada[i] = nums[rand() % (sizeof(nums) - 2)];
    };
    random_entrada[random_entrada.size()-1] = nombre[0];
    return random_entrada;
}


/** Testea algunos casos de prueba de la clase Taquilla
 */
void test_Taquilla()
{
    cout << "# Test Taquilla" << endl;
    pVehiculo pv1 = new Vehiculo();
    pVehiculo pv2 = new Vehiculo();
    pVehiculo pv3 = new Vehiculo();
    pVehiculo pv4 = new Vehiculo();
    //pVehiculo pv5 = new Vehiculo();

    cout << "Taquilla: taquilla vacia" << endl;
    Taquilla taquilla("A");
    taquilla.write();
    cout << "taquilla vacia: " << taquilla.esVacia() << endl;

    cout << "Taquilla: taquilla entrar vehiculo" << endl;
    taquilla.entrar(pv1);
    taquilla.entrar(pv2);
    taquilla.entrar(pv3);
    taquilla.entrar(pv4);
    //taquilla.entrar(pv5);
    cout << "taquilla vacia: " << taquilla.esVacia() << endl;
    cout << "taquilla llena: " << taquilla.esLlena() << endl;
    taquilla.write();

    cout << "Taquilla: taquilla salir vehiculo" << endl;
    Vehiculo pv6 = *taquilla.salir();
    //taquilla.entrar(pv5);
    pv6.write();
    taquilla.write();
    cout << "Taquilla: Numero vehiculos recursivo: " << taquilla.getNumVehiculos() << endl;
    cout << "Taquilla: Entrada random: " << taquilla.randomEntrada() << endl;

    cout << "Taquilla: taquilla B con while" << endl;
    Taquilla taquillaB("B");
    taquillaB.write();

    int cochesGenerados = 0;
    while((cochesGenerados < 10))
    {
        taquillaB.entrar(randomVehiculo());
        cochesGenerados++;
    }
    taquillaB.write();


}
