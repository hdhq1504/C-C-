// C program to find N'th node from end
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    new_node->next = (*head_ref);

    /* 4. Update the new_node pointer points to the head */
    (*head_ref) = new_node;
}

// Recursive Approach
void printNthFromLast(struct Node *head, int N)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, N);
    if (++i == N)
        printf("%d", head->data);
}

// Iterative Approach
void printNthFromLast(Node *head, int N)
{
    int len = 0;
    Node *temp = head;

    // Count the number of nodes in Linked List
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    // Check if value of N is not more than length of the linked list
    if (len < N)
        return;
    temp = head;

    // Get the (len-N+1)th node from the beginning
    for (int i = 1; i < len - N + 1; i++)
        temp = temp->next;
    printf("%d", temp->data);
    return;
}

// Driver's Code
int main()
{
    /* Start with the empty list */
    struct Node *head = NULL;

    // Create linked 35->15->4->20
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    // Function call
    printNthFromLast(head, 4);

    return 0;
}