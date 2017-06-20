/*
struct node
{
int data;
node* left;
node* right;
};

*/
void leftPostOrder(node *&root) {
	if (root->left != nullptr) {
		leftPostOrder(root->left);
	}
	cout << root->data << ' ';
}

void rightPreOrder(node *&root) {
	if (root != nullptr) {
		cout << root->data << ' ';
		rightPreOrder(root->right);
	}
}


void top_view(node * root)
{
	leftPostOrder(root);
	rightPreOrder(root->right);
}