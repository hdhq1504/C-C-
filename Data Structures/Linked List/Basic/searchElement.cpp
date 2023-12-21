#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

/* Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list.*/
void push(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

// Iterative Approach
bool search(struct Node* head, int x)
{
	struct Node* current = head;
	while(current != NULL)
	{
		if(current->data == x)
			return true;
		current = current->next;
	}
	return false;
}

// Recursive Approach
bool search(struct Node* head, int x)
{
	if(head == NULL)
		return false;
	if(head->data == x)
		return true;
	else
		return search(head->next, x);
}

/* Driver code*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
	int x = 21;

    /* Use push() to construct below list 14->21->11->30->10  */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

	search(head, x)? printf("Yes") : printf("No");
    return 0;
}
