#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool isMaxHeap) {
    int extreme = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMaxHeap) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i) {
        int temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        heapify(arr, n, extreme, isMaxHeap);
    }
}

void heapSort(int arr[], int n, bool increasing = true) {
    bool isMaxHeap = increasing;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, isMaxHeap);
    }

    if (!increasing) {
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }
}

int main() {
    int arr[] = {20, 5, 15, 22, 40, 3, 10};
    int n = 7;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n, true);
    cout << "Sorted in Increasing Order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n, false);
    cout << "Sorted in Decreasing Order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
