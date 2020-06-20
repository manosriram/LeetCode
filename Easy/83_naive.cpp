#include "../linkedListDriver.hpp"
#include <set>
using namespace std;
Node* deleteDuplicates(Node* head) {
        if (!head) return nullptr;
        set<int> s;
        Node *res = nullptr;
        Node *p = head;
        
        while (p) {
            s.insert(p->data);
            p = p->next;
        }
        
        for (auto t: s) {
            insertAtEnd(res, t);
        }
        return res;
    }
int main() {
    Node *root = nullptr;

    insertAtEnd(root, 1);
    insertAtEnd(root, 1);
    insertAtEnd(root, 2);
    root = deleteDuplicates(root);

    displayNodes(root);
}

