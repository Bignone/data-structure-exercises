#include "ArbolBB.h"
#include <iostream>
#include "NodoArbol.h"

ArbolBB::ArbolBB()
{
    raiz = NULL;
}
ArbolBB::~ArbolBB()
{
    podar(raiz);
}

// Insertar un int en el �rbol ABB
void ArbolBB::insertar(pVehiculo vehiculo)
{
    NodoArbol *padre = NULL;

    actual = raiz;
    // Buscar el int en el �rbol, manteniendo un puntero al nodo padre
    while(!vacio(actual) && vehiculo != actual->vehiculo)
    {
        padre = actual;
        if(vehiculo > actual->vehiculo)
            actual = actual->derecho;
        else if(vehiculo < actual->vehiculo)
            actual = actual->izquierdo;
    }

    // Si se ha encontrado el elemento, regresar sin insertar
    if(!vacio(actual))
        return;
    // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
    // el nodo raiz
    if(vacio(padre))
        raiz = new NodoArbol(vehiculo);
    // Si el int es menor que el que contiene el nodo padre, lo insertamos
    // en la rama izquierda
    else if(vehiculo < padre->vehiculo)
    //else if(vehiculo.compare(padre->vehiculo) < 0 )
        padre->izquierdo = new NodoArbol(vehiculo);
    // Si el int es mayor que el que contiene el nodo padre, lo insertamos
    // en la rama derecha
    else if(vehiculo > padre->vehiculo)
        padre->derecho = new NodoArbol(vehiculo);
}


// Eliminar un elemento de un �rbol ABB
void ArbolBB::borrar(pVehiculo vehiculo)
{
    pNodoArbol padre = NULL;
    pNodoArbol nodo;
    pVehiculo aux;

    actual = raiz;
    // Mientras sea posible que el valor est� en el �rbol
    while(!vacio(actual))
    {
        if(vehiculo == actual->vehiculo)   // Si el valor est� en el nodo actual
        {
            if(esHoja(actual))   // Y si adem�s es un nodo hoja: lo borramos
            {
                if(padre)  // Si tiene padre (no es el nodo raiz)
                {
                    // Anulamos el puntero que le hace referencia
                    if(padre->derecho == actual)
                        padre->derecho = NULL;
                    else if(padre->izquierdo == actual)
                        padre->izquierdo = NULL;
                }
                delete actual; // Borrar el nodo
                actual = NULL;
                return;
            }
            else   // Si el valor est� en el nodo actual, pero no es hoja
            {
                // Buscar nodo
                padre = actual;
                // Buscar nodo m�s izquierdo de rama derecha
                if(actual->derecho)
                {
                    nodo = actual->derecho;
                    while(nodo->izquierdo)
                    {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                // O buscar nodo m�s derecho de rama izquierda
                else
                {
                    nodo = actual->izquierdo;
                    while(nodo->derecho)
                    {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                // Intercambiar valores de no a borrar u nodo encontrado
                // y continuar, cerrando el bucle. El nodo encontrado no tiene
                // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que s�lo se eliminan nodos hoja.
                aux = actual->vehiculo;
                actual->vehiculo = nodo->vehiculo;
                nodo->vehiculo = aux;
                actual = nodo;
            }
        }
        else   // Todav�a no hemos encontrado el valor, seguir busc�ndolo
        {
            padre = actual;
            if(vehiculo > actual->vehiculo)
                actual = actual->derecho;
            else if(vehiculo < actual->vehiculo)
                actual = actual->izquierdo;
        }
    }
}

// Buscar un valor en el �rbol
bool ArbolBB::buscar(pVehiculo vehiculo)
{
    actual = raiz;

    // Todav�a puede aparecer, ya que quedan nodos por mirar
    while(!vacio(actual))
    {
        if(vehiculo == actual->vehiculo)
            return true; // int encontrado
        else if(vehiculo > actual->vehiculo)
            actual = actual->derecho; // Seguir
        else if(vehiculo < actual->vehiculo)
            actual = actual->izquierdo;
    }
    return false; // No est� en �rbol
}

bool ArbolBB::vacio(pNodoArbol r)
{
    return r == NULL;
}

bool ArbolBB::esHoja(pNodoArbol r)
{
    return !r->derecho && !r->izquierdo;
}

// Calcular la altura del nodo que contiene el int dat
int ArbolBB::getAltura(pVehiculo vehiculo)
{
    int altura = 0;
    actual = raiz;

    // Todav�a puede aparecer, ya que quedan nodos por mirar
    while(!vacio(actual))
    {
        if(vehiculo == actual->vehiculo)
            return altura; // int encontrado
        else
        {
            altura++; // Incrementamos la altura, seguimos buscando
            if(vehiculo > actual->vehiculo)
                actual = actual->derecho;
            else if(vehiculo < actual->vehiculo)
                actual = actual->izquierdo;
        }
    }
    return -1; // No est� en �rbol
}

pNodoArbol ArbolBB::getRaiz()
{
    return raiz;
}

pNodoArbol ArbolBB::getValorActual()
{
    return actual;
}

pVehiculo ArbolBB::getActualVehiculo()
{
    return actual->vehiculo;
}

void ArbolBB::raizActual()
{
    actual = raiz;
}

// Poda: borrar todos los nodos a partir de uno, incluido
void ArbolBB::podar(NodoArbol* &nodo)
{
    // Algoritmo recursivo, recorrido en postorden
    if(nodo)
    {
        podar(nodo->izquierdo); // Podar izquierdo
        podar(nodo->derecho);   // Podar derecho
        delete nodo;            // Eliminar nodo
        nodo = NULL;
    }
}



// Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolBB::inOrden(void (*func)(pVehiculo), pNodoArbol nodo, bool r)
{
    if(r)
        nodo = raiz;
    if(nodo->izquierdo)
        inOrden(func, nodo->izquierdo, false);
    func(nodo->vehiculo);
    if(nodo->derecho)
        inOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolBB::preOrden(void (*func)(pVehiculo), pNodoArbol nodo, bool r)
{
    if(r)
        nodo = raiz;
    func(nodo->vehiculo);
    if(nodo->izquierdo)
        preOrden(func, nodo->izquierdo, false);
    if(nodo->derecho)
        preOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolBB::postOrden(void (*func)(pVehiculo), pNodoArbol nodo, bool r)
{
    if(r)
        nodo = raiz;
    if(nodo->izquierdo)
        postOrden(func, nodo->izquierdo, false);
    if(nodo->derecho)
        postOrden(func, nodo->derecho, false);
    func(nodo->vehiculo);
}





// Contar el n�mero de nodos
const int ArbolBB::numeroNodos()
{
    contador = 0;

    auxContador(raiz); // FUnci�n auxiliar
    return contador;
}

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolBB::auxContador(pNodoArbol nodo)
{
    contador++;  // Otro nodo
    // Continuar recorrido
    if(nodo->izquierdo)
        auxContador(nodo->izquierdo);
    if(nodo->derecho)
        auxContador(nodo->derecho);
}

// Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
const int ArbolBB::alturaArbol()
{
    altura = 0;

    auxAltura(raiz, 0); // Funci�n auxiliar
    return altura;
}

// Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
// postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
// altura de la m�xima actual
void ArbolBB::auxAltura(pNodoArbol nodo, int a)
{
    // Recorrido postorden
    if(nodo->izquierdo)
        auxAltura(nodo->izquierdo, a+1);
    if(nodo->derecho)
        auxAltura(nodo->derecho, a+1);
    // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
    // �rbol, actualizamos la altura actual del �rbol
    if(esHoja(nodo) && a > altura)
        altura = a;
}

void ArbolBB::writeNodoArbol(pNodoArbol nodo)
{
    if(nodo->izquierdo)
        writeNodoArbol(nodo->izquierdo);
    nodo->write();
    if(nodo->derecho)
        writeNodoArbol(nodo->derecho);
}

void ArbolBB::write()
{
    writeNodoArbol(raiz);
}

void writeVehiculo(pVehiculo v)
{
    v->write();
}

void test_ArbolBB()
{
    pVehiculo punteroVehiculo1 = new Vehiculo();
    pVehiculo punteroVehiculo2 = new Vehiculo();
    pVehiculo punteroVehiculo3 = new Vehiculo();

    ArbolBB arbolBB;
    arbolBB.insertar(punteroVehiculo1);
    cout << "Numero nodos (1 vehiculos): " << arbolBB.numeroNodos() << endl;
    cout << "Altura arbol (1 vehiculos): " << arbolBB.alturaArbol() << endl;
    cout << "Find vehiculo (True): " << arbolBB.buscar(punteroVehiculo1) << endl;
    cout << "Find vehiculo (False): " << arbolBB.buscar(punteroVehiculo2) << endl;
    arbolBB.insertar(punteroVehiculo2);
    cout << "Altura arbol (2 vehiculos): " << arbolBB.alturaArbol() << endl;
    cout << "Numero nodos (2 vehiculos): " << arbolBB.numeroNodos() << endl;

    arbolBB.insertar(punteroVehiculo3);
    arbolBB.borrar(punteroVehiculo3);
    cout << "Borrar vehiculo (find deleted: False): " << arbolBB.buscar(punteroVehiculo3) << endl;
    cout << "Buscar vehiculo (True): " << arbolBB.buscar(punteroVehiculo1) << endl;

    cout << "Arbol write Vehiculos: " << endl;
    arbolBB.inOrden(writeVehiculo, arbolBB.getRaiz(), false);

    cout << "Arbol write Nodos: " << endl;
    arbolBB.write();


}
