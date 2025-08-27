#include <iostream>
using namespace std;

#define MAX 100
int stack_arr[MAX];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

void push(int data) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << data << endl;
        return;
    }
    stack_arr[++top] = data;
    cout << data << " pushed into stack." << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Nothing to pop." << endl;
        return;
    }
    cout << stack_arr[top--] << " popped from stack." << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Top element: " << stack_arr[top] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack_arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
