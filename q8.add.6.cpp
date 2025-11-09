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

Node* buildTreeFromInPost(int inorder[], int postorder[], int inStart, int inEnd, int &postIndex, unordered_map<int, int> &inMap) {
    if (inStart > inEnd) return NULL;
    int curr = postorder[postIndex--];
    Node* node = newNode(curr);
    if (inStart == inEnd) return node;
    int inIndex = inMap[curr];
    node->right = buildTreeFromInPost(inorder, postorder, inIndex + 1, inEnd, postIndex, inMap);
    node->left = buildTreeFromInPost(inorder, postorder, inStart, inIndex - 1, postIndex, inMap);
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
    int postorder[] = {4, 5, 2, 3, 1};
    int n = 5;
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++)
        inMap[inorder[i]] = i;
    int postIndex = n - 1;
    Node* root = buildTreeFromInPost(inorder, postorder, 0, n - 1, postIndex, inMap);
    inorderTraversal(root);
    return 0;
}
