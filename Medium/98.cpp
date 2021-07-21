#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

bool Solve(Node *root, Node *parent, char c) {
    if (!root) return true;

    if (c == 'L' && root->data > parent->data) return false;
    if (c == 'R' && root->data < parent->data) return false;
    
    return Solve(root->left, root, 'L') && Solve(root->right, root, 'R');
}

int main() {
    Node *root = new Node(6);
    root->left = new Node(5);
    root->right = new Node(7);
    root->left->left = new Node(4);
    root->right->right = new Node(11);
    root->right->right->left = new Node(90);
    root->right->right = new Node(14);

    cout << Solve(root, NULL, ' ');
}
