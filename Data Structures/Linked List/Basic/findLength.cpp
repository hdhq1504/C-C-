#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* Given a reference (pointer to pointer) to the head of a list and an int, push a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// Iterative Approach
int getCount(struct Node* head)
{
	int count = 0;
	struct Node* current = head;
	while(current != NULL)
	{
		current = current->next;
		count++;
	}
	return count;
}

// Recursive Approach
int getCount(struct Node* head)
{
	// Base Case
	if (head == NULL) 
		return 0;
	// Count this node plus the rest of the list
	else
		return 1 + getCount(head->next);
}

/* Driver program to test count function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Use push() to construct below list
	1->2->1->3->1 */
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);

	/* Check the count function */
	printf("Count of nodes is %d\n", getCount(head));
	return 0;
}
