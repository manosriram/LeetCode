int Solve(TreeNode *root, int sum) {
  if (!root) return 0; 
    
  sum = (sum << 1) | root->val;
  if (!root->left && !root->right) {
     return sum;
  }
  int l = Solve(root->left, sum);
  int r = Solve(root->right, sum);
  return l + r;
}

int sumRootToLeaf(TreeNode* root) {
    return Solve(root, 0);
}
