/*
Compare two linked lists A and B
Return 1 if they are identical and 0 if they are not.
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
int CompareLists(Node *headA, Node* headB)
{
	if (headA == nullptr && headB == nullptr) { return 1; }
	Node *iterA = headA, *iterB = headB;
	while (iterA != nullptr && iterB != nullptr)
	{
		if (iterA->data != iterB->data) { return 0; }
		iterA = iterA->next;
		iterB = iterB->next;
	}
	if (iterA != nullptr || iterB != nullptr) { return 0; }
	else { return 1; }
}