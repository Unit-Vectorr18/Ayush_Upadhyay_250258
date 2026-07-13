#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr)
        return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans;
    inorder(root, ans);

    for (int x : ans)
        cout << x << " ";

    return 0;
}