#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build tree from level order input
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        Node* current = q.front();
        q.pop();

        if (i < n && arr[i] != -1) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Function to print the right view of the binary tree
void rightView(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            // last node of the current level
            if (i == levelSize - 1)
                cout << current->data << " ";

            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Node* root = buildTree(arr, n);
        rightView(root);
    }

    return 0;
}
