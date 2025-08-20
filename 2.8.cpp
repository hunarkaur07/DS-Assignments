#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int A[n];
    cout << "Enter elements of array:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int distinct = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            distinct++;
    }

    cout << "Total number of distinct elements: " << distinct << endl;
    return 0;
}
