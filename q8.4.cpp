#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* node = new Node();
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

bool isBSTree(Node* root, Node* &prev) {
    if (root == NULL) return true;
    if (!isBSTree(root->left, prev))
        return false;
    if (prev != NULL && root->data <= prev->data)
        return false;
    prev = root;
    return isBSTree(root->right, prev);
}

bool isBST(Node* root) {
    Node* prev = NULL;
    return isBSTree(root, prev);
}

int main() {
    Node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    cout << (isBST(root) ? "Tree is BST" : "Tree is not BST");
    return 0;
}
