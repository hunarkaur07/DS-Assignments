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

    int count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (A[i] > A[j])
                count++;

        }
    }

    cout << "Number of inversions in the array: " << count << endl;
    return 0;
}
//inversion pairs are those where(i,j)-> (i>j)