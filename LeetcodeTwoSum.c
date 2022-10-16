#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    // defining variable and pointers
    int x, y;
    int *ptr;
    // Allocating the memory 
    ptr = (int *)malloc(2 * sizeof(int));
    // getting the values of indexes in x and y 
    for (int k = 0; k < numsSize; k++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            // printf("k = %d and j = %d\n",k,j);
            if (nums[k] + nums[j] == target)
            {
                ptr[0] = k;
                ptr[1] = j;
                // printf("%d and %d", k, j);
                break;
            }
        }
    }
    // storing the index in 
    // ptr[0] = x;
    // ptr[1] = y;
    return ptr;
}

int main()
{
    int nums[10] = {4, 7, 11, 15, 3, 43, 12, 46, 17, 95};
    int target = 110;
    int numsSize = 10;
    // int answer[];
    int answer123[3];
    // answer=twoSum(nums,numsSize,target,answer123);
    int *add;
    add = twoSum(nums, numsSize, target, answer123);

    // Print the elements of the array
    printf("The indexes are : ");
    for (int i = 0; i <= 1; i++)
    {
        printf("%d ", add[i]);
    }
    free(add);
    return 0;
}