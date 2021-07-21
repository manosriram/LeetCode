#include <iostream>
#include <map>
using namespace std;
map<int, bool> mp;

struct Node {
	int data;
	Node *next;
	Node *prev;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}

        Node() {}
};
Node *root = NULL;

Node *insertAtStart(int data) {
	Node *temp = new Node(data);
	if (!root) {
		root = temp;
		return root;
	} else {
		temp->next = root;
		root->prev = temp;
		root = temp;
		return root;
	}
}

Node *findPosition(int key) {
	Node *p = root;
	while (p) {
		if (p->data == key) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void updateOrAdd(int key) {
    Node *el = findPosition(key);
}

void put(int key) {
	if (!mp[key] || mp[key] == false) {
		root = insertAtStart(key);
	} else {
		updateOrAdd(key);
	}
}

void show(Node *root) {
	Node *p = root;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	return;
}

int main() {
	put(1);
	put(2);
	put(2);
	show(root);
}
