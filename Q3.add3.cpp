#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;
    int nge[n];

    // For each element
    for (int i = 0; i < n; i++) {
        int next = -1; // Default
        // right elements
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                next = arr[j];
                break; // 1st greatest element
            }
        }
        nge[i] = next;
    }

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}
