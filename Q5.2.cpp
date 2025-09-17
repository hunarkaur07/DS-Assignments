#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// function to insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node{val, NULL};
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

// function to display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

// function to count and delete all occurrences of key
int deleteKeyOccurrences(Node*& head, int key) {
    int count = 0;

    // first handle case when head nodes contain key
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // now handle rest of list
    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

int main() {
    Node* head = NULL;

    // create linked list 1->2->1->2->1->3->1
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 3);
    insertEnd(head, 1);

    cout << "Original Linked List: ";
    display(head);

    int key = 1;
    int count = deleteKeyOccurrences(head, key);

    cout << "Count of " << key << " : " << count << endl;
    cout << "Updated Linked List: ";
    display(head);

    return 0;
}
