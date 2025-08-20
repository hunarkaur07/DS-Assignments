#include<iostream>
using namespace std;

int main() {
    int arr[6] = {1,2,3,4,5,6}; 
    int size = 6;
    int n = 0;

    while (n*(n+1)/2 < size) {
        n++;
    }

    cout << "Symmetric matrix:" << endl;

    int index = 0;
    int mat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            mat[i][j] = arr[index++];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            mat[i][j] = mat[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
    
}
