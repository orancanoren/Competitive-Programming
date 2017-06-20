
/*The tree node has data, left child and right child
class Node {
int data;
Node* left;
Node* right;
};

*/
int max(int a, int b) {
	return a >= b ? a : b;
}

int height(Node* root) {
	if (root == nullptr) return -1;
	return 1 + max(height(root->left), height(root->right));
}