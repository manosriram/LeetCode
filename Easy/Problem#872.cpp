#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void DFS(TreeNode *root, vector<int> &arr) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        arr.push_back(root->val);
        return;
    }

    DFS(root->left, arr);
    DFS(root->right, arr);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> arr1, arr2;

    DFS(root1, arr1);
    DFS(root2, arr2);

    return (arr1 == arr2);
}