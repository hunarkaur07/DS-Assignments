#include <iostream>
using namespace std;

class PriorityQueue {
    int heap[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int val) {
        size++;
        int i = size - 1;
        heap[i] = val;

        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[(i - 1) / 2];
            heap[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }

    void remove() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }

        heap[0] = heap[size - 1];
        size--;

        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                int temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;
                i = largest;
            } else
                break;
        }
    }

    int getMax() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(40);
    pq.insert(15);
    pq.insert(30);
    pq.insert(10);
    pq.insert(50);

    cout << "Priority Queue Elements: ";
    pq.display();

    cout << "Maximum Element: " << pq.getMax() << endl;

    pq.remove();
    cout << "After removing max, Queue: ";
    pq.display();

    return 0;
}