#include <iostream>
using namespace std;

vector<int> preorder(Node* root) {
    if (!root) return {};
    vector<int> v;
    stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
        auto node = s.top();
        v.push_back(node->val);
        s.pop();
        
        for (int t=node->children.size()-1;t>=0;--t) {
            s.push(node->children[t]);
        }
    }
    return v;
}
