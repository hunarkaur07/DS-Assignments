#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// insert node at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, NULL};
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

// find middle node
int findMiddle(Node* head) {
    if (head == NULL) return -1; // empty list

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // move 1 step
        fast = fast->next->next;  // move 2 steps
    }
    return slow->data;
}

int main() {
    Node* head = NULL;

    // create linked list: 1->2->3->4->5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "Linked List: ";
    display(head);

    int mid = findMiddle(head);
    cout << "Middle element: " << mid << endl;

    return 0;
}
