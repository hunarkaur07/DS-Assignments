#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// insert at end
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

// display linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// reverse linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;     // save next
        curr->next = prev;     // reverse link
        prev = curr;           // move prev ahead
        curr = next;           // move curr ahead
    }
    return prev; // new head
}

int main() {
    Node* head = NULL;

    // create list 1->2->3->4->NULL
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);

    cout << "Original Linked List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    display(head);

    return 0;
}
