#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Insert node at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to detect and remove loop
void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    // No loop
    if (slow != fast) return;

    // Step 2: Find start of loop
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove loop
    fast->next = NULL;
}

// Print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    // Build list using insertAtEnd
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    // Create loop: last node points back to node 2
    head->next->next->next->next->next = head->next;

    cout << "Loop created in linked list.\n";

    // Remove loop
    removeLoop(head);

    cout << "List after removing loop:\n";
    printList(head);

    return 0;
}
