#include <iostream>
using namespace std;
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
    int ml(TreeNode *root, int lvl) {
        if (!root) return lvl;
        
        return max(ml(root->left, lvl+1), ml(root->right, lvl+1));
    }
    
    int dfs(TreeNode *root, int currentLevel, int maxLevel) {
        if (!root) return 0;
        cout << currentLevel << " ";
        if (!root->left && !root->right && currentLevel == maxLevel) return root->val;
        else if (!root->left && !root->right) return 0;
        
        return dfs(root->left, currentLevel + 1, maxLevel) + dfs(root->right, currentLevel + 1, maxLevel);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxl = ml(root, 0);
        return dfs(root, 0, maxl-1);
    }
};
