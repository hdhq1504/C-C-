#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef char ItemType;
struct StackNode
{
    ItemType Info;
    StackNode *next;
};

struct Stack
{
    StackNode *top;
};

void initStack(Stack &s)
{
    s.top = NULL;
}

StackNode *createStackNode(ItemType x)
{
    StackNode *p = new StackNode;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat nut moi!");
        getch();
        return NULL;
    }
    p->Info = x;
    p->next = NULL;
    return p;
}

int isEmpty(Stack s)
{
    if (s.top == NULL)
        return 1;
    else
        return 0;
}

int push(Stack &s, StackNode *p)
{
    if (p == NULL)
        return 0;

    if (isEmpty(s) == 1)
        s.top = p;
    else
    {
        p->next = s.top;
        s.top = p;
    }
    return 1;
}

int pop(Stack &s, ItemType &x)
{
    if (isEmpty(s) == 1)
        return 0;
    StackNode *p = s.top;
    s.top = s.top->next;
    x = p->Info;
    delete p;
    return 1;
}

int getTop(Stack s, ItemType &x)
{
    if (isEmpty(s) == 1)
        return 0;
    x = s.top->Info;
    return 1;
}

void reverse(char str[])
{
    // Create a stack of capacity equal to length of string
    int n = strlen(str);
    Stack stack;
    initStack(stack);

    // Push all characters of string to stack
    for (int i = 0; i < n; i++)
    {
        StackNode *p = createStackNode(str[i]);
        push(stack, p);
    }

    // Pop all characters of stack and put them back to str
    for (int i = 0; i < n; i++)
    {
        ItemType x;
        pop(stack, x);
        str[i] = x;
    }
}

int main()
{
    char str[100];
    printf("Nhap chuoi: ");
    fflush(stdin);
    gets(str);
 
    reverse(str);
    printf("Chuoi sau khi dao nguoc: %s", str);
    return 0;
}
