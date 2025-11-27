#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = valor;

    if (*cabeza == nullptr) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *cabeza = nuevo;
    }
}

void recorrerCircular(Nodo *cabeza) {
    if (cabeza == nullptr) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo *aux = cabeza;

    cout << "Lista Circular: ";
    do {
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    } while (aux != cabeza);

    cout << "(vuelve al inicio)\n";
}

void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    if (*cabeza == nullptr) return;

    Nodo *actual = *cabeza;
    Nodo *anterior = *ultimo;

    do {
        if (actual->dato == valor) {
            if (actual == *cabeza) {
                *cabeza = (*cabeza)->siguiente;
                (*ultimo)->siguiente = *cabeza;
            }
            if (actual == *ultimo) {
                *ultimo = anterior;
            }
            anterior->siguiente = actual->siguiente;
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);
}

void liberarCircular(Nodo *cabeza) {
    if (cabeza == nullptr) return;

    Nodo *actual = cabeza->siguiente;

    while (actual != cabeza) {
        Nodo *tmp = actual;
        actual = actual->siguiente;
        delete tmp;
    }

    delete cabeza;
    cout << "Memoria liberada correctamente\n";
}

int main() {
    Nodo *cabeza = nullptr;
    Nodo *ultimo = nullptr;

    int n, valor;
    cout << "Cuantos valores insertar?: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Valor: ";
        cin >> valor;
        insertarCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    cout << "Valor a eliminar: ";
    cin >> valor;
    eliminarCircular(&cabeza, &ultimo, valor);
    recorrerCircular(cabeza);

    liberarCircular(cabeza);
    return 0;
}
