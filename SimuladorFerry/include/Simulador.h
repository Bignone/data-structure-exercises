#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <Embarcadero.h>
#include <Taquilla.h>
#include <Barco.h>
#include <Vehiculo.h>
#include <Configuracion.h>

class Simulador
{
    public:
        Simulador();
        virtual ~Simulador();
        void run();

    protected:

    private:
        Configuracion configuracion;
        pBarco punteroBarco1;
        pBarco punteroBarco2;
        pTaquilla punteroTaquillaA;
        pTaquilla punteroTaquillaB;
        pEmbarcadero punteroEmbarcaderoA;
        pEmbarcadero punteroEmbarcaderoB;

       void imprimirBarco();
       void generarVehiculos();
       void taquillaToEmbarcadero();
       void desembarcarEmbarcar();
       void navegar();


};

#endif // SIMULADOR_H
