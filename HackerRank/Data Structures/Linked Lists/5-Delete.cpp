/*
Delete Node at a given position in a linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* Delete(Node *head, int position)
{
	if (position == 0)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		Node *iter = head, *temp;
		for (int i = 0; i < position - 1; i++) { iter = iter->next; }
		temp = iter->next;
		iter->next = temp->next;
		delete temp;
	}
	return head;
}
