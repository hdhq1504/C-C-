#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackNode
{
	int data;
	struct StackNode *next;
};

int isEmpty(struct StackNode *top)
{
	if (top == NULL)
		return 1;
	return 0;
}

void push(struct StackNode **top, int new_data)
{
	struct StackNode *new_node = (struct StackNode *)malloc(sizeof(struct StackNode));
	if (new_node == NULL)
	{
		printf("\nStack Overflow.\n");
		return;
	}
	new_node->data = new_data;
	new_node->next = (*top);
	(*top) = new_node;
}

int pop(struct StackNode **top)
{
	if (isEmpty(*top))
		return 0;
	struct StackNode *temp = *top;
	(*top) = (*top)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int isMatchingPair(char ch1, char ch2)
{
	if (ch1 == '{' && ch2 == '}')
		return 1;
	else if (ch1 == '(' && ch2 == ')')
		return 1;
	else if (ch1 == '[' && ch2 == ']')
		return 1;
	return 0;
}

int areBalancedParenthesis(char exp[])
{
	struct StackNode *stack = NULL;
	int len = strlen(exp);

	for (int i = 0; i < len; i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			push(&stack, exp[i]);

		if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
			if (stack == NULL)
				return 0;
			else if (!isMatchingPair(pop(&stack), exp[i]))
				return 0;
	}
	if (stack == NULL)
		return 1;
	return 0;
}

int main()
{
	char exp[100] = "[()]{}{[()()]()}";
	printf("Expressions: %s", exp);
	if (areBalancedParenthesis(exp))
		printf("\nBalanced\n");
	else
		printf("\nNot balanced\n");
	getchar();
}