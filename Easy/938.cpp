#include <iostream>
using namespace std;

int rangeSumBST(TreeNode* root, int L, int R) {
    if (!root) return 0;
                    
    int add = (root->val >= L && root->val <= R) ? root->val : 0;
    return add + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}
