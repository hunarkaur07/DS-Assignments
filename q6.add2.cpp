#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to delete even nodes from a doubly linked list
Node* removeEvenDoubly(Node* head) {
    Node* temp = head;
    while (temp) {
        Node* nextNode = temp->next;
        if (temp->data % 2 == 0) {
            if (temp->prev)
                temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp == head)
                head = temp->next;
            delete temp;
        }
        temp = nextNode;
    }
    return head;
}

// Function to delete even nodes from circular linked list
void removeEvenCircular(Node*& head) {
    if (!head) return;
    Node* curr = head;
    Node* prev = NULL;

    do {
        if (curr->data % 2 == 0) {
            if (curr == head) {
                Node* temp = head;
                while (temp->next != head)
                    temp = temp->next;
                head = head->next;
                temp->next = head;
                delete curr;
                curr = head;
                prev = temp;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    } while (curr != head);
}

void displayCircular(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void displayDoubly(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Doubly Linked List
    Node* d1 = new Node{1, NULL, NULL};
    Node* d2 = new Node{2, NULL, d1};
    Node* d3 = new Node{3, NULL, d2};
    d1->next = d2; d2->next = d3;

    cout << "Original Doubly LL: ";
    displayDoubly(d1);
    d1 = removeEvenDoubly(d1);
    cout << "After Removing Even: ";
    displayDoubly(d1);

    // Circular Linked List
    Node* c1 = new Node{10, NULL, NULL};
    Node* c2 = new Node{15, NULL, NULL};
    Node* c3 = new Node{20, NULL, NULL};
    c1->next = c2; c2->next = c3; c3->next = c1;

    cout << "Original Circular LL: ";
    displayCircular(c1);
    removeEvenCircular(c1);
    cout << "After Removing Even: ";
    displayCircular(c1);

    return 0;
}
