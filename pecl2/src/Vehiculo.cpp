#include "Vehiculo.h"
#include <Lista.h>
#include <iostream>
#include <string.h>
#include <random>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;


/** Constructor de la clase Vehiculo
 * Genera un vehiculo con valores aleatorios
 */
Vehiculo::Vehiculo()
{
    randomMatricula();
    randomMarca();
    randomModelo();
    randomColor();
    tiempoEspera = 0;
    randomEntrada();
    viajes = NULL;
}

/** Constructor con argumentos de la clase Vehiculo
 *  @param mat: matricula (string)
 *  @param mar: marca (string)
 *  @param mod: modelo (string)
 *  @param col: color (string)
 *  @param entr: entrada (string)
 *  @param tiempoEsp: tiempo de espera en minutos (int)
 */
Vehiculo::Vehiculo(string mat, string mar, string mod, string col, string entr, int tiempoEsp)
{
    matricula = mat;
    marca = mar;
    modelo = mod;
    color = col;
    entrada = entr;
    tiempoEspera = tiempoEsp;
    viajes = NULL;
}

/** Destructor de la clase Vehiculo
 */
Vehiculo::~Vehiculo()
{

}

/** Imprime el vehiculo con un formato guay
 */
void Vehiculo::write()
{
    cout << "Vehiculo("<<"matricula:"<<matricula<<", "<<"marca:"<<marca<<", "<<"modelo:"<<modelo<<", "<<"color:"<<color<<", "<<"entrada:"<<entrada<<", "<<"tiempoEspera:"<<tiempoEspera<<")" << endl;
    if (viajes)
    {
        viajes->write();
    }
}

/** Obtiene el valor de matricula
 */
string Vehiculo::getMatricula()
{
    return matricula;
}

/** Establece el valor de matricula
 * @param mat: matricula (string)
 */
void Vehiculo::setMatricula(string mat)
{
    matricula = mat;
}

/** Obtiene el valor de marca
 */
string Vehiculo::getMarca()
{
    return marca;
}

/** Establece el valor de marca
 * @param mar: marca (string)
 */
void Vehiculo::setMarca(string mar)
{
    marca = mar;
}

/** Obtiene el valor de modelo
 */
string Vehiculo::getModelo()
{
    return modelo;
}

/** Establece el valor de modelo
 * @param mod: modelo (string)
 */
void Vehiculo::setModelo(string mod)
{
    modelo = mod;
}

/** Obtiene el valor de color
 */
string Vehiculo::getColor()
{
    return color;
}

/** Establece el valor de color
 * @param col: color (string)
 */
void Vehiculo::setColor(string col)
{
    color = col;
}

/** Obtiene el valor de entrada
 */
string Vehiculo::getEntrada()
{
    return entrada;
}

/** Establece el valor de entrada
 * @param ent: entrada (string)
 */
void Vehiculo::setEntrada(string ent)
{
    entrada = ent;
}

/** Obtiene el valor de tiempo de espera
 */
int Vehiculo::getTiempoEspera()
{
    return tiempoEspera;
}

/** Establece el valor de tiempo de espera
 * @param tiempoEsp: tiempo de espera (int)
 */
void Vehiculo::setTiempoEspera(int tiempoEsp)
{
    tiempoEspera = tiempoEsp;
}

/** Annade un valor al tiempo de espera
 * @param tiempoEsp: tiempo de espera (int)
 */
int Vehiculo::addTiempoEspera(int tiempoEsp)
{
    tiempoEspera += tiempoEsp;
    return tiempoEspera;
}

void Vehiculo::setViajes(pLista viajs)
{
    viajes = viajs;
}

pLista Vehiculo::getViajes()
{
    return viajes;
}

/** Compara si dos vehiculos son iguales mediante sus atributos
 * @param v: Vehiculo
 */
bool Vehiculo::equals(Vehiculo v)
{
    bool isEquals = true;

    if ((matricula != v.getMatricula()) ||
        (color != v.getColor()) ||
        (marca != v.getMarca()) ||
        (modelo != v.getModelo()) ||
        (entrada != v.getEntrada()) ||
        (tiempoEspera != v.getTiempoEspera())
        )
    {
        isEquals = false;
    }

    return isEquals;
}

/**Establece una marca random al vehiculo
 */
void Vehiculo::randomMarca()
{
    string marcas[4] = {
        "Wolkswagen", "Mercedes", "BMW", "Audi"
    };
    string random_marca = marcas[rand() % 4];
    marca = random_marca;
}

/**Establece un modelo random al vehiculo
 */
