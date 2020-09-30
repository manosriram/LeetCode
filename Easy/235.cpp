TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;

    auto l = lowestCommonAncestor(root->left, p, q);
    auto r = lowestCommonAncestor(root->right, p, q);

    if (l && r)
        return root;

    if (l) return l;
    else return r;
}
