#include <stdio.h>
#include <malloc.h>

/*
we have to find k elements from the array nearest to x

if x is an negative value or 0 then we will return the 1st k elementd from the list

no we will find the nearest integer to x in the array so position og=f the index will be a
a-1 = h and a+1 =t
start a while loop till k
if h==0 then  BREAK -As we are returning array + head so it will automatically adjust!!!!! we will add the remaining after the t
same if t==arrsize BREAK - As we are returning aray so we will return head-(roud of k in the loop )!!!then we will add the remaining elements from head to 0 till k

if (x-h)>(t-x){
    --------add t to the result
    t++;
}
else if (x-h)==(t-x){
    --------add t to the result
    t++;
    --------add h to the result ;
    h--;
}
else{
    --------add h to the result
    h--;
}

given array + h


*/

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findNum(int *arr, int arrSize, int num)
{
    if (arr[0] > num)
    {
        return 0;
    }

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] <= num && arr[i + 1] > num)
        {
            if ((num - arr[i]) <= (arr[i + 1] - num))
            {
                return i;
            }
            else
            {
                return (i + 1);
            }
        }
    }
    return -1;
}

int *findClosestElements(int *arr, int arrSize, int k, int x, int *returnSize)
{

    *returnSize = k;            // setting return size to k
    int i = 0;                  // for indexing
    int temp = 0, h = 0, t = 0; // for the loop

    // if x is negative or equal to 0  ||  and if first elemtn of array is x || if arrSize==k meaning we have to return the whole array
    if (x <= 0 || arr[0] == x || arrSize == k)
    {
        return arr;
    }

    // if the arr last element is = x
    if (arr[arrSize - 1] == x)
    {
        return (arr + (arrSize - k));
    }

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] <= x && arr[i + 1] > x)
        {
            if ((x - arr[i]) <= (arr[i + 1] - x))
            {
                temp = i;
            }
            else
            {
                temp = i + 1;
            }
        }
    }
    printf("temp = %d \n", temp);
    int head = temp - 1; // 2
    int tail = temp + 1; // 4

    h = x - arr[head];
    t = arr[tail] - x;

    for (int i = 0; i < k - 1; i++)
    {
        printf("head=%d and tail=%d,h = %d and t = %d and comparing between %d - %d\n", head, tail, h, t, arr[head], arr[tail]);

        // if (head == 0 || tail == (arrSize - 1))
        // {
        //     arr=head==0?arr:(arr+(head-1));
        //     return arr;
        // }
        if (tail == (arrSize - 1))
        {
            head--;
            h = x - arr[head];
        }

        else if (head == 0)
        {
            // printf("Inside 1 \n");
            return arr;
        }

        else if (h > t)
        {
            // printf("Inside 1 \n");
            tail++;
            t = arr[tail] - x;
        }
        else
        {
            // printf("Inside 2nd\n");
            head--;
            h = x - arr[head];
        }
    }

    return (arr + (head + 1));
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5}, k = 3, x = 5;
    // int arrSize = 5;

    // int arr[] = {1, 1, 1, 10, 10, 10}, k = 1, x = 9;
    // int arrSize = 6;

    // int arr[] = {1}, k = 1, x = 1;
    // int arrSize = 1;

    // int arr[] = {-2, -1, 1, 2, 3, 4, 5}, k = 7, x = 3,arrSize = 7;
    // int arr[] = {1, 2, 5, 5, 6, 6, 7, 7, 8, 9}, k = 7, x = 7, arrSize = 10;
    // int arr[] = {0,1,2,2,2,3,6,8,8,9}, k = 5, x = 9, arrSize = 10;
    int arr[] = {1, 2, 3, 3, 6, 6, 7, 7, 9, 9}, k = 8, x = 8, arrSize = 10;
    // int arr[] = {1,2,5,5,6,6,7,7,8,9}, k = 7, x = 7, arrSize = 10;

    int returnSize;
    int *result;
    result = findClosestElements(arr, arrSize, k, x, &returnSize);
    printArr(result, returnSize);
    // printf("%d\n", findNum(arr, arrSize, 6));
    return 0;
}