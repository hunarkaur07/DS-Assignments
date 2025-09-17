#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer (global for simplicity)
Node* head = NULL;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// (a) Insertion at beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// (b) Insertion at end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
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

// (c) Insertion before a node with given value
void insertBeforeValue(int value, int beforeValue) {
    if (head == NULL) return;

    // If we want to insert before head
    if (head->data == beforeValue) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != beforeValue) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value " << beforeValue << " not found.\n";
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// (c) Insertion after a node with given value
void insertAfterValue(int value, int afterValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << afterValue << " not found.\n";
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// (d) Deletion from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// (e) Deletion from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// (f) Deletion of a specific node
void deleteValue(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value " << value << " not found.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// (g) Search for a node and display its position
void searchValue(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << value << " not found in the list.\n";
}

// (h) Display all nodes
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Menu function
int main() {
    int choice, value, key;
    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before Value\n";
        cout << "4. Insert After Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Value\n";
        cout << "8. Search a Value\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Insert before which value? ";
                cin >> key;
                insertBeforeValue(value, key);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Insert after which value? ";
                cin >> key;
                insertAfterValue(value, key);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteValue(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchValue(value);
                break;
            case 9:
                displayList();
                break;
            case 10:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
