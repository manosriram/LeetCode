class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> vv;
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            vv.push_back(dq.back()->val);
            int n = dq.size();
            for (int t=0;t<n;++t) {
                auto temp = dq.front();
                dq.pop_front();
                if (temp->left) dq.push_back(temp->left);
                if (temp->right) dq.push_back(temp->right);
            }
        }
        
        return vv;
    }
};
