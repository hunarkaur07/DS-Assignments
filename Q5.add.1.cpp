#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to find intersection using 2 pointers
Node* getIntersection(Node* head1, Node* head2) {
    if (!head1 || !head2) return NULL;

    Node* p1 = head1;
    Node* p2 = head2;

    // Traverse both lists
    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }
    return p1; // Either intersection node or NULL
}

int main() {
    // Example: create intersecting lists
    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = common;

    Node* head2 = new Node(15);
    head2->next = common;

    Node* intersect = getIntersection(head1, head2);
    if (intersect)
        cout << "Intersection at node with value: " << intersect->data << endl;
    else
        cout << "No intersection found.\n";

    return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to find intersection using 2 pointers
Node* getIntersection(Node* head1, Node* head2) {
    if (!head1 || !head2) return NULL;

    Node* p1 = head1;
    Node* p2 = head2;

    // Traverse both lists
    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }
    return p1; // Either intersection node or NULL
}

int main() {
    // Example: create intersecting lists
    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = common;

    Node* head2 = new Node(15);
    head2->next = common;

    Node* intersect = getIntersection(head1, head2);
    if (intersect)
        cout << "Intersection at node with value: " << intersect->data << endl;
    else
        cout << "No intersection found.\n";

    return 0;
}
