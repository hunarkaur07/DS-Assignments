#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random;
};

void correctRandom(Node* head, int wrongVal, int correctVal) {
    Node* temp = head;
    Node* wrongNode = NULL;
    Node* correctNode = NULL;

    // find both nodes
    while (temp) {
        if (temp->data == wrongVal)
            wrongNode = temp;
        if (temp->data == correctVal)
            correctNode = temp;
        temp = temp->next;
    }

    if (wrongNode && correctNode)
        wrongNode->random = correctNode;
}

int main() {
    Node* a = new Node{1, NULL, NULL, NULL};
    Node* b = new Node{2, NULL, a, NULL};
    Node* c = new Node{3, NULL, b, NULL};
    a->next = b; b->next = c;

    a->random = c;
    b->random = a;
    c->random = a; // wrong random pointer

    correctRandom(a, 3, 2); // correct node 3's random pointer to node 2

    cout << "After correction, node 3's random -> " << c->random->data << endl;
    return 0;
}
