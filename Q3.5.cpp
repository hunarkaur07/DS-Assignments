#include <iostream>
#include <stack>
using namespace std;

void evaluatePostfix(string exp) {
    stack<int> s;//empty stack to store integers
    for (int i = 0; i < exp.length(); i++) {//to read each character
        char ch = exp[i];
        if (isdigit(ch)) {
            s.push(ch - '0');//coverts character into integer using ascii value conversion
        } else {
            int val2 = s.top(); s.pop(); //val2 is 2nd operand
            int val1 = s.top(); s.pop(); //val1 is 1st operand
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    cout << "Result: " << s.top() << endl;
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single digits): ";
    cin >> postfix;
    evaluatePostfix(postfix);
    return 0;
}
