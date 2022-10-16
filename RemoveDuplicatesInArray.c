#include <stdio.h>

void printArr(int *nums, int k)
{
    for (int i = 0; i < k; i++)
    {
        printf("at number %d the values is = %d\n", i, nums[i]);
    }
}



int removeDuplicates(int *nums, int numsSize)
{
    int k = 1;
    for (int j = 0; j < (numsSize-1); j++)
    {
        if (nums[j] != nums[j + 1])
        {
            // printf("comparing index %d  = %d and %d\n", j, nums[j], nums[j + 1]);
            nums[k] = nums[j+1];
            k++;
            
        }
        // printf("j= %d \n",j);
    }
    return k;
}
int main()
{
    int nums[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = 10;
    // int nums[10] = {1,1,2};
    // int numsSize = 3;
    // int nums[10] = {1,2};
    // int numsSize = 2;

    int k = removeDuplicates(nums, numsSize); // Calls your implementation
    printf("%d\n", k);
    printArr(nums, k);


    return 0;
}
