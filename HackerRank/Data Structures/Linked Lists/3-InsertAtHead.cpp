/*
Insert Node at the begining of a linked list
Initially head pointer argument could be NULL for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
return back the pointer to the head of the linked list in the below method.
*/
Node *Insert(Node *head, int data)
{
	Node *nn = new Node;
	nn->data = data;
	if (head == NULL)
	{
		nn->next = NULL;
	}
	else
	{
		nn->next = head;
	}
	return nn;
}