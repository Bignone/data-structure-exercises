#include <iostream>
#include <Vehiculo.h>
#include <Viaje.h>
#include <NodoLista.h>
#include <Lista.h>
#include <NodoArbol.h>
#include <ArbolBB.h>
#include <Configuracion.h>

using namespace std;

void test()
{

    //test_Viaje();
    //test_NodoLista();
    test_Lista();
    //test_Vehiculo();
    //test_NodoArbol();
    //test_ArbolBB();

}

void printMenu()
{
    cout << "------------------------- MENU DE OPERACIONES ----------------------------" << endl;
    cout << "1. Insertar un vehiculo (de forma automatica o manual)." << endl;
    cout << "2. Borrar un vehiculo." << endl;
    cout << "3. Mostrar los datos almacenados de un vehiculo dado." << endl;
    cout << "4. Modificar la valoracion de un viaje concreto por parte de un cliente." << endl;
    cout << "5. Mostrar estadisticas mensuales sobre el servicio." << endl;
    cout << "6. Mostrar estadisticas de un dia concreto." << endl;
    cout << "7. Mostrar estadisticas de un coche concreto." << endl;
    cout << "8. Borrar algun viaje concreto." << endl;
    cout << "0. Salir (liberar memoria previamente)." << endl;
    cout << "--------------------------------------------------------------------------" << endl;
}

