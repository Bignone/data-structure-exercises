#ifndef TAQUILLA_H
#define TAQUILLA_H

#include <Cola.h>


class Taquilla : public Cola
{
    public:
        Taquilla(string nombre);
        virtual ~Taquilla();
        void write();
        void entrar(Vehiculo *v);
        pVehiculo salir();
        string randomEntrada();

    protected:

    private:
        string nombre;

};
typedef Taquilla *pTaquilla;

void test_Taquilla();


#endif // TAQUILLA_H
