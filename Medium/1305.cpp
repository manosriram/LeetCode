void inorder(TreeNode *root, vector<int> &v) {
    if (!root) return;
    
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);
    
    vector<int> res;
    int r1 = 0, r2 = 0;
    while (r1 < v1.size() && r2 < v2.size()) {
        if (v1[r1] < v2[r2]) {
            res.push_back(v1[r1]);
            ++r1;
        } else if (v2[r2] < v1[r1]) {
            res.push_back(v2[r2]);
            ++r2;
        } else {
            res.push_back(v1[r1]);
            res.push_back(v2[r2]);
            ++r1, ++r2;
        }
    }
    while (r1 < v1.size()) res.push_back(v1[r1++]);
    
    while (r2 < v2.size()) res.push_back(v2[r2++]);
    
    return res;
    
}