void raw_main()
{
    Configuracion configuracion;
    cout << "Introduce la configuracion deseada:" << endl;
    // pedir datos
    configuracion.pedirDatos();
    cout << "La configuracion seleccionada es:" << endl;
    configuracion.write();

    // crear objectos
    ArbolBB arbolBB;

    // generar vehiculos
    cout << "\n" << endl;
    cout << "Generar vehiculos" << endl;
    int contadorVehiculosGenerados = 0;
    while (contadorVehiculosGenerados < configuracion.getN1()) {
        arbolBB.insertar(randomVehiculo());
        contadorVehiculosGenerados++;
    }
    cout << "Generados todos los vehiculos: " << contadorVehiculosGenerados << endl;

    // generar viajes
    cout << "\n" << endl;
    cout << "Generar viajes (inOrden)" << endl;
    int diaIteracion = 1;
    int interacionesGeneracion = 5;
    string inputTeclado;
    getline(cin, inputTeclado);
    while (interacionesGeneracion >= diaIteracion)
    {
        int numViajesGenerados = 0;
        int numParaGenerar = configuracion.getN2();
        cout << "Iteracion de generacion de viajes (5 dias), dia: " << diaIteracion << ", viajes: " << numParaGenerar << endl;
        while (numViajesGenerados < numParaGenerar)
        {
            //cout << "dia numViajesGenerados: " << numViajesGenerados << endl;
            arbolBB.randomViaje(diaIteracion);
            numViajesGenerados++;
        }


        getline(cin, inputTeclado);
        diaIteracion++;
    }


    // imprimit arbol
    cout << "\n" << endl;
    cout << "Imprimir arbol" << endl;
    arbolBB.write();

    // impirmir menu
    cout << "\n" << endl;
    cout << "Imprimir menu" << endl;
    printMenu();
    string matricula;
    string marca;
    string modelo;
    string color;
    string entrada;
    int valoracion;
    int dia;

    getline(cin, inputTeclado);
    while (inputTeclado != "0")
    {
        if (inputTeclado == "1") // 1. Insertar un vehiculo (de forma automatica o manual) (OK)
        {
            pVehiculo vehiculo = new Vehiculo();
            cout << "Introduce matricula (Enter for random)" << endl;

            getline(cin, matricula);
            if (matricula != "") {
                vehiculo->setMatricula(matricula);
            }
            cout << "Introduce marca (Enter for random)" << endl;

            getline(cin, marca);
            if (marca != "") {
                vehiculo->setMarca(marca);
            }

            cout << "Introduce modelo (Enter for random)" << endl;

            getline(cin, modelo);
            if (modelo != "") {
                vehiculo->setModelo(modelo);
            }

            cout << "Introduce color (Enter for random)" << endl;

            getline(cin, color);
            if (color != "") {
                vehiculo->setColor(color);
            }

            vehiculo->write();
            arbolBB.insertar(vehiculo);
            cout << "Vehiculo insertado. Arbol:" << endl;
            arbolBB.write();

        }
        else if (inputTeclado == "2") // 2. Borrar un vehiculo. (OK)
        {
            pVehiculo vehiculo = new Vehiculo();
            cout << "Introduce matricula" << endl;
            getline(cin, matricula);
            if (matricula == "")
            {
                continue;
            }
            vehiculo->setMatricula(matricula);
            arbolBB.borrar(vehiculo);
            cout << "Vehiculo borrado. Arbol:" << endl;
            arbolBB.write();
        }
        else if (inputTeclado == "3") // 3. Mostrar los datos almacenados de un vehiculo dado. (OK)
        {
            pVehiculo vehiculo = new Vehiculo();
            cout << "Introduce matricula" << endl;
            getline(cin, matricula);
            if (matricula == "")
            {
                cout << "matricula invalida" << endl;
                continue;
            }
            vehiculo->setMatricula(matricula);
            if (!arbolBB.buscar(vehiculo)) {
                cout << "vehiculo no encontrado" << endl;
                continue;
            }
            arbolBB.getActualVehiculo()->write();

        }
        else if (inputTeclado == "4") // 4. Modificar la valoracion de un viaje concreto por parte de un cliente
        {
            pVehiculo vehiculo = new Vehiculo();
            cout << "Introduce matricula" << endl;
            getline(cin, matricula);
            if (matricula == "")
            {
                cout << "matricula invalida" << endl;
                continue;
            }
            vehiculo->setMatricula(matricula);
            if (!arbolBB.buscar(vehiculo))
            {
                cout << "vehiculo no encontrado" << endl;
                continue;
            }
            vehiculo = arbolBB.getActualVehiculo();
            vehiculo->write();
            cout << "Introduce la entrada del viaje" << endl;
            getline(cin, entrada);
            pViaje viaje = new Viaje(matricula, entrada);
            if (!vehiculo->getViajes()->buscarViaje(viaje))
            {
                cout << "Entrada invalida" << endl;
                continue;
            }
            cout << "Introduce nueva valoracion" << endl;
            cin >> valoracion;
            viaje->setValoracion(valoracion);
            vehiculo->getViajes()->modificarViaje(viaje);
        }
        else if (inputTeclado == "5") // 5. Mostrar estadisticas mensuales sobre el servicio
        {
            arbolBB.estadisticas();
        }
        else if (inputTeclado == "6") // 6. Mostrar estadisticas de un dia concreto
        {
            cout << "Introduce numero dia" << endl;
            dia = 0;
            cin >> dia;
            arbolBB.estadisticas(dia+1);
        }
        else if (inputTeclado == "7") // 7. Mostrar estadisticas de un coche concreto
        {
            pVehiculo vehiculo = new Vehiculo();
            cout << "Introduce matricula" << endl;

            getline(cin, matricula);
            if (matricula != "") {
                vehiculo->setMatricula(matricula);
            }
            if (!arbolBB.buscar(vehiculo))
            {
                cout << "vehiculo no encontrado" << endl;
                continue;
            }
            arbolBB.getActualVehiculo()->write();
            arbolBB.getActualVehiculo()->getViajes()->estadisticas();
        }
        else if (inputTeclado == "8") // 8. Borrar algun viaje concreto. (OK)
        {
            pVehiculo vehiculo = new Vehiculo();
            cout << "Introduce matricula" << endl;

            getline(cin, matricula);
            if (matricula != "") {
                vehiculo->setMatricula(matricula);
            }
            if (!arbolBB.buscar(vehiculo))
            {
                cout << "vehiculo no encontrado" << endl;
                continue;
            }
            vehiculo = arbolBB.getActualVehiculo();
            vehiculo->write();
            cout << "Introduce la entrada del viaje" << endl;
            getline(cin, entrada);
            pViaje viaje = new Viaje(matricula, entrada);
            if (!vehiculo->getViajes()->buscarViaje(viaje))
            {
                cout << "Entrada invalida" << endl;
                continue;
            }
            arbolBB.getActualVehiculo()->borrarViaje(viaje);
            arbolBB.getActualVehiculo()->write();
        }
        else {
            printMenu();
        }

        getline(cin, inputTeclado);
        diaIteracion++;
    }
    cout << "Saliendo del programa" << endl;

}

int main()
{
    //test();
    raw_main();
    return 0;
}
