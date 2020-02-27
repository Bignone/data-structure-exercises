#include <iostream>
#include <Vehiculo.h>
#include <Nodo.h>
#include <Pila.h>
#include <Cola.h>
#include <Barco.h>
#include <Embarcadero.h>
#include <Taquilla.h>
#include <Simulador.h>
#include <time.h>


using namespace std;

/** Funcion para testear el funcionamiento de cada clase
 *  comentar - descomentar para testear uno u otro
 */
void test()
{
    //test_Vehiculo();
    //test_Nodo();
    //test_Pila();
    //test_Cola();
    //test_Barco();
    //test_Embarcadero();
    //test_Taquilla();
}

void raw_main()
{
    Configuracion configuracion;
    cout << "Introduce la configuracion deseada:" << endl;
    // pedir datos
    configuracion.pedirDatos();
    cout << "la configuracion seleccionada es:" << endl;
    configuracion.write();

    // crear objectos
    Barco barco1(configuracion.getN6());
    Barco barco2(configuracion.getN6());
    Taquilla taquillaA("A");
    Taquilla taquillaB("B");
    Embarcadero embarcaderoA("A");
    Embarcadero embarcaderoB("B");

    // imprimir la config y el menu
    int iteraciones = 0;
    string inputTeclado;
    while (inputTeclado != "q" && configuracion.getN9() > 0)
    {
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << "--------------------------------> Iteracion " << iteraciones << " <------------------------------------" << endl;
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << "  Quedan " << configuracion.getN3() << " por generarse" << endl;
        cout << "  Quedan " << configuracion.getN9() << " por acabar" << endl;
        cout << "-----------------------------------------------------------------------------------" << endl;
        // imprimir barcos;
        cout << "##### Imprimiendo barcos" << endl;
        barco1.write();
        barco2.write();

        // generar vehiculos;
        cout << "##### Generando vehiculos en taquilla A" << endl;
        int cochesGenerados = 0;
        int cochesParaGenerar = configuracion.getN1();
        while(cochesGenerados < cochesParaGenerar)
        {
            taquillaA.entrar(randomVehiculo());

            cochesGenerados++;
        }

        cout << "##### Generando vehiculos en taquilla B" << endl;
        cochesGenerados = 0;
        cochesParaGenerar = configuracion.getN2();
        while(cochesGenerados < cochesParaGenerar)
        {
            taquillaB.entrar(randomVehiculo());
            cochesGenerados++;
        }

        taquillaA.write();
        taquillaB.write();

        //De taquillas a embarcaderos
        cout << "##### Pasando de taquilla A a emarcadero A" << endl;
        int cochesEntrados = 0;
        int cochesParaEntrar = configuracion.getN4();
        while((cochesEntrados < cochesParaEntrar) && (!taquillaA.esVacia()))
        {
            embarcaderoA.entrar(taquillaA.salir());
            cochesEntrados++;
        }

        cout << "##### Pasando de taquilla B a emarcadero B" << endl;
        cochesEntrados = 0;
        while((cochesEntrados < configuracion.getN4()) && (!taquillaB.esVacia()))
        {
            embarcaderoB.entrar(taquillaB.salir());
            cochesEntrados++;
        }

        embarcaderoA.write();
        embarcaderoB.write();

        //Desembarco en orilla
        cout << "##### Desembarcar barco 1 si esta lleno en orilla" << endl;
        int cochesDesembarcados = 0;
        int cochesParaDesembarcar = barco1.getNumVehiculos();

        if (barco1.permitidoDesembarcar())
        {
            while (cochesDesembarcados < cochesParaDesembarcar)
            {
                barco1.desembarcar();
                configuracion.minusN9(1);

                cochesDesembarcados++;

            }
            cout << "Vehiculos desembarcados: " << cochesDesembarcados << endl;
        }
        barco1.write();

        //Embarcamos en orillas
        cout << "##### Embarcar barco 1 si esta vacio en orilla" << endl;
        int cochesEmbarcados = 0;
        if (barco1.getEstado() == "OrillaA")
        {
            while((cochesEmbarcados < configuracion.getN5())
                  && (!barco1.esLlena())
                  && (!embarcaderoA.esVacia())
                  )
            {
                barco1.embarcar(embarcaderoA.salir());
                cochesEmbarcados++;
            }
        } else if (barco1.getEstado() == "OrillaB")
        {
            while((cochesEmbarcados < configuracion.getN5())
                  && (!barco1.esLlena())
                  && (!embarcaderoB.esVacia())
                  )
            {
                barco1.embarcar(embarcaderoB.salir());
                cochesEmbarcados++;
            }
        }
        barco1.write();

        cout << "##### Navegar barco 1 si esta lleno se fuerza" << endl;
        bool forzarNavegacion = (configuracion.getN3() == 0);
        barco1.navegar(forzarNavegacion); // zarpa cuando esLLeno o n3 es 0 (no quedan coches por generarse)
        barco1.write();

        //Desembarco en orilla
        cout << "##### Desembarcar barco 2 si esta lleno en orilla" << endl;
        cochesDesembarcados = 0;
        cochesParaDesembarcar = barco2.getNumVehiculos();

        if (barco2.permitidoDesembarcar())
        {
            while (cochesDesembarcados < cochesParaDesembarcar)
            {
                barco2.desembarcar();
                configuracion.minusN9(1);
                cochesDesembarcados++;
            }
            cout << "Vehiculos desembarcados: " << cochesDesembarcados << endl;
        }
        barco2.write();

        //Embarcamos en orillas
        cout << "##### Embarcar barco 2 si esta vacio en orilla" << endl;
        cochesEmbarcados = 0;
        if (barco2.getEstado() == "OrillaA")
        {
            while((cochesEmbarcados < configuracion.getN5())
                  && (!barco2.esLlena())
                  && (!embarcaderoA.esVacia())
                  )
            {
                barco2.embarcar(embarcaderoA.salir());
                cochesEmbarcados++;
            }
        } else if (barco2.getEstado() == "OrillaB")
        {
            while((cochesEmbarcados < configuracion.getN5())
                  && (!barco2.esLlena())
                  && (!embarcaderoB.esVacia())
                  )
            {
                barco2.embarcar(embarcaderoB.salir());
                cochesEmbarcados++;
            }
        }
        barco2.write();

        cout << "##### Navegar barco 2 si esta lleno se fuerza" << endl;
        forzarNavegacion = (configuracion.getN3() == 0);
        barco2.navegar(forzarNavegacion); // zarpa cuando esLLeno o n3 es 0(no quedan coches por generarse)
        barco2.write();

        // Otra iteracion
        getline(cin, inputTeclado);
        iteraciones++;
    }




}

int main()
{
    //test();
    raw_main();
    return 0;
}
