#ifndef VIAJE_H
#define VIAJE_H
#include <Lista.h>
#include <iostream>
#include <string.h>

using namespace std;

class Viaje
{
    public:
        Viaje(string matricula, string entrada);
        Viaje(string matricula, string entrada, int hora, int dia, int ocupantes, int valoracion);
        virtual ~Viaje();
        void write();
        string getMatricula();
        void setMatricula(string matricula);
        string getEntrada();
        void setEntrada(string entrada);
        int getHora();
        void setHora(int hora);
        int getDia();
        void setDia(int dia);
        int getOcupantes();
        void setOcupantes(int ocupantes);

    protected:

    private:
        string matricula;
        string entrada;
        int hora;
        int dia;
        int ocupantes;
        int valoracion;
        int nAleatorio(int a, int b);
        friend class Lista;
        friend class NodoLista;

};

typedef Viaje *pViaje;

void test_Viaje();
#endif // VIAJE_H
