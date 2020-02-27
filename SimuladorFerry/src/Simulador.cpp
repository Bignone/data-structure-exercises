#include "Simulador.h"
#include <random>


Simulador::Simulador()
{
    Configuracion configuracion;
    punteroBarco1 = new Barco(configuracion.getN6());
    punteroBarco2 = new Barco(configuracion.getN6());
    punteroTaquillaA = new Taquilla("A");
    punteroTaquillaB = new Taquilla("B");
    punteroEmbarcaderoA = new Embarcadero("A");
    punteroEmbarcaderoB = new Embarcadero("B");

}

Simulador::~Simulador()
{
    //dtor
}

void Simulador::run()
{
    // pedir datos configuracion
    configuracion.pedirDatos();
    // imprimir la config y el menu
    string inputTeclado;
    while (inputTeclado != "9" && configuracion.getN3() > 0)
    {
        getline(cin, inputTeclado);
        imprimirBarco();
        generarVehiculos();
        taquillaToEmbarcadero();
        desembarcarEmbarcar();
    }

}

void Simulador::imprimirBarco()
{
    punteroBarco1->write();
    punteroBarco2->write();
}


void Simulador::generarVehiculos()
{
    pVehiculo pV;
    int cochesGenerados = 0;
    while((cochesGenerados < configuracion.getN1()))
    {
        //pV = new Vehiculo();
        punteroTaquillaA->entrar(randomVehiculo());
        cochesGenerados++;
        //pV = NULL;
    }

    cochesGenerados = 0;
    while(cochesGenerados < configuracion.getN2())
    {
        pVehiculo pV2 = new Vehiculo();
        punteroTaquillaB->entrar(pV2);
        cochesGenerados++;
        delete pV2;
    }

    punteroTaquillaA->write();
    punteroTaquillaB->write();
}

void Simulador::taquillaToEmbarcadero()
{
    int cochesEntrados = 0;
    while(cochesEntrados < configuracion.getN4())
    {
        punteroEmbarcaderoA->entrar(punteroTaquillaA->salir());
        cochesEntrados++;
    }

    cochesEntrados = 0;
    while(cochesEntrados < configuracion.getN4())
    {
        punteroEmbarcaderoB->entrar(punteroTaquillaB->salir());
        cochesEntrados++;
    }

    punteroEmbarcaderoA->write();
    punteroEmbarcaderoB->write();
}

void Simulador::desembarcarEmbarcar()
{
    int cochesEmbarcados = 0;
    punteroBarco1->desembarcar();
    if (punteroBarco1->getEstado() == "OrillaA")
    {
        while((cochesEmbarcados < configuracion.getN5()) && (!punteroBarco1->esLlena()))
        {
            punteroBarco1->embarcar(punteroEmbarcaderoA->salir());
            cochesEmbarcados++;
        }
    } else if (punteroBarco1->getEstado() == "OrillaB")
    {
        while((cochesEmbarcados < configuracion.getN5()) && (!punteroBarco1->esLlena()))
        {
            punteroBarco1->embarcar(punteroEmbarcaderoB->salir());
            cochesEmbarcados++;
        }
    }

    cochesEmbarcados = 0;
    punteroBarco2->desembarcar();
    if (punteroBarco2->getEstado() == "OrillaA")
    {
        while((cochesEmbarcados < configuracion.getN5()) && (!punteroBarco2->esLlena()))
        {
            punteroBarco2->embarcar(punteroEmbarcaderoA->salir());
            cochesEmbarcados++;
        }
    } else if (punteroBarco2->getEstado() == "OrillaB")
    {
        while((cochesEmbarcados < configuracion.getN5()) && (!punteroBarco2->esLlena()))
        {
            punteroBarco2->embarcar(punteroEmbarcaderoB->salir());
            cochesEmbarcados++;
        }
    }

    punteroBarco1->write();
    punteroBarco2->write();
}

void Simulador::navegar()
{
    punteroBarco1->navegar();
    punteroBarco2->navegar();
}
