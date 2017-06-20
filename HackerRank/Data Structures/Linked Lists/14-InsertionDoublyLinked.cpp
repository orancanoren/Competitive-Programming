/*
Insert Node in a doubly sorted linked list
After each insertion, the list should be sorted
Node is defined as
struct Node
{
int data;
Node *next;
Node *prev;
}
*/
Node* SortedInsert(Node *head, int data)
{
	Node *iter = head, *nn = new Node;
	nn->data = data;
	if (head == nullptr) {
		nn->next = nullptr;
		head = nn;
	}
	else if (head->data > data) {
		nn->next = head;
		head = nn;
	}
	else {
		while (iter->next != nullptr && iter->next->data < data) {
			iter = iter->next;
		}
		nn->next = iter->next;
		iter->next = nn;
	}
	return head;
}