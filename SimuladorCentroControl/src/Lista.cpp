#include "Lista.h"
#include <Viaje.h>
#include <iostream>
#include <string.h>

Lista::Lista(pNodoLista prim, pNodoLista ult)
{
    primero = prim;
    ultimo = ult;
}

Lista::~Lista()
{
    //dtor
}

/** Imprime la Lista con un formato guay
 */
void Lista::write()
{
    bool vac = listaVacia();
    cout << "Lista(vacia: " << vac << ")" << endl;
    cout << "[...........................<" << endl;
    writeNodo(primero);
    cout << "<...........................]" << endl;
}

/** Metodo de ayuda para imprimir el contenido de la Lista
 * Utiliza la recursividad y los punteros
 *  @param *punteroNodo: puntero a un nodo de la Lista
 */
void Lista::writeNodo(NodoLista *punteroNodo)
{
    if (punteroNodo)
    {
        // imprimir utilizando los punteros (->) sin traer los objetos a memoria
        punteroNodo->getViaje()->write();
        writeNodo(punteroNodo->siguiente);

    }

}
pNodoLista Lista::getPrimero()
{
    return primero;
}

pNodoLista Lista::getUltimo()
{
    return ultimo;
}

bool Lista::listaVacia()
{
    return primero == NULL && ultimo == NULL;
}

void Lista::insertarNodo(pViaje v)
{
    pNodoLista aux;
    if(listaVacia())
    {
        primero = new NodoLista(v, NULL);
        ultimo = primero;
    }
    else
    {
        if (!buscarViaje(v))
        {
            aux = new NodoLista(v, NULL);
            aux->anterior = ultimo;
            ultimo->siguiente = aux;
            ultimo = aux;
            ultimo->siguiente = NULL;
        }

    }
}

bool Lista::buscarViaje(pViaje v)
{
    bool existe = false;
    pNodoLista aux;

    if (!listaVacia())
    {
        aux = primero;
        while(aux != NULL && existe == false)
        {
            existe = v->pEquals(aux->getViaje());
            aux = aux->siguiente;
        }
    }

    return existe;
}

void Lista::borrarViaje(pViaje v)
{
    if (buscarViaje(v))
    {
        pNodoLista aux = primero;

        while (!(aux->getViaje()->pEquals(v)) && aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        if (aux->anterior)
        {
            aux->anterior->siguiente = aux->siguiente;
        }
        else
        {
            primero = aux->siguiente;
        }
        if (aux->siguiente)
        {
            aux->siguiente->anterior = aux->anterior;
        }
        else
        {
            ultimo= aux->anterior;
        }

        aux->anterior = NULL;
        aux->siguiente = NULL;
        delete aux;

    }
}

void Lista::modificarViaje(pViaje v)
{
    if (buscarViaje(v))
    {
        pNodoLista aux = primero;

        while (aux->getViaje() != v && aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        pViaje auxViaje = aux->getViaje();
        auxViaje->valoracion = v->valoracion;

    }
}

void Lista::estadisticas()
{
    float mediaSatisfaccion = 0;
    float mediaOcupantes = 0;
    float nViajes = 0;

    if (!listaVacia())
    {
        pNodoLista aux = primero;
        while(aux != NULL)
        {
            nViajes ++;
            mediaSatisfaccion += aux->getViaje()->getValoracion();
            mediaOcupantes += aux->getViaje()->getOcupantes();
            aux = aux->siguiente;
        }
        mediaOcupantes = mediaOcupantes / nViajes;
        mediaSatisfaccion = mediaSatisfaccion / nViajes;
    }
    cout << "Estadisticas de los viajes" << endl;
    cout << "Numero de viajes: "<< nViajes << endl;
    cout << "Media de las valoraciones del usuario: " << mediaSatisfaccion << endl;
    cout << "Media de los ocupantes del vehiculo: " << mediaOcupantes << endl;
}

float Lista::estadistica(int tipo, int dia)
{
    // 1: valoracion; 2: ocupantes; 3: viajes

    float mediaSatisfaccion = 0;
    float mediaOcupantes = 0;
    float nViajes = 0;

    if (!listaVacia())
    {
        pNodoLista aux = primero;
        while(aux != NULL)
        {
            if (dia == 0 || dia == aux->getViaje()->getDia())
            {
                nViajes ++;
                mediaSatisfaccion += aux->getViaje()->getValoracion();
                mediaOcupantes += aux->getViaje()->getOcupantes();

            }
            aux = aux->siguiente;
        }
        if (nViajes != 0)
        {
            mediaOcupantes /= nViajes;
            mediaSatisfaccion /= nViajes;
        }
    }
    if (tipo == 1)
        {
            return mediaSatisfaccion;
        }
    if (tipo == 2)
        {
            return mediaOcupantes;
        }
    if (tipo == 3)
        {
            return nViajes;
        }
    return 0;
}

/** Testea algunos casos de prueba de la clase Lista
 */
void test_Lista()
{
    cout << "# Test Lista" << endl;
    cout << "Lista: viaje random" << endl;
    pViaje punteroViaje = new Viaje("asdasd", "afgs");
    pViaje punteroViaje1 = new Viaje("asdhfsd", "dfgdfgas");
    pViaje punteroViaje2 = new Viaje("asdkkkk", "dfgdgggs");

    pNodoLista punteroNodo;
    punteroNodo = new NodoLista(punteroViaje);
    NodoLista n1 = *punteroNodo;
    n1.write();
    // Creamos un puntero y almacenamos en el el puntero del nodo al vehiculo.
    // En el v4 almacenamos el contenido del puntero. Printeamos
    pViaje p1 = n1.getViaje();
    Viaje v4 = *p1;
    v4.write();
    // Lo mismo, pero nos ahorramos crear un puntero. Al vehículo se le pasa directamente el del nodo.
    Viaje v5 = *n1.getViaje();
    v5.write();

    pLista l1 = new Lista();


    l1->insertarNodo(punteroViaje);
    cout << "Buscar viaje (True): " << l1->buscarViaje(punteroViaje) << endl;
    cout << "Buscar viaje (False): " <<l1->buscarViaje(punteroViaje1) << endl;
    l1->write();

     cout << "Borrar viajes" << endl;
    Lista l2 ;
    l2.insertarNodo(punteroViaje);
    l2.insertarNodo(punteroViaje1);
    l2.insertarNodo(punteroViaje2);
    l2.write();
    l2.borrarViaje(punteroViaje1);
    l2.write();
    pViaje punteroViaje3 = new Viaje("asdkkkk", "dfgdgggs");
    punteroViaje3->setValoracion(0);
    punteroViaje3->write();
    cout << l2.buscarViaje(punteroViaje3) <<endl;
    l2.modificarViaje(punteroViaje3);
    l2.write();

    l2.estadisticas();
}
