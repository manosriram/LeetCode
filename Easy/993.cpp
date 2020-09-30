pair<int, int> lx, ly;
    
void Solve(TreeNode *root, TreeNode *parent, int x, int y, int level) {
    if (!root) return;
    
    Solve(root->left, root, x, y, level + 1);
    if (root->val == x) {
        lx = make_pair(parent->val, level);
    } if (root->val == y) {
        ly = make_pair(parent->val, level);
    }
    Solve(root->right, root, x, y, level + 1);
}

bool isCousins(TreeNode* root, int x, int y) {
    Solve(root, root, x, y, 0);
    
    return ((lx.first != ly.first) && (lx.second == ly.second));
}
