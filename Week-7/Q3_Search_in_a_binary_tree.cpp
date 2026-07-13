#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* searchBST(TreeNode* root, int val) {

    if (root == nullptr || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    TreeNode* ans = searchBST(root, val);

    if (ans == nullptr) {
        cout << "Value not found!" << endl;
    }
    else {
        cout << "Subtree (Inorder): ";
        inorder(ans);
        cout << endl;
    }

    return 0;
}