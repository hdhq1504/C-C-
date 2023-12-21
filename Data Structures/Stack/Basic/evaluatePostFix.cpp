#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

// Cài đặt ngăn xếp (Stack)
struct Stack
{
    int items[MAX_STACK_SIZE];
    int top;
};

void initializeStack(Stack *s)
{
    s->top = -1;
}

int isStackEmpty(Stack *s)
{
    return (s->top == -1);
}

void push(Stack *s, int value)
{
    s->items[++s->top] = value;
}

int pop(Stack *s)
{
    if (!isStackEmpty(s))
        return s->items[s->top--];
    return -1;
}

// Hàm để tính giá trị của biểu thức hậu tố
int evaluatePostfix(char *exp)
{
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; exp[i]; ++i)
    {
        if (exp[i] == ' ')
        {
            continue;
        }
        else if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        else
        {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            switch (exp[i])
            {
            case '+':
                push(&stack, operand2 + operand1);
                break;
            case '-':
                push(&stack, operand2 - operand1);
                break;
            case '*':
                push(&stack, operand2 * operand1);
                break;
            case '/':
                push(&stack, operand2 / operand1);
                break;
            }
        }
    }
    return pop(&stack);
}

int main()
{
    char exp[] = "100 200 + 2 / 5 * 7 +";

    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}