int totalGoodNodes = 0;
int DFS(TreeNode *root, int maxInPath) {
    if (!root) return 0;
    
    if (root->val >= maxInPath) {
        maxInPath = root->val;
        ++totalGoodNodes;
    }
    
    DFS(root->left, maxInPath);
    DFS(root->right, maxInPath);
    return totalGoodNodes;
}

int goodNodes(TreeNode* root) {
    return DFS(root, INT_MIN);
}
