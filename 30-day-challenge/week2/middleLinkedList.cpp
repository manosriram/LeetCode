#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void insertEnd(Node *&head, int d) {
    Node *temp = new Node();
    temp->data = d;
    temp->next = nullptr;

    if (!head) {
        head = temp;
        return;
    }
    Node *p = head;
    while (p->next) p = p->next;

    p->next = temp;
    return;
}

void pt(Node *head) {
    Node *p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}

int middle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    Node *head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << middle(head);
}

