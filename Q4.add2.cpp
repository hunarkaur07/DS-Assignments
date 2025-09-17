#include <iostream>
#include <queue>
using namespace std;

//Function to get minimum index in first n elements
int minIndex(queue<int>& q, int sortedIndex) {
    int min_index = -1;
    int min_value = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        //if this element is smaller and still in unsorted part
        if (curr <= min_value && i <= sortedIndex) {
            min_value = curr;
            min_index = i;
        }
        q.push(curr); //put element back
    }
    return min_index;
}

//Function to move min at the end of queue
void insertMinToRear(queue<int>& q, int min_index) {
    int n = q.size();
    int min_value;
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i == min_index)
            min_value = curr;
        else
            q.push(curr);
    }
    q.push(min_value);
}

//Sorting function
void sortQueue(queue<int>& q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout << "Sorted Queue: "; 
    //this will print all the elements from the sorted queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
