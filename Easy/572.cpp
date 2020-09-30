 bool same(TreeNode *r1, TreeNode *r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    
    return r1->val == r2->val && same(r1->left, r2->left) && same(r1->right, r2->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    return s && (same(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
}
