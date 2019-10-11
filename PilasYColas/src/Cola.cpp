#include "Cola.h"
#include <cstddef>

Cola::Cola()
{
    frente = NULL;
    finall = NULL;
}

Cola::~Cola()
{
    while(frente) desencolar();
}

//A�adir elemento en la cola
void Cola::encolar(int v)
{
    pNodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
    // Si cola no vac�a, se a�ade el nuevo a continuaci�n de ultimo
    if(finall) finall->siguiente = nuevo;
    //El �ltimo elemento de la cola es el nuevo nodo
    finall= nuevo;
    // Si 1� es NULL, la cola vac�a, 1� apunta al nuevo nodo
    if(!frente) frente = nuevo;
}

//Leer elemento de la cola
int Cola::desencolar()
{
    pNodo nodo; //Var aux para manipular nodo
    int v; //Var aux para retorno del valor
    // Nodo apunta al primer elemento de la pila
    nodo = frente;
    if(!nodo) return 0; // Si no hay nodos en la pila se devuelve 0
    //Se asigna a 1� la direcci�n del segundo nodo
    frente = nodo->siguiente;
    //Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
    // Si cola vac�a, ultimo debe ser NULL tambi�n
    if(!frente) finall = NULL;
    return v;
}
