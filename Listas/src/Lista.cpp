#include "Lista.h"

Lista::Lista(pNodo prim, pNodo ult)
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
void Lista::writeNodo(Nodo *punteroNodo)
{
    if (punteroNodo)
    {
        // imprimir utilizando los punteros (->) sin traer los objetos a memoria
        punteroNodo->getAlumno().write();
        writeNodo(punteroNodo->siguiente);

    }

}
pNodo Lista::getPrimero()
{
    return primero;
}

pNodo Lista::getUltimo()
{
    return ultimo;
}

bool Lista::listaVacia()
{
    return primero == NULL;
}

void Lista::insertarNodo(Alumno a)
{   pNodo aux;
    if(listaVacia())
    {
        primero = new Nodo(a, NULL);
        ultimo = primero;
    }
    else
    {
        aux = new Nodo(a, NULL);
        ultimo->siguiente = aux;
        ultimo = aux;
    }
}

void Lista::borrarNodo(Alumno a)
{   pNodo anterior;
    pNodo actual;
    actual = primero;
    while (!actual->valor.compare(a) && (actual->siguiente)!=NULL)
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    if(actual == primero)
        primero = actual->siguiente;
    else{
        anterior->siguiente = actual->siguiente;
        if(actual == ultimo){
            ultimo = anterior;
        }
    }
    actual->siguiente=NULL;
    delete actual;
}
