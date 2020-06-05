#include <iostream>
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q, qq;
        int last = root->val;
        q.push(root);
        while(!q.empty()) {
            auto temp = q.front();q.pop();
            
            if (temp->left) qq.push(temp->left);
            if (temp->right) qq.push(temp->right);
            
            if (q.empty()) {
                if (qq.size())
                    last = qq.front()->val;
                swap(q, qq);
            }
        }
        
        
        return last;
    }
};
