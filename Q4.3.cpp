#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;// this is the main queue to store full queue
    int arr[] = {4, 7, 11, 20, 5, 9}; //our input
    int n = sizeof(arr) / sizeof(arr[0]);//num of elements

    // Step 1: Put elements in queue-rear
    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    // Step 2: Divide into two halves
    int half = n / 2;
    queue<int> firstHalf;//this is a temp queue to store the first half

    // Move first half into another queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());//copy elements from front to first half
        q.pop();//remove them //now q = 20 5 9 firsthalf = 4 7 11
    }

    // Step 3: Interleave both halves
    while (!firstHalf.empty()) {
        // Take from first half
        q.push(firstHalf.front());
        firstHalf.pop();//remove it

        // Take from second half (from original queue)
        q.push(q.front());
        q.pop();//remove from old position
    }

    // Step 4: Display result
    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();//remove after printing
    }

    return 0;
}
