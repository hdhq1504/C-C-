// Simple C code to delete node at particular position
#include <stdio.h>
#include <stdlib.h>

void insert(struct list &l, int value);
void display_List(struct list l);
void deleteNth(list &l, int pos);

struct node // Structure declaration
{
    int data;
    struct node *next; // Self referral pointer
};

struct list
{
    struct node *head = NULL;
    struct node *tail = NULL;
};

void insert(struct list &l, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node)); // Allocating dynamic memory

    newnode->data = value; // Assigning value to newnode
    newnode->next = NULL;

    if (l.head == NULL) // Checking if List is empty
    {
        l.head = l.tail = newnode;
    }
    else // If not empty then...
    {
        l.tail->next = newnode;
        l.tail = newnode; // Updating the tail node with each insertion
    }
    return;
}

void display_List(struct list l)
{
    struct node *temp = l.head; // Creating a temporary pointer & temp points to head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d->NULL", temp->data);
        }
        else
        {
            printf("%d->", temp->data);
        }
        temp = temp->next; // Traversing the List till end
    }
    printf("\n");
    return;
}

void deleteNth(struct list &l, int pos)
{
    struct node *p = l.head;
    struct node *q = l.head->next; // q pointer points to the node to be deleted
    if (pos == 0)
    {
        printf("\nElement is deleted: %d\n", p->data);
        l.head = l.head->next;
        free(p);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        printf("\nElement is deleted: %d\n", q->data);
        delete (q);
    }
    printf("\nUpdate linked list is:\n");
    display_List(l);
    return;
}

// --Driver Code--
int main()
{
    struct list l;

    insert(l, 10);
    insert(l, 20);
    insert(l, 30);
    insert(l, 40);
    insert(l, 50);
    insert(l, 60);

    printf("\n--Created Linked List--\n");
    display_List(l);

    printf("\nLinked list after deletion the position at 0");
    deleteNth(l, 0);

    printf("\nLinked list after deletion the position at 2");
    deleteNth(l, 2);

    return 0;
}