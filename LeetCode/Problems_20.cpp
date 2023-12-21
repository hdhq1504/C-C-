#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Stack
{
    char data;
    struct Stack *next;
};

typedef struct Stack Stack;

Stack *createStackNode(char data)
{
    Stack *node = (Stack *)malloc(sizeof(Stack));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Stack **top, char data)
{
    Stack *node = createStackNode(data);
    node->next = *top;
    *top = node;
}

char pop(Stack **top)
{
    if (*top == NULL)
        return '\0';

    char data = (*top)->data;
    Stack *temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

bool isValid(char *s)
{
    Stack *stack = NULL;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(&stack, s[i]);
        else
        {
            if (stack == NULL || (stack->data == '(' && s[i] != ')') || (stack->data == '{' && s[i] != '}') || (stack->data == '[' && s[i] != ']'))
                return false;

            pop(&stack);
        }
    }

    return stack == NULL;
}

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
