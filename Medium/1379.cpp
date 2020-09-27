#include <iostream>
using namespace std;

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    queue<TreeNode *> q;
    q.push(cloned);
    TreeNode *res = NULL;
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        
        if (tp->val == target->val) {
            res = tp;
            break;
        }
        
        if (original->left) q.push(cloned->left);
        if (original->right) q.push(cloned->right);
    }
    return res;
}
