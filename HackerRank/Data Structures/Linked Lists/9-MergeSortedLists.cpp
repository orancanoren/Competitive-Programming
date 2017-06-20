/*
Merge two sorted lists A and B as one linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* MergeLists(Node *headA, Node* headB)
{
	// This is a "method-only" submission. 
	// You only need to complete this method
	//1 - set the head of the linked list so we may return it
	Node * mergedHead = (headA->data < headB->data ? headA : headB);

	Node *iterA = headA, *iterB = headB;
	Node *tailA, *tailB;
	while (iterA != nullptr && iterB != nullptr) {
		if (iterA->data < iterB->data) {
			Node * temp = iterA->next;
			iterA->next = iterB;

			if (temp == nullptr) {
				tailA = iterA;
			}
			iterA = temp;
		}
		else {
			Node * temp = iterB->next;
			iterB->next = iterA;

			if (temp == nullptr) {
				tailB = iterB;
			}
			iterB = temp;
		}
	}
	if (iterA != nullptr) {
		tailB->next = iterA;
	}
	else if (iterB != nullptr) {
		tailA->next = iterB;
	}

	return mergedHead;
}