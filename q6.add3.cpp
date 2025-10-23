#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* reverseKGroup(Node* head, int k) {
    Node* current = head;
    Node* nextNode = NULL;
    Node* newHead = NULL;
    int count = 0;

    // reverse first k nodes
    while (current && count < k) {
        nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        newHead = current;
        current = nextNode;
        count++;
    }

    if (nextNode != NULL) {
        head->next = reverseKGroup(nextNode, k);
        if (head->next)
            head->next->prev = head;
    }
    return newHead;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{1, NULL, NULL};
    Node* second = new Node{2, NULL, head};
    Node* third = new Node{3, NULL, second};
    Node* fourth = new Node{4, NULL, third};
    Node* fifth = new Node{5, NULL, fourth};
    head->next = second; second->next = third; third->next = fourth; fourth->next = fifth;

    cout << "Original Doubly LL: ";
    display(head);
    head = reverseKGroup(head, 2);
    cout << "Reversed in Groups of 2: ";
    display(head);

    return 0;
}
