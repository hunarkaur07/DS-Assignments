//exact diff pairs
#include <iostream>
#include <cmath> // for abs
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5}; //4,2  3,1  5,3 = 3 output 
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                cnt++;
            }
        }
    }

    cout << "Count = " << cnt;
    return 0;
}
