#include "../linkedListDriver.hpp"
#include <set>
using namespace std;

// It is a sorted list, so consecutive elements must not be same!
Node* deleteDuplicates(Node* head) {
    Node *p;
    int prev = head->data;
    p = head->next;
    Node *res = nullptr;
    insertAtEnd(res, p->data);

    while(p) {
        if (p->data != prev) {
            insertAtEnd(res, p->data);
            prev = p->data;
        }
        p = p->next;
    }
    return res;
}
int main() {
    Node *root = nullptr;

    insertAtEnd(root, 1);
    insertAtEnd(root, 1);
    insertAtEnd(root, 1);
    insertAtEnd(root, 1);
    insertAtEnd(root, 2);
    root = deleteDuplicates(root);

    displayNodes(root);
}

