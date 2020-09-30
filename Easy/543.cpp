 int ans = 1;
int depth(TreeNode *root) {
   if (!root) return 0; 
    
   int l = depth(root->left);
   int r = depth(root->right);
   ans = max(ans, l+r+1);
   return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    depth(root);
    return ans - 1;
}
