/*
Remove all duplicate elements from a sorted linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* RemoveDuplicates(Node *head)
{
	Node *pre = head, *cur = head->next;
	while (cur != nullptr)
	{
		if (cur->data == pre->data) {
			pre->next = cur->next;
			cur = pre->next;
		}
		else {
			pre = cur;
			cur = pre->next;
		}
	}
	return head;
}