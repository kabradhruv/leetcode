#include <stdio.h>

// This function swaps values pointed by xp and yp
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// to print all the elements of a given list 
void printList(int *nums, int numsSize){
    for (int l = 0; l < numsSize; l++)
    {
        printf("%d. = %d\n",l,nums[l]);
    }
    
}
// to print all the elements of a given list 
void printListAgain(int *nums){
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    for (int l = 0; l < numsSize; l++)
    {
        printf("%d. = %d\n",l,nums[l]);
    }
    
}

int removeElement(int *nums, int numsSize, int val)
{
    int k = 0, j = 0;

    for (int i = 0; i < numsSize; i++)
    {
        printf("J = %d(%d) , I = %d(%d) , K = %d \n",j,nums[j],i,nums[i],k);
        if (nums[i] != val)
        {
            printf("Got inside the loop\n");
            nums[j] = nums[i];
            j++;
            k++;
        }
    }
    return k;
}

int main()
{
    int nums[] = {1, 2, 3,1,5,8,6,9,4,3,5,2,7,3};
    int numsSize=14;
    int val=3;
    int k=removeElement(nums, numsSize, val);
    printList(nums,14);
    printf("\n\n");
    printList(nums,14);
}