#include <iostream>
#include <stack>
using namespace std;

void isBalanced(string exp) {
    stack<char> s;
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') { //if opening bracket then we ll push
            s.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) { //we ll check if stack is empty
                cout << "Not Balanced" << endl;
                return;
            }
            char top = s.top(); //not empty--check if matches with top--if matches ok
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                cout << "Not Balanced" << endl;
                return;
            }
        }
    }
    if (s.empty()) //if stack empty only then this will be printed
        cout << "Balanced Parentheses" << endl;
    else
        cout << "Not Balanced" << endl;
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    isBalanced(exp);
    return 0;
}
