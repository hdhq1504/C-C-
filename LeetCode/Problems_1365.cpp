#include <stdio.h>
#include <stdlib.h>

/*Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Example 1:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
*/

int *smallerNumberThanCurrent(int *nums, int numsSize, int *returnSize)
{
    int *result = (int *)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++)
    {
        int count = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] < nums[i])
            {
                count++;
            }
        }
        result[i] = count;
    }

    *returnSize = numsSize;
    return result;
}

int main()
{
    int nums[] = {8, 1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int *result = smallerNumberThanCurrent(nums, numsSize, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
