#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* node = new Node();
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void convertToDLL(Node* root, Node* &head, Node* &prev) {
    if (!root) return;
    convertToDLL(root->left, head, prev);
    if (prev == NULL)
        head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    convertToDLL(root->right, head, prev);
}

Node* mergeDLLs(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    Node* head = NULL;
    Node* tail = NULL;
    while (head1 && head2) {
        Node* smaller = (head1->data < head2->data) ? head1 : head2;
        if (smaller == head1)
            head1 = head1->right;
        else
            head2 = head2->right;
        smaller->left = tail;
        if (tail)
            tail->right = smaller;
        else
            head = smaller;
        tail = smaller;
    }
    Node* rem = (head1) ? head1 : head2;
    while (rem) {
        rem->left = tail;
        tail->right = rem;
        tail = rem;
        rem = rem->right;
    }
    return head;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " <—> ";
        head = head->right;
    }
    cout << "null";
}

int main() {
    Node* t1 = NULL;
    t1 = insert(t1, 20);
    t1 = insert(t1, 10);
    t1 = insert(t1, 30);
    t1 = insert(t1, 25);
    t1 = insert(t1, 100);
    t1 = insert(t1, 50);

    Node* t2 = NULL;
    t2 = insert(t2, 5);
    t2 = insert(t2, 70);

    Node *head1 = NULL, *prev1 = NULL;
    Node *head2 = NULL, *prev2 = NULL;

    convertToDLL(t1, head1, prev1);
    convertToDLL(t2, head2, prev2);

    Node* merged = mergeDLLs(head1, head2);
    printDLL(merged);

    return 0;
}
