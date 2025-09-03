#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed\n";
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << q.front() << " popped\n";
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Top: " << q.front() << "\n";
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Stack: ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};

int main() {
    StackUsingOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.top();
    return 0;
}
