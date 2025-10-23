#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (!head)
        return false;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    // Linked list 1: Not circular
    Node* head1 = new Node{10, NULL};
    head1->next = new Node{20, NULL};
    head1->next->next = new Node{30, NULL};

    // Linked list 2: Circular
    Node* head2 = new Node{1, NULL};
    head2->next = new Node{2, NULL};
    head2->next->next = new Node{3, NULL};
    head2->next->next->next = head2; // makes it circular

    cout << "List 1: " << (isCircular(head1) ? "Circular" : "Not Circular") << endl;
    cout << "List 2: " << (isCircular(head2) ? "Circular" : "Not Circular") << endl;

    return 0;
}
