/*
Get Nth element from the end in a linked list of integers
Number of elements in the list will always be greater than N.
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
int GetNode(Node *head, int positionFromTail)
{
	int size = 0;
	Node *iter = head;
	while (iter != nullptr)
	{
		size += 1;
		iter = iter->next;
	}
	iter = head;
	for (int i = 0; i < size - 1 - positionFromTail; i++)
	{
		iter = iter->next;
	}
	return iter->data;
}