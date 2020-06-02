/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<Node *> q, q2;
        q.push(root);
        int lv = 0;
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            
            for (int t=0;t<temp->children.size();++t) {
                q2.push(temp->children[t]);
            }
            
            if (q.empty()) {
                ++lv;
                swap(q, q2);
            }
        }
        return lv;
    }
};
