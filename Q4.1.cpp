#include <iostream>
using namespace std;

#define SIZE 5  // maximum capacity of our queue

class SimpleQueue {
    int arr[SIZE];
    int front, rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add " << value << "\n";
            return;
        }
        if (front == -1) front = 0;  // first element added
        arr[++rear] = value;
        cout << value << " added to queue\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Nothing to remove\n";
            return;
        }
        cout << arr[front] << " removed from queue\n";
        if (front == rear) {
            // queue becomes empty again
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
        } else {
            cout << "Front element: " << arr[front] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    SimpleQueue q;
    int choice, value;

    do {
        cout << "\n--- Simple Queue ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
