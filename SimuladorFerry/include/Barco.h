#ifndef BARCO_H
#define BARCO_H

#include <Pila.h>


class Barco : public Pila
{
    public:
        Barco(int limite = 5);
        virtual ~Barco();
        void write();
        void embarcar(Vehiculo *v);
        pVehiculo desembarcar();
        bool permitidoDesembarcar();
        void navegar(bool force = false);
        string getEstado();

    protected:

    private:
        string matricula;
        string estado;
        bool puedeDesembarcar;
        void randomMatricula();
        void randomEstadoInicial();
};
typedef Barco *pBarco;

void test_Barco();

#endif // BARCO_H
