#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* down;
    Node* left;
    Node* up;
};

Node* create2DList(int mat[3][3], int n, int m) {
    Node* head = NULL;
    Node* rowHead = NULL;
    Node* prevRow = NULL;

    for (int i = 0; i < n; i++) {
        Node* prev = NULL;
        for (int j = 0; j < m; j++) {
            Node* newNode = new Node{mat[i][j], NULL, NULL, NULL, NULL};
            if (!head)
                head = newNode;

            if (!rowHead)
                rowHead = newNode;

            if (prev) {
                prev->right = newNode;
                newNode->left = prev;
            }

            if (prevRow) {
                Node* upper = prevRow;
                for (int k = 0; k < j; k++)
                    upper = upper->right;
                upper->down = newNode;
                newNode->up = upper;
            }

            prev = newNode;
        }
        prevRow = rowHead;
        rowHead = NULL;
    }
    return head;
}

void display2DList(Node* head, int n, int m) {
    Node* row = head;
    for (int i = 0; i < n; i++) {
        Node* temp = row;
        for (int j = 0; j < m; j++) {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = create2DList(mat, 3, 3);
    cout << "2D Doubly Linked List Representation:\n";
    display2DList(head, 3, 3);

    return 0;
}
