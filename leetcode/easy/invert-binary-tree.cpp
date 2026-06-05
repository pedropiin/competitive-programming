#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

void invert(TreeNode* root) {
    swap(root->left, root->right);
    if (root->left != nullptr) invert(root->left);
    if (root->right != nullptr) invert(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if (root != nullptr) invert(root);
    return root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	TreeNode *root;
	cout << invertTree(root) << endl;
	
	return 0;
}

