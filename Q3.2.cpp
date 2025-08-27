#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        s.push(c);
    }

    cout << "Reversed string: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}
