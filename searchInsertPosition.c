#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
    // to check if ntarget is present
    for (int q = 0; q < numsSize; q++)
    {
        if (nums[q] == target)
        {
            return q;
        }
    }

    // to check where it can inserted

    // if target is greater than the last digit
    if (nums[numsSize - 1] < target)
    {
        return numsSize;
    }

    // if target is not greater than the last digit
    for (int w = 0; w < numsSize; w++)
    {

        if (nums[w] > target)
        {
            return w;
        }
    }
}

int main()
{
    int nums[] = {1, 3, 5, 6}, target = 7, numsSize = 4;
    int index = searchInsert(nums, numsSize, target);
    printf("%d", index);

    return 0;
}


// solution.c: In function ‘searchInsert’
// Line 30: Char 1: error: control reaches end of non-void function [-Werror=return-type] [solution.c]
//  }
//  ^
// cc1: some warnings being treated as errors