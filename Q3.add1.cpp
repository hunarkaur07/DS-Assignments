#include <iostream>
using namespace std;

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> G(A.size());
    stack<int> s;

    for (int i = 0; i < A.size(); i++) {
        while (!s.empty() && s.top() >= A[i]) {
            s.pop();
        }
        if (s.empty())
            G[i] = -1;
        else
            G[i] = s.top();

        s.push(A[i]);
    }

    cout << "Nearest Smaller to Left: ";
    for (int x : G) cout << x << " ";
    return 0;
}
