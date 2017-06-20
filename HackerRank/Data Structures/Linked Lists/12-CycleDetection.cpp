/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
struct Node {
int data;
struct Node* next;
}
*/

bool has_cycle(Node* head) {
	if (head == nullptr || head->next == nullptr) { return false; }
	Node *slow = head, *fast = head->next->next;
	while (fast != nullptr)
	{
		if (slow == fast) { return true; }
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}