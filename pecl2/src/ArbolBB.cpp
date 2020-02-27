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

// Insertar un int en el árbol ABB
void ArbolBB::insertar(pVehiculo vehiculo)
{
    NodoArbol *padre = NULL;

    actual = raiz;
    // Buscar el int en el árbol, manteniendo un puntero al nodo padre
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
    // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
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


// Eliminar un elemento de un árbol ABB
void ArbolBB::borrar(pVehiculo vehiculo)
{
    pNodoArbol padre = NULL;
    pNodoArbol nodo;
    pVehiculo aux;

    actual = raiz;
    // Mientras sea posible que el valor esté en el árbol
    while(!vacio(actual))
    {
        if(vehiculo == actual->vehiculo)   // Si el valor está en el nodo actual
        {
            if(esHoja(actual))   // Y si además es un nodo hoja: lo borramos
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
            else   // Si el valor está en el nodo actual, pero no es hoja
            {
                // Buscar nodo
                padre = actual;
                // Buscar nodo más izquierdo de rama derecha
                if(actual->derecho)
                {
                    nodo = actual->derecho;
                    while(nodo->izquierdo)
                    {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                // O buscar nodo más derecho de rama izquierda
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
                // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que sólo se eliminan nodos hoja.
                aux = actual->vehiculo;
                actual->vehiculo = nodo->vehiculo;
                nodo->vehiculo = aux;
                actual = nodo;
            }
        }
        else   // Todavía no hemos encontrado el valor, seguir buscándolo
        {
            padre = actual;
            if(vehiculo > actual->vehiculo)
                actual = actual->derecho;
            else if(vehiculo < actual->vehiculo)
                actual = actual->izquierdo;
        }
    }
}

// Buscar un valor en el árbol
bool ArbolBB::buscar(pVehiculo vehiculo)
{
    actual = raiz;

    // Todavía puede aparecer, ya que quedan nodos por mirar
    while(!vacio(actual))
    {
        if(vehiculo == actual->vehiculo)
            return true; // int encontrado
        else if(vehiculo > actual->vehiculo)
            actual = actual->derecho; // Seguir
        else if(vehiculo < actual->vehiculo)
            actual = actual->izquierdo;
    }
    return false; // No está en árbol
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

    // Todavía puede aparecer, ya que quedan nodos por mirar
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
    return -1; // No está en árbol
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



// Recorrido de árbol en inorden, aplicamos la función func, que tiene
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

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
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

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
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





// Contar el número de nodos
const int ArbolBB::numeroNodos()
{
    contador = 0;

    auxContador(raiz); // FUnción auxiliar
    return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
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

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int ArbolBB::alturaArbol()
{
    altura = 0;

    auxAltura(raiz, 0); // Función auxiliar
    return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void ArbolBB::auxAltura(pNodoArbol nodo, int a)
{
    // Recorrido postorden
    if(nodo->izquierdo)
        auxAltura(nodo->izquierdo, a+1);
    if(nodo->derecho)
        auxAltura(nodo->derecho, a+1);
    // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
    // árbol, actualizamos la altura actual del árbol
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
