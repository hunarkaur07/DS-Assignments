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

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

bool searchRecursive(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

bool searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int findMax(Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

Node* findMinNode(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

Node* findMaxNode(Node* node) 
{
    while (node && node->right != NULL)
        node = node->right;
    return node;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != NULL)
        return findMinNode(node->right);
    Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != NULL)
        return findMaxNode(node->left);
    Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    cout << "Search Recursive (15): " << (searchRecursive(root, 15) ? "Found" : "Not Found");
    cout << "\nSearch Non-Recursive (40): " << (searchNonRecursive(root, 40) ? "Found" : "Not Found");
    cout << "\nMaximum Element: " << findMax(root);
    cout << "\nMinimum Element: " << findMin(root);

    Node* node = root->left;
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    cout << "\nInorder Successor of " << node->data << ": " << (succ ? to_string(succ->data) : "None");
    cout << "\nInorder Predecessor of " << node->data << ": " << (pred ? to_string(pred->data) : "None");
    return 0;
}
