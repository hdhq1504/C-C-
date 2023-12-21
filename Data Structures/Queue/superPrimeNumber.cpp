#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Cho một số n, hãy đưa số dãy số siêu nguyên tố nhỏ hơn hoặc bằng n, các số đã được sắp xếp tăng dần.
Input: 30
Output: 2 3 5 7 23 29
Với n = 30 thì superPrimeNumber(n) = [2, 3, 5, 7, 23, 29];
Vì các số 2, 3, 5, 7, 23 và 29 đều là số siêu nguyên tố và nhỏ hơn hoặc bằng 30. */
typedef int ItemType;
struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(ItemType data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Queue *q, ItemType data)
{
    struct Node *newNode = createNode(data);
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(struct Queue *q)
{
    if (q->front == NULL)
        return;

    struct Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    struct Queue q = {NULL, NULL};
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n && i < 10; i++)
    {
        if (isPrime(i))
            enqueue(&q, i);
    }

    while (q.front != NULL)
    {
        for (int i = 1; i <= 9; i++)
        {
            int k = q.front->data * 10 + i;
            if (k <= n && isPrime(k))
            {
                enqueue(&q, q.front->data * 10 + i);
            }
        }
        printf("%d ", q.front->data);
        dequeue(&q);
    }

    return 0;
}
