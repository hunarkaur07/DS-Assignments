#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int arr[] = {2, 3, 4, 6, 5, 7};  
    int k = 0;                 
    
    cout << "\nTridiagonal Matrix form:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << "1 ";
            }
            else if (i == j + 1 || i == j - 1) {
                cout << arr[k++]<< " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;

}
