#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

//double 
class DoublyLinkedList {
    Node *head;
public:
    DoublyLinkedList() { head = NULL; }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert after a given node
    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Insert before a given node
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    // Delete a specific node by value
    void deleteNode(int key) {
        if (!head) return;
        Node *temp = head;
        if (head->data == key) {
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            return;
        }
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        if (temp->next)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }

    // Search for a node
    void search(int key) {
        Node *temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    // Display list
    void display() {
        Node *temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Find size
    int size() {
        int count = 0;
        Node *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Check if list is palindrome
    void checkPalindrome() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node *start = head;
        Node *end = head;
        while (end->next)
            end = end->next;
        bool flag = true;
        while (start != end && end->next != start) {
            if (start->data != end->data) {
                flag = false;
                break;
            }
            start = start->next;
            end = end->prev;
        }
        if (flag)
            cout << "The list is a palindrome.\n";
        else
            cout << "The list is not a palindrome.\n";
    }
};

//circular 
class CircularLinkedList {
    Node *head;
public:
    CircularLinkedList() { head = NULL; }

    // Insert at end
    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Delete a specific node
    void deleteNode(int key) {
        if (!head) return;
        Node *curr = head, *prev = NULL;
        while (curr->data != key) {
            if (curr->next == head) {
                cout << "Node not found!\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        if (curr == head && curr->next == head) {
            head = NULL;
            delete curr;
            return;
        }
        if (curr == head) {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;
            prev->next = head;
            delete curr;
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    // Search
    void search(int key) {
        if (!head) return;
        Node *temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    // Display circular list
    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // repeat head at end
    }

    // Find size
    int size() {
        if (!head) return 0;
        int count = 0;
        Node *temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};


int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, val, key, type;

    cout << "===== LINKED LIST MENU =====\n";
    do {
        cout << "\n1. Work on Doubly Linked List\n";
        cout << "2. Work on Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> type;

        if (type == 1) {
            cout << "\n--- Doubly Linked List Operations ---\n";
            cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After Node\n4. Insert Before Node\n5. Delete Node\n6. Search\n7. Display\n8. Size\n9. Check Palindrome\n10. Back\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; dll.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; dll.insertAtEnd(val); break;
                case 3: cout << "Enter key and value: "; cin >> key >> val; dll.insertAfter(key, val); break;
                case 4: cout << "Enter key and value: "; cin >> key >> val; dll.insertBefore(key, val); break;
                case 5: cout << "Enter value to delete: "; cin >> val; dll.deleteNode(val); break;
                case 6: cout << "Enter value to search: "; cin >> val; dll.search(val); break;
                case 7: dll.display(); break;
                case 8: cout << "Size: " << dll.size() << endl; break;
                case 9: dll.checkPalindrome(); break;
            }
        }
        else if (type == 2) {
            cout << "\n--- Circular Linked List Operations ---\n";
            cout << "1. Insert at Beginning\n2. Insert at End\n3. Delete Node\n4. Search\n5. Display\n6. Size\n7. Back\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; cll.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; cll.insertAtEnd(val); break;
                case 3: cout << "Enter value to delete: "; cin >> val; cll.deleteNode(val); break;
                case 4: cout << "Enter value to search: "; cin >> val; cll.search(val); break;
                case 5: cll.display(); break;
                case 6: cout << "Size: " << cll.size() << endl; break;
            }
        }

    } while (type != 3);

    cout << "Program Terminated.\n";
    return 0;
}
