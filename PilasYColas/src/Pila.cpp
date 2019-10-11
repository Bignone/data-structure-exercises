#include "Pila.h"
#include <cstddef>

Pila::Pila()
{
    cima = NULL;
}

Pila::~Pila()
{
    while(cima) desapilar();
}

//Meter elemento en la Pila
void Pila::apilar(int v)
    {
    pNodo nuevo; //Var aux para manipular el nuevo nodo
    //Se crea un nodo nuevo
    nuevo = new Nodo(v, cima);
    //El comienzo de la pila es el nuevo nodo
    cima = nuevo;
}

//Sacar elemento de la Pila
int Pila::desapilar()
{
    pNodo nodo; //Var aux para manipular el nodo
    int v; //Var aux para el retorno del valor del nodo
    if(!cima) return 0; // Si no hay nodos en la pila se devuelve 0
    // Nodo apunta al primer elemento de la pila
    nodo = cima;
    //Se asigna a pila toda la pila menos el primer elemento
    cima= nodo->siguiente;
    //Se guarda el retorno del valor del nodo
    v = nodo->valor;
    //Se borra el nodo
    delete nodo;
    return v;
}
