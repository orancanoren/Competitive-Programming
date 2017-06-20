/*
Print elements of a linked list in reverse order as standard output
head pointer could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
void ReversePrint(Node *head)
{
	if (head != nullptr)
	{
		Node *iter = head, *prev = nullptr, *after;
		while (iter->next != nullptr) //reverse the linked list
		{
			after = iter->next;
			iter->next = prev;
			prev = iter;
			iter = after;
		}
		iter->next = prev; //iter is now the new, reversed head node 
		while (iter != nullptr)
		{
			cout << iter->data << endl;
			iter = iter->next;
		}
	}
}