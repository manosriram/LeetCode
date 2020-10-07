vector<TreeNode *> v;
bool contains(vector<int> del, int x) {
    return find(del.begin(), del.end(), x) != del.end();
}

TreeNode *dfs(TreeNode *root, vector<int> del) {
    if (!root) return NULL;
    
    if ((!root->left && !root->right) && contains(del, root->val)) {
        return NULL;
    }
    
    root->left = dfs(root->left, del);
    root->right = dfs(root->right, del);
    if (contains(del, root->val)) {
        if (root->left) v.push_back(root->left);
        if (root->right) v.push_back(root->right);
        return NULL;
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    root = dfs(root, to_delete);
    if (root) v.push_back(root);
    return v;
}