void Vehiculo::randomModelo()
{
    string marcasWolkswagen[5] = {
        "Golf", "Passat", "Touareg", "Polo", "Golf"
    };
    string marcasMercedes[5] = {
        "CLA", "CLS", "GLC", "CLS", "CLE"
    };
    string marcasBMW[5] = {
        "320", "520", "X5", "Serie1", "Serie2"
    };
    string marcasAudi[5] = {
        "A3", "A8", "Q7", "Q5", "TT"
    };

    string random_modelo;

    if (marca == "Wolkswagen")
    {
        random_modelo = marcasWolkswagen[rand() % 5];
    }
    else if (marca == "Mercedes")
    {
        random_modelo = marcasMercedes[rand() % 5];
    }
    else if (marca == "BMW")
    {
        random_modelo = marcasBMW[rand() % 5];
    }
    else if (marca == "Audi")
    {
        random_modelo = marcasAudi[rand() % 5];
    }
    else {
        random_modelo = "Unknown";
    }
    modelo = random_modelo;
}

/**Establece una matricula random al vehiculo
 */
void Vehiculo::randomMatricula()
{
    string random_matricula = "0000AAA";
    char nums[] = "0123456789";
    char chars[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    for (int i = 0; i < 4; ++i) {
        random_matricula[i] = nums[rand() % (sizeof(nums) - 2)];
    }
    for (int i = 4; i < 7; ++i) {
        random_matricula[i] = chars[rand() % (sizeof(chars) - 2)];
    }

    matricula = random_matricula;
}

/**Establece una entrada random al vehiculo
 */
void Vehiculo::randomEntrada()
{

    string random_entrada = "-----";
    char nums[] = "0123456789";
    char taquillas[] = "AB";

    for (int i = 0; i < 5; ++i) {
        random_entrada[i] = nums[rand() % (sizeof(nums) - 2)];
    };
    random_entrada[random_entrada.size()-1] = taquillas[rand() % (sizeof(taquillas) - 2)];
    entrada = random_entrada;
}

/**Establece un color random al vehiculo
 */
void Vehiculo::randomColor()
{
    string colores[6] = {
        "Blanco", "Negro", "Rojo", "Azul", "Verde", "Amarillo"
    };
    string random_color = colores[rand() % (6 - 1)];

    color = random_color;
}

/**Compara este Vehiculo con otro
 * Primero compara las letras y si son iguales, los numeros
 * (-1) -> El propio vehiculo es mas antiguo
 * (+1) -> El propio vehiculo es mas nuevo
 *  (0) -> Los vehiculos son iguales
 */
int Vehiculo::compare(Vehiculo v)
{

    int result = 0;
    string letrasPropio = matricula.substr(4, 7);
    string letrasOtro = v.getMatricula().substr(4, 7);

    string numerosPropio = matricula.substr(0, 4);
    string numerosOtro = v.getMatricula().substr(0, 4);

    if (letrasPropio > letrasOtro)
    {
        result = 1;
    }
    else if (letrasPropio < letrasOtro)
    {
        result = -1;
    }
    else
    {
        if (numerosPropio > numerosOtro)
        {
            result = 1;
        }
        else if (numerosPropio < numerosOtro)
        {
            result = 1;
        }
    }
    return result;

}


pVehiculo randomVehiculo()
{
    return new Vehiculo();
}

/** Testea algunos casos de prueba de la clase Vehiculo
 */
void test_Vehiculo()
{
    cout << "# Test Vehiculo" << endl;
    cout << "Vehiculo 1: random" << endl;
    Vehiculo v1;
    v1.write();
    cout << "Vehiculo: vehiculos iguales (true):" << v1.equals(v1) << endl;

    cout << "Vehiculo 2: params" << endl;
    string matricula = "1234ABC";
    string marca = "Audi";
    string modelo = "Q7";
    string color = "Negro";
    string entrada = "";
    Vehiculo v2(matricula, marca, modelo, color, entrada, 0);
    v2.write();

    cout << "Vehiculo 3: desde puntero" << endl;
    pVehiculo punteroVehiculo = new Vehiculo();
    cout << "Direccion de memoria: " << punteroVehiculo << endl;
    Vehiculo v3 = *punteroVehiculo;
    v3.write();

    cout << "Vehiculo 4: desde puntero" << endl;
    pVehiculo pV = new Vehiculo();
    pV->write();

    cout << "Vehiculo 5: comparar vehiculos" << endl;
    Vehiculo compareV1;
    Vehiculo compareV2;
    compareV1.write();
    compareV2.write();
    int comparation = compareV1.compare(compareV2);
    cout << "Comparation: " << endl;
    compareV1.write();
    compareV2.write();
    cout << "comparation: " << comparation << endl;
}
