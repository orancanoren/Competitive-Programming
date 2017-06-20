
/*
struct node
{
int data;
node* left;
node* right;
}*/

#include <queue>

void LevelOrder(node * root)
{ // Breadth First Traversal Algorithm
	queue<node *> q;
	q.push(root);
	while (!q.empty()) {
		node * current = q.front();
		cout << current->data << " ";
		q.pop();
		if (current->left != nullptr) q.push(current->left);
		if (current->right != nullptr) q.push(current->right);
	}
}
