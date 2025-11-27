#include <iostream>
using namespace std;

#define MAX 5

class Deque {
private:
    int datos[MAX];
    int front;
    int size;

public:
    Deque() {
        front = 0;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    int rearIndex() {
        return (front + size - 1 + MAX) % MAX;
    }

    void insert_front(int valor) {
        if (isFull()) {
            cout << "Deque lleno, no se puede insertar al frente\n";
            return;
        }
        front = (front - 1 + MAX) % MAX;
        datos[front] = valor;
        size++;
    }

    void insert_rear(int valor) {
        if (isFull()) {
            cout << "Deque lleno, no se puede insertar atras\n";
            return;
        }
        int rear = (front + size) % MAX;
        datos[rear] = valor;
        size++;
    }

    int delete_front() {
        if (isEmpty()) {
            cout << "Deque vacio\n";
            return -1;
        }
        int valor = datos[front];
        front = (front + 1) % MAX;
        size--;
        return valor;
    }

    int delete_rear() {
        if (isEmpty()) {
            cout << "Deque vacio\n";
            return -1;
        }
        int rear = rearIndex();
        int valor = datos[rear];
        size--;
        return valor;
    }

    int peek_front() {
        if (isEmpty()) return -1;
        return datos[front];
    }

    int peek_rear() {
        if (isEmpty()) return -1;
        return datos[rearIndex()];
    }

    void printDeque() {
        cout << "Deque: ";
        if (isEmpty()) {
            cout << "(vacio)" << endl;
        } else {
            int i = front;
            for (int k = 0; k < size; k++) {
                cout << datos[i] << " ";
                i = (i + 1) % MAX;
            }
            cout << endl;
        }

        cout << "Front: " << front
             << " | Rear: " << rearIndex()
             << " | Size: " << size << endl;
    }
};

int main() {
    Deque d;

    d.insert_front(10);
    d.insert_rear(15);
    d.insert_rear(20);
    d.insert_front(30);
    d.insert_rear(40);

    d.printDeque();

    d.delete_front();
    d.delete_rear();

    d.printDeque();

    return 0;
}
