/*
Node is defined as

typedef struct node
{
int data;
node * left;
node * right;
}node;

*/


node * insert(node * root, int value)
{
	node * nn = new node;
	nn->left = nullptr;
	nn->right = nullptr;
	nn->data = value;
	if (root == nullptr) root = nn;
	else {
		node * iter = root;
		bool insertion_complete = false;
		while (!insertion_complete) {
			if (iter->data < value) {
				if (iter->right == nullptr) {
					iter->right = nn;
					insertion_complete = true;
				}
				else {
					iter = iter->right;
				}
			}
			else {
				if (iter->left == nullptr) {
					iter->left = nn;
					insertion_complete = true;
				}
				else {
					iter = iter->left;
				}
			}
		}
	}
	return root;
}
