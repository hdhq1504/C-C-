// C code to delete a node from linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int number;
	struct Node *next;
};

void Push(struct Node** head_ref, int data)
{
	struct Node* new_node = (struct Node *)malloc(sizeof(Node));
	new_node->number = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void deleteN(struct Node** head, int position)
{
	struct Node *temp = *head, *prev = *head;
	for (int i = 0; i < position; i++)
	{
		// If the deleted node is the first node
		if (i == 0 && position == 1)
		{
			(*head) = (*head)->next;
			free(temp);
		}
		// If don't, 
		else
		{
			if (i == position - 1 && temp)
			{
				prev->next = temp->next;
				free(temp);
			}
			else
			{
				prev = temp;

				// Position was greater than
				// number of nodes in the list
				if (prev == NULL)
					break;
				temp = temp->next;
			}
		}
	}
}

void printList(Node *head)
{
	while (head)
	{
		printf("[%i] [%p]->%p\n", head->number, head, head->next);
		head = head->next;
	}
	printf("\n\n");
}

// Drivers code
int main()
{
	struct Node *list = (struct Node *)malloc(sizeof(Node));
	list->next = NULL;
	Push(&list, 1);
	Push(&list, 2);
	Push(&list, 3);

	printList(list);

	// Delete any position from list
	deleteN(&list, 1);
	printList(list);
	return 0;
}
