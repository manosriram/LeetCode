int maxLevelSum(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    int level = 1, lvl = 1;
    int mx = INT_MIN;
    
    int sum = 0;
    while (q.size() > 1) {
        auto node = q.front();
        q.pop();
        
        if (node == NULL) {
            q.push(NULL);
            if (sum > mx) {
                mx = sum;
                lvl = level;
            }
            ++level;
            sum = 0;
        } else {
            sum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    if (sum > mx) {
        lvl = level;
    }
    return lvl;
}
