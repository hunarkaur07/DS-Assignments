#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << x << " pushed\n";
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Top: " << q1.front() << "\n";
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Stack: ";
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};

int main() {
    StackUsingTwoQueues s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.top();
    return 0;
}
