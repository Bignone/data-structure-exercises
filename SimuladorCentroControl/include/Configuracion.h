#ifndef CONFIGURACION_H
#define CONFIGURACION_H
#include <algorithm>

using namespace std;

class Configuracion
{
    public:
        Configuracion();
        virtual ~Configuracion();
        int getN1();
        int getN2();
        void pedirDatos();
        void write();

    protected:

    private:
        int n1;
        int n2;
        int nAleatorio(int a,int b);
};

#endif // CONFIGURACION_H
