#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert node at end
void insertNode(Node*& head, int val) {
    Node* newNode = new Node(val);//
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

// Reverse k nodes using head, p, q
Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    int count = 0;

    // Step 1: check if k nodes exist
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }
    if (count < k) return head;

    // Step 2: reverse k nodes
    Node* p = head;
    Node* q = NULL;
    Node* r = NULL;
    count = 0;

    while (p != NULL && count < k) {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
        count++;
    }

    // Step 3: connect with next part
    if (r != NULL)
        head->next = reverseKGroup(r, k);

    return q;
}

// Utility to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Build linked list 
    for (int i = 1; i <= 8; i++) {
        insertNode(head, i);
    }

    cout << "Original List: ";
    printList(head);

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
