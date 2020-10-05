TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.empty()) return NULL;
    int rootValue = preorder[0];
    vector<int> smaller, greater;
    for (int t=1;t<preorder.size();++t) {
        if (preorder[t] < rootValue) smaller.push_back(preorder[t]);
        else greater.push_back(preorder[t]);
    }
    TreeNode *root = new TreeNode(rootValue);
    root->left = bstFromPreorder(smaller);
    root->right = bstFromPreorder(greater);
    return root;
}
