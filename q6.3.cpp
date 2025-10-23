#include <iostream>
using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };

// int sizeOfDoublyLinkedList(Node* head) {
//     int count = 0;
//     Node* temp = head;
//     while (temp) {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// int main() {
//     Node* head = new Node{10, NULL, NULL};
//     Node* second = new Node{20, NULL, head};
//     Node* third = new Node{30, NULL, second};

//     head->next = second;
//     second->next = third;

//     cout << "Size of Doubly Linked List = " << sizeOfDoublyLinkedList(head) << endl;
//     return 0;
// }


struct Node {
    int data;
    Node* next;
};

int sizeOfCircularLinkedList(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};
    head->next = second;
    second->next = third;
    third->next = head;

    cout << "Size of Circular Linked List = " << sizeOfCircularLinkedList(head) << endl;
    return 0;
}
