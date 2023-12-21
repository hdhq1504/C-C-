#include <stdio.h>
#include <stdlib.h>

/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

Example:
Input: n = 5
Output: [-7,-1,1,3,4]
*/

int *sumZero(int n, int *returnSize)
{
    int *result = (int *)malloc(*returnSize * (sizeof(int)));
    *returnSize = n;
    for (int i = 0; i < n / 2; i++)
    {
        result[i] = i + 1;
        result[n / 2 + i] = (-1) * (i + 1);
    }

    if (n % 2 != 0)
    {
        result[n - 1] = 0;
    }
    return result;
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int returnSize = 0;
    int *result = sumZero(n, &returnSize);

    printf("Array contains %d elements that they add up to 0:\n", returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}