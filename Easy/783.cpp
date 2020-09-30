 void inorder(TreeNode *root) {
    if (!root) return;
    
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}

int minDiffInBST(TreeNode* root) {
    inorder(root);
    int ans = INT_MAX;
    
    for (int t=0;t<v.size() - 1;++t) {
        ans = min(v[t+1] - v[t], ans);
    }
    return ans;
}
