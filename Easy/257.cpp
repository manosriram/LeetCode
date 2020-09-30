vector<string> ans;
void path(TreeNode *root, string res) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        res += to_string(root->val);
        ans.push_back(res);
        return;
    }
    path(root->left, res + (to_string(root->val) + "->"));
    path(root->right, res + (to_string(root->val) + "->"));
}

vector<string> binaryTreePaths(TreeNode* root) {
    path(root, "");
    return ans;
}
