// Input:  1->10->30->14,  index = 2
// Output: 30  
// The node at index 2 is 30

// C program to find n'th node in linked list
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
  
// Link list node
struct Node 
{
    int data;
    struct Node* next;
};
  
/* Given a reference (pointer to pointer) to the head of a 
list and an int, push a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
  
    // allocate node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  
    // put in the data
    new_node->data = new_data;
  
    // link the old list of the new node
    new_node->next = (*head_ref);
  
    // move the head to point to the new node
    (*head_ref) = new_node;
}

int GetNth(struct Node* head, int index)
{
    struct Node *current = head;
    int count = 0;
    while(current != NULL)
    {
        if(count == index)
            return current->data;
        count++;
        current = current->next;
    }
}

// Driver Code
int main()
{
    // Start with the empty list
    struct Node* head = NULL;
  
    // Use push() to construct below list
    // 1->12->1->4->1
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
  
    // Check the count function
    printf("Element at index 3 is %d", GetNth(head, 3));
    getchar();
}