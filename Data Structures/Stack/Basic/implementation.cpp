// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct StackNode
{
    int data;
    struct StackNode *next;
};

struct StackNode *newNode(int data)
{
    struct StackNode *new_node = (struct StackNode *)malloc(sizeof(struct StackNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int isEmpty(struct StackNode *top)
{
    if(top == NULL)
        return 1;
    return 0;
}

void push(struct StackNode **top, int data)
{
    struct StackNode *new_node = newNode(data);
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode **top)
{
    if (isEmpty(*top))
        return INT_MIN;
    struct StackNode *temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode *top)
{
    if (isEmpty(top))
        return INT_MIN;
    return top->data;
}

int main()
{
    struct StackNode *top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("%d popped from stack\n", pop(&top));

    printf("Top element is %d\n", peek(top));

    return 0;
}
