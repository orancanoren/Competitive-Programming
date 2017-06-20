/*
Reverse a linked list and return pointer to the head
The input list will have at least one element
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* Reverse(Node *head)
{
	if (head != nullptr)
	{
		Node *prev = nullptr, *after, *cur = head;
		while (cur->next != nullptr)
		{
			after = cur->next;
			cur->next = prev;
			prev = cur;
			cur = after;
		}
		cur->next = prev;
		return cur;
	}
	return head;
}