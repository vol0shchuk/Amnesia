#include <iostream>
#include <cstring>
using namespace std;

class Queue {
private:
    struct Node {
        char* data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(const char* value) {
        Node* newNode = new Node;
        newNode->data = new char[strlen(value) + 1];
        strcpy(newNode->data, value);
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete[] temp->data;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    const char* peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek.\n";
            return nullptr;
        }

        return front->data;
    }
};

int main() {
    Queue charQueue;

    charQueue.enqueue("Hello");
    charQueue.enqueue("World");

    cout << "Peek: " << charQueue.peek() << endl;

    charQueue.dequeue();

    cout << "Peek after dequeue: " << charQueue.peek() << endl;

    return 0;
}
