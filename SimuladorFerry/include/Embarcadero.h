#ifndef EMBARCADERO_H
#define EMBARCADERO_H
#include <Cola.h>


class Embarcadero : public Cola
{
    public:
        Embarcadero(string nombre);
        virtual ~Embarcadero();
        void write();
        void entrar(Vehiculo *v);
        pVehiculo salir();



    protected:

    private:
        string nombre;
};
typedef Embarcadero *pEmbarcadero;

void test_Embarcadero();

#endif // EMBARCADERO_H
