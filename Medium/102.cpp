/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        res.push_back({root->val});
        queue<TreeNode *> q, q2;
        q.push(root);
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            if (temp->left) q2.push(temp->left);
            if (temp->right) q2.push(temp->right);

            if (q.empty()) {
                vector<int> re;
                while (!q2.empty()) {
                    auto tt = q2.front();
                    q2.pop();
                    
                    q.push(tt);
                    re.push_back(tt->val);
                }
                if (re.size() > 0) {
                    res.push_back(re);
                    re.clear();
                }
            }
        }
        return res;
    }
};
