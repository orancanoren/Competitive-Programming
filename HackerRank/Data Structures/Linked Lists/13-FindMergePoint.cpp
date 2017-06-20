/*
Find merge point of two linked lists
Node is defined as
struct Node
{
int data;
Node* next;
}
*/
int FindMergeNode(Node *headA, Node *headB)
{
	Node *iterA = headA, *iterB = headB, *temp;
	while (iterA != nullptr) {
		temp = iterA->next,
			iterA->next = nullptr;
		iterA = temp;
	}
	while (iterB->next != nullptr) {
		iterB = iterB->next;
	}
	return iterB->data;
}