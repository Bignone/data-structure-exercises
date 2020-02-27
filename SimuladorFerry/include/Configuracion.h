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
        int getN3();
        int getN4();
        int getN5();
        int getN6();
        int getN9();
        void minusN9(int n);
        void pedirDatos();
        void write();

    protected:

    private:
        int n1;
        int n2;
        int n3;
        int n4;
        int n5;
        int n6;
        int n9;

        int nAleatorio(int a,int b);
};

#endif // CONFIGURACION_H
