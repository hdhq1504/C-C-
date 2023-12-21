#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXP 100

int isOperator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '%':
        return 1;
    }
    return 0;
}

char *preToInfix(char *prefix)
{
    char *stack[MAX_EXP];
    int top = -1;

    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {
            char *op1 = stack[top--];
            char *op2 = stack[top--];

            char temp[MAX_EXP];
            sprintf(temp, "(%s%c%s)", op1, prefix[i], op2);

            stack[++top] = strdup(temp);
        }
        else
        {
            char operand[2] = {prefix[i], '\0'};
            stack[++top] = strdup(operand);
        }
    }
    return stack[top];
}

int main()
{
    char prefix[] = "+-*AB/CDE";
    printf("Prefix: %s\n", prefix);
    char *infix = preToInfix(prefix);
    printf("Infix: %s\n", infix);
    free(infix);
    return 0;
}