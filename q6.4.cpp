#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* start = head;
    Node* end = head;
    while (end->next)
        end = end->next;

    while (start != end && end->next != start) {
        if (start->data != end->data)
            return false;
        start = start->next;
        end = end->prev;
    }
    return true;
}

int main() {
    Node* n1 = new Node{'R', NULL, NULL};
    Node* n2 = new Node{'A', NULL, n1};
    Node* n3 = new Node{'D', NULL, n2};
    Node* n4 = new Node{'A', NULL, n3};
    Node* n5 = new Node{'R', NULL, n4};
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;

    if (isPalindrome(n1))
        cout << "The Doubly Linked List is Palindrome.\n";
    else
        cout << "The Doubly Linked List is NOT Palindrome.\n";

    return 0;
}
