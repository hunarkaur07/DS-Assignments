#include <iostream>
#include <unordered_map>
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

Node* buildTreeFromPreIn(int inorder[], int preorder[], int inStart, int inEnd, int &preIndex, unordered_map<int, int> &inMap) {
    if (inStart > inEnd) return NULL;
    int curr = preorder[preIndex++];
    Node* node = newNode(curr);
    if (inStart == inEnd) return node;
    int inIndex = inMap[curr];
    node->left = buildTreeFromPreIn(inorder, preorder, inStart, inIndex - 1, preIndex, inMap);
    node->right = buildTreeFromPreIn(inorder, preorder, inIndex + 1, inEnd, preIndex, inMap);
    return node;
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    int n = 5;
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++)
        inMap[inorder[i]] = i;
    int preIndex = 0;
    Node* root = buildTreeFromPreIn(inorder, preorder, 0, n - 1, preIndex, inMap);
    inorderTraversal(root);
    return 0;
}
