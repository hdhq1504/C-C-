// Iterative C program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node 
{
	int data;
	struct Node* next;
};

/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Function to reverse the linked list */
static void reverse(struct Node **head_ref)
{
	struct Node *prev = NULL;
	struct Node *current = (*head_ref);
	struct Node *next = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*head_ref) = prev;
}

/* Function to print linked list */
void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) 
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	/* Print the original linked list */
	printf("Given linked list\n");
	printList(head);
	
	reverse(&head);
	
	/* Print the reversed linked list */
	printf("\nReversed linked list \n");
	printList(head);
	
	getchar();
}