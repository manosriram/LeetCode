TreeNode *root = NULL;
map<int, bool> mp;

void fE(TreeNode *root) {
    if (!root) return;
    this->mp[root->val] = true;
    if (root->left)
        root->left->val = 2 * root->val + 1;
    if (root->right)
        root->right->val = 2 * root->val + 2;
    
    fE(root->left);
    fE(root->right);
}

FindElements(TreeNode* root) {
    if (!root) return;
    
    root->val = 0;
    fE(root);
    this->root = root;
}

bool find(int target) {
    return this->mp[target];
}
