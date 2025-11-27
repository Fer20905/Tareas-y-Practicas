#include <iostream>
using namespace std;

#define MAX 5

class ColaCircular {
private:
    int datos[MAX];
    int frente;
    int final;
    int size;

public:
    ColaCircular() {
        frente = 0;
        final = 0;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    void enqueue(int valor) {
        if (isFull()) {
            cout << "La cola esta llena, no se puede encolar " << valor << endl;
            return;
        }
        datos[final] = valor;
        final = (final + 1) % MAX;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "La cola esta vacia" << endl;
            return -1;
        }
        int valor = datos[frente];
        frente = (frente + 1) % MAX;
        size--;
        return valor;
    }

    int peek() {
        if (isEmpty()) return -1;
        return datos[frente];
    }

    void printQueue() {
        cout << "Cola: ";
        if (isEmpty()) {
            cout << "(vacia)" << endl;
        } else {
            int i = frente;
            for (int k = 0; k < size; k++) {
                cout << datos[i] << " ";
                i = (i + 1) % MAX;
            }
            cout << endl;
        }

        cout << "Frente: " << frente
             << " | Final: " << final
             << " | Size: " << size << endl;
    }
};

int main() {
    ColaCircular c;

    c.enqueue(5);
    c.enqueue(10);
    c.enqueue(15);
    c.printQueue();

    c.dequeue();
    c.printQueue();

    c.enqueue(20);
    c.enqueue(25);
    c.enqueue(30);
    c.printQueue();

    return 0;
}
