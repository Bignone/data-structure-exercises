#include "Viaje.h"
#include <iostream>
#include <algorithm>

using namespace std;

Viaje::Viaje(string mat, string entrad)
{
    matricula = mat;
    entrada = entrad;
    hora = nAleatorio(0, 23);
    dia = nAleatorio(1, 30);
    ocupantes = nAleatorio(1, 5);
    valoracion = nAleatorio(0, 10);
}

Viaje::Viaje(string mat, string ent, int hor, int di, int ocupts, int valorn)
{
    matricula = mat;
    entrada = ent;
    hora = hor;
    dia = di;
    ocupantes = ocupts;
    valoracion = valorn;
}

Viaje::~Viaje()
{
    //dtor
}

/** Imprime el vehiculo con un formato guay
 */
void Viaje::write()
{
    cout << "Viaje("<<"matricula:"<<matricula<<", "<<"entrada:"<<entrada<<", "<<"hora:"<<hora<<", "<<"dia:"<<dia<<", "<<"ocupantes:"<<ocupantes<<", "<<"valoracion:"<<valoracion<<")" << endl;
}

/** Obtiene el valor de matricula
 */
string Viaje::getMatricula()
{
    return matricula;
}

/** Establece el valor de matricula
 * @param mat: matricula (string)
 */
void Viaje::setMatricula(string mat)
{
    matricula = mat;
}

/** Obtiene el valor de entrada
 */
string Viaje::getEntrada()
{
    return entrada;
}

/** Establece el valor de entrada
 * @param ent: entrada (string)
 */
void Viaje::setEntrada(string ent)
{
    entrada = ent;
}

/** Obtiene el valor de hora
 */
int Viaje::getHora()
{
    return hora;
}

/** Establece el valor de hora
 * @param hor: hora (int)
 */
void Viaje::setHora(int hor)
{
    hora = hor;
}

/** Obtiene el valor del dia
 */
int Viaje::getDia()
{
    return dia;
}

/** Establece el valor del dia
 * @param di: dia (int)
 */
void Viaje::setDia(int di)
{
    dia = di;
}

/** Obtiene el valor de ocupantes
 */
int Viaje::getOcupantes()
{
    return ocupantes;
}

/** Establece el valor de ocupantes
 * @param ocupts: ocupantes (int)
 */
void Viaje::setOcupantes(int ocupts)
{
    ocupantes = ocupts;
}

int Viaje::getValoracion()
{
    return valoracion;
}

void Viaje::setValoracion(int v)
{
    valoracion = v;
}

bool Viaje::equals(Viaje v)
{
    bool isEquals = true;

    if (entrada != v.getEntrada())
    {
        isEquals = false;
    }

    return isEquals;
}

bool Viaje::pEquals(pViaje v)
{
    bool isEquals = true;

    if (entrada != v->getEntrada())
    {
        isEquals = false;
    }

    return isEquals;
}

int Viaje::nAleatorio(int a, int b)
{
    int num;
    //srand(time(NULL));
    num = a + rand() % (b + 1 - a);
    return num;
}

/** Testea algunos casos de prueba de la clase Viaje
 */
void test_Viaje()
{
    cout << "# Test Viaje" << endl;
    //pVehiculo punteroVehiculo = new Vehiculo();
    //Viaje viaje(punteroVehiculo->getMatricula(), punteroVehiculo->getEntrada());
    Viaje viaje("3321fda", "asdasd");
    viaje.write();
    Viaje viaje2("3321fda", "asdasd");
    viaje2.write();
    bool eq = viaje.equals(viaje2);
    cout << eq <<endl;

    pViaje viaje3 = new Viaje("3321fda", "asdasd");
    viaje3->write();
    pViaje viaje4 = new Viaje("3321fda", "asdasd");
    viaje4->write();
    bool eqq = viaje3->pEquals(viaje4);
    cout << eqq <<endl;

    //pVehiculo punteroVehiculo2 = new Vehiculo();
    //pViaje punteroViaje = new Viaje(punteroVehiculo2->getMatricula(), punteroVehiculo2->getEntrada());
    //punteroViaje->write();
}
