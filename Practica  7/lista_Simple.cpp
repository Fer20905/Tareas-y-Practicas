#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarInicio(Nodo **cabeza, int valor) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void recorrer(Nodo *cabeza) {
    Nodo *aux = cabeza;
    cout << "Lista: ";
    while (aux != nullptr) {
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }
    cout << "NULL\n";
}

void eliminar(Nodo **cabeza, int valor) {
    if (*cabeza == nullptr) return;

    Nodo *actual = *cabeza;
    Nodo *anterior = nullptr;

    if (actual->dato == valor) {
        *cabeza = actual->siguiente;
        delete actual;
        return;
    }

    while (actual != nullptr && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) return;

    anterior->siguiente = actual->siguiente;
    delete actual;
}

void liberar(Nodo *cabeza) {
    Nodo *actual = cabeza;
    while (actual != nullptr) {
        Nodo *tmp = actual;
        actual = actual->siguiente;
        delete tmp;
    }
    cout << "Memoria liberada correctamente\n";
}

int main() {
    Nodo *cabeza = nullptr;
    int n, valor;

    cout << "Cuantos valores deseas insertar?: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Valor: ";
        cin >> valor;
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    cout << "Valor a eliminar: ";
    cin >> valor;
    eliminar(&cabeza, valor);
    recorrer(cabeza);

    liberar(cabeza);
    return 0;
}
