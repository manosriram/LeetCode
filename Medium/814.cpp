bool hasOnes(TreeNode *root) {
    if (!root) return false;
    if (root->val == 1) return true;
    
    return hasOnes(root->left) || hasOnes(root->right);
}

TreeNode* pruneTree(TreeNode* root) {
    if (!root) return NULL;
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    
    if (!hasOnes(root)) return NULL;
    else return root;
}
