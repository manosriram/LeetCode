#include "../linkedListDriver.hpp"
#include <iostream>
using namespace std;

Node *mergeLists(Node *l1, Node *l2) {
    Node *res = nullptr,
         *p = l1,
         *q = l2;
        while (p || q) {
            if (p && q && p->data == q->data) {
                insertAtEnd(res, p->data);
                insertAtEnd(res, q->data);
                p = p->next;
                q = q->next;
                continue;
            }
            
            if (p && q && p->data < q->data) {
                insertAtEnd(res, p->data);
                p = p->next;
            } else if (p && q && p->data > q->data) {
                insertAtEnd(res, q->data);
                q = q->next;
            } else if (p || q) {
                if (p) {
                    insertAtEnd(res, p->data);
                    p = p->next;
                } if (q) {
                    insertAtEnd(res, q->data);
                    q = q->next;
                }
            }
        }
    return res;
}

int main() {
   Node *l1 = nullptr; 
   Node *l2 = nullptr; 

   insertAtEnd(l1, 1);
   insertAtEnd(l1, 2);
   insertAtEnd(l1, 4);

   insertAtEnd(l2, 1);
   insertAtEnd(l2, 3);
   insertAtEnd(l2, 4);

   auto res = mergeLists(l1, l2);
   displayNodes(res);
}

