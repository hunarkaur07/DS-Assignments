#include <iostream>
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

// Function to check if a node is a leaf
bool isLeaf(Node* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

// Function to find the sum of all left leaves
int sumOfLeftLeaves(Node* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // If left child is a leaf, add its value
    if (isLeaf(root->left))
        sum += root->left->data;
    else
        sum += sumOfLeftLeaves(root->left);

    // Recur for right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    // Example Tree: [3,9,20,null,null,15,7]
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of all left leaves: " << sumOfLeftLeaves(root);
    return 0;
}
