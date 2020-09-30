vector<int> v;

void inorder(TreeNode *root) {
    if (!root) return;
    
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}

int getMinimumDifference(TreeNode* root) {
    inorder(root);
    int diff = INT_MAX;
    for (int t=0;t<v.size() - 1;++t) {
        diff = min(diff, abs(v[t] - v[t+1]));
    }
    return diff;
}
