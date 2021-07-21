#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;

	Node(int val) {
		this->val = val;
	}

	Node() {}
};

int getMxIndex(int x, int y, vector<int> nums) {
	int mx = INT_MIN;
	int ind = nums[x];
	for (int t=x;t<=y;++t) {
		if (mx >= nums[t]) {
			mx = nums[t];
			ind = t;
		}
	}
	return ind;
}

Node *Solve(int x, int y, vector<int> nums) {
	if (x > y) return NULL;

	int maxIndex = getMxIndex(x, y, nums);
	Node *root = new Node(nums[maxIndex]);
	root->left = Solve(x, maxIndex, nums);
	root->right = Solve(maxIndex + 1, y, nums);
	return root;
}

Node *constructBinaryTree(vector<int> nums) {
	return Solve(0, nums.size()-1, nums);
}

void inorder(Node *root) {
	if (!root) return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

int main() {
	cout << "hit";
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(0);
	nums.push_back(5);
	Node *root = constructBinaryTree(nums);
	inorder(root);
}