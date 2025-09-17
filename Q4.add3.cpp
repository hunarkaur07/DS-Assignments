#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int>& q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == expected) {
            expected++;
        } 
        else {
            // Pop from stack if top matches expected
            while (!st.empty() && st.top() == expected) {
                st.pop();
                expected++;
            }

            // If stack top is smaller than curr → order breaks
            if (!st.empty() && st.top() < curr)
                return false;

            st.push(curr);
        }
    }

    // Empty stack if possible
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    return (expected == n + 1);
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (checkSorted(q))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
