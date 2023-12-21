#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

void push(struct ListNode **head_ref, int new_data)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void reorderList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;

    // Find middle
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode *curr = slow->next;
    struct ListNode *prev = NULL;
    slow->next = NULL;
    while(curr)
    {
        struct ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    // Merge two halves
    struct ListNode *first = head, *second = prev;
    while (second)
    {
        struct ListNode *tmp1 = first->next;
        struct ListNode *tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}

void display_List(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Driver's Code
int main()
{
    // Create a sample linked list
    struct ListNode *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    // Print the original linked list
    printf("Original linked list: ");
    display_List(head);

    // Reorder the linked list
    reorderList(head);

    // Print the reordered linked list
    printf("Reordered linked list: ");
    display_List(head);

    // Free the memory
    while (head != NULL)
    {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
