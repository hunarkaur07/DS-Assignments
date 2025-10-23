#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitCircularList(Node* head, Node** head1_ref, Node** head2_ref) {
    Node* slow = head;
    Node* fast = head;

    if (head == NULL) return;

    // Use slow and fast pointers
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For odd number of nodes, move fast one step further
    if (fast->next->next == head)
        fast = fast->next;

    // Set the heads of the two halves
    *head1_ref = head;
    if (head->next != head)
        *head2_ref = slow->next;

    // Make first half circular
    fast->next = slow->next;
    // Make second half circular
    slow->next = head;
}

void printCircularList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};
    head->next->next->next->next = new Node{5, NULL};
    head->next->next->next->next->next = head; // circular

    Node *head1 = NULL, *head2 = NULL;
    splitCircularList(head, &head1, &head2);

    cout << "First Circular List: ";
    printCircularList(head1);
    cout << "Second Circular List: ";
    printCircularList(head2);

    return 0;
}
