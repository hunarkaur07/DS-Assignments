#include <iostream>
using namespace std;

// Structure for tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Simple queue structure for level order building
struct Queue {
    Node* arr[100];
    int front, rear;
    Queue() {
        front = 0;
        rear = 0;
    }
    void push(Node* node) {
        arr[rear++] = node;
    }
    Node* pop() {
        return arr[front++];
    }
    bool empty() {
        return front == rear;
    }
};

// Function to build tree using array input (-1 means NULL)
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = new Node(arr[0]);
    Queue q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        Node* current = q.pop();

        // Left child
        if (arr[i] != -1) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Recursive function to find maximum depth
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// Main function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[100];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Node* root = buildTree(arr, n);
        cout << maxDepth(root) << endl;
    }
    return 0;
}
