vector<int> v;
void trav(TreeNode *root) {
    if (!root) return;
    
    trav(root->left);
    v.push_back(root->val);
    trav(root->right);
}

bool findTarget(TreeNode* root, int k) {
    trav(root);
    int i = 0, j = v.size() - 1;
    while (i < j) {
        if (v[i] + v[j] == k) return true;
        else if (v[i] + v[j] > k) --j;
        else ++i;
    }
    return false;
}
