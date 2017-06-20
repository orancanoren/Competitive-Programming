/*
Insert Node at a given position in a linked list
head can be NULL
First element in the linked list is at position 0
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* InsertNth(Node *&head, int data, int position)
{
	Node *iter = head, *nn = new Node;
	nn->data = data;
	if (position == 0)
	{
		nn->next = head;
		return nn;
	}
	for (int i = 0; i < position - 1; i++) { iter = iter->next; }
	nn->next = iter->next;
	iter->next = nn;
	return head;
}
