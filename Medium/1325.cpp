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

bool isLeaf(Node *root) {
    if (root && !root->left && !root->right) return true;
    return false;
}

Node *Solve(Node *root, int x) {
    if (!root) return NULL;

    Node *left = Solve(root->left, x);
    Node *right = Solve(root->right, x);

    if (!left && !right && root->data == x) {
        cout << "yes, " << root->data << endl;
        return NULL;
    }

    if (!left) root->left = NULL;
    if (!right) root->right = NULL;

    return root;
}

void inorder(Node *root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = new Node(2);
    root->left = new Node(5);
    root->right = new Node(2);
    root->left->left = new Node(7);
    root->left->left = new Node(2);

    root = Solve(root, 2);
    inorder(root);
}
