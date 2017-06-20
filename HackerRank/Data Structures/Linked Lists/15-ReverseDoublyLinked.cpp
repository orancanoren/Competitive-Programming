/*
Reverse a doubly linked list, input list may also be empty
Node is defined as
struct Node
{
int data;
Node *next;
Node *prev;
}
*/
Node* Reverse(Node* head)
{
	if (head == nullptr) { return head; }
	Node *iter = head, *tail, *temp, *newTail;
	while (iter->next != nullptr) {
		iter = iter->next;
	}
	tail = iter;
	newTail = tail;
	iter = tail->prev;
	while (iter != nullptr) {
		temp = iter->prev;
		newTail->next = iter;
		iter->prev = newTail;
		newTail = iter;
		iter = temp;
	}
	tail->prev = nullptr;
	newTail->next = nullptr;
	return tail;
}