#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayCircularList(Node* head) {
    if (!head) return;
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; // repeating head node value
}

int main() {
    Node* head = new Node{20, NULL};
    Node* second = new Node{100, NULL};
    Node* third = new Node{40, NULL};
    Node* fourth = new Node{80, NULL};
    Node* fifth = new Node{60, NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;  // circular connection

    displayCircularList(head);
    return 0;
}
