
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to print a tree (preorder)
void printTree(TreeNode* root) {
    if (root == NULL) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Function to clone a tree (used to copy trees easily)
TreeNode* clone(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* newRoot = new TreeNode(root->val);
    newRoot->left = clone(root->left);
    newRoot->right = clone(root->right);
    return newRoot;
}

// Build all trees recursively (no vector version)
int build(TreeNode* trees[], int start, int end) {
    if (start > end) {
        trees[0] = NULL;  // only one null tree
        return 1;         // count = 1
    }

    int total = 0;  // total trees made
    TreeNode* leftTrees[100];
    TreeNode* rightTrees[100];
    int leftCount, rightCount;

    // Try every number as root
    for (int i = start; i <= end; i++) {
        leftCount = build(leftTrees, start, i - 1);
        rightCount = build(rightTrees, i + 1, end);

        // Combine left and right subtrees
        for (int l = 0; l < leftCount; l++) {
            for (int r = 0; r < rightCount; r++) {
                TreeNode* root = new TreeNode(i);
                root->left = clone(leftTrees[l]);
                root->right = clone(rightTrees[r]);
                trees[total++] = root;
            }
        }
    }
    return total;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    TreeNode* allTrees[100];
    int count = build(allTrees, 1, n);

    cout << "\nTotal Unique BSTs: " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << "Tree " << i + 1 << ": ";
        printTree(allTrees[i]);
        cout << endl;
    }
    return 0;
}
