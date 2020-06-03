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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int lvl = 0;
        while (!q.empty()) {
            int nn = q.size();
            while (nn--) {
                auto temp = q.front();
                q.pop();
                if (!temp->left && !temp->right) {
                    ++lvl;
                    return lvl;
                }

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ++lvl;
        }
        return lvl;
    }
};
