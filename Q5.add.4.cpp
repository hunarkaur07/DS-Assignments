#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to rotate left by k
Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Find length of list
    int n = 1;
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
        n++;
    }

    k = k % n;  // normalize k
    if (k == 0) return head;

    // Step 2: Traverse to kth node
    Node* curr = head;
    for (int i = 1; i < k; i++) {
        curr = curr->next;
    }

    // Step 3: New head is (k+1)-th node
    Node* newHead = curr->next;
    curr->next = NULL;  // break list

    // Step 4: Connect last node to old head
    temp->next = head;

    return newHead;
}

// Utility function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    cout << "Original List: ";
    printList(head);

    head = rotateLeft(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
