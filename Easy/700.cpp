#include <iostream>
using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
    queue<TreeNode *> q;
    q.push(root);
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        
        if (node->val == val) return node;
       
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return NULL;
}
