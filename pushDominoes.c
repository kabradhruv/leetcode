#include <stdio.h>
#include <malloc.h>

// to print array
void printArr(char *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("---\n");
}

void printArrInt(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); 
    }
    printf("\n");
}

char *pushDominoes(char *dominoes)
{
    int i = 0;
    /*
    mkae two array - right push and left push
    fill it with the sec measures
    compare and put in the final one

    */

    // finding length of the string
    int len = 0;
    while (dominoes[len] != '\0')
    {
        len++;
    }

    // making tree array
    int *lftPush = (int *)malloc(sizeof(int) * len);
    int *rightpush = (int *)malloc(sizeof(int) * len);
    char *final = (char *)malloc((sizeof(char) * len) + 1);

    // filling the right push
    int lstRight = 0;
    while (dominoes[i] != '\0')
    {
        if ((dominoes[i] == '.') && (lstRight == 0))
        {
            rightpush[i] = 0;
        }
        else if ((dominoes[i] == '.') && (lstRight != 0))
        {
            rightpush[i] = lstRight;
            lstRight++;
        }
        else if (dominoes[i] == 'L')
        {
            lstRight = 0;
            rightpush[i] = 0;
        }
        else if (dominoes[i] == 'R')
        {
            rightpush[i] = 0;
            lstRight=1;
        }
        else
        {
            printf("Didnt get what to do in right oush \n");
        }
        i++;
    }

    // filling the left push
    int lstLeft = 0;
    i = 0;
    for (i = len - 1; i >= 0; i--)
    {
        if ((dominoes[i] == '.') && (lstLeft == 0))
        {
            lftPush[i] = 0;
        }
        else if ((dominoes[i] == '.') && (lstLeft != 0))
        {
            lftPush[i] = lstLeft;
            lstLeft++;
        }
        else if (dominoes[i] == 'L')
        {
            lstLeft=1;
            lftPush[i] = 0;
        }
        else if (dominoes[i] == 'R')
        {
            lftPush[i] = 0;
            lstLeft = 0;
        }
        else
        {
            printf("Didnt get what to do in right oush for character = %d\n", i);
        }
    }

    // comparing both the arrays
    i = 0;
    while (dominoes[i] != '\0')
    {
        if ((lftPush[i] == 0) && (rightpush[i] == 0))
        {
            final[i] = dominoes[i];
        }
        else if (lftPush[i]==0 && rightpush[i]!=0)
        {
            final[i] = 'R';
        }
        else if (lftPush[i]!=0 && rightpush[i]==0)
        {
            final[i] = 'L';
        }
        else if (lftPush[i] < rightpush[i])
        {
            final[i] = 'L';
        }
        else if (lftPush[i] > rightpush[i])
        {
            final[i] = 'R';
        }
        else if (lftPush[i] == rightpush[i])
        {
            final[i] = '.';
        }
        else
        {
            printf("Did'nt get what to do in right oush for character = %d\n", i);
        }
        i++;
    }
    final[len]='\0';
    free(lftPush);
    free(rightpush);
    return final;
}


int main()
{
    // char *s = ".L.R...LR..L..";
    char *s = "RR.L";
    printf("%s", pushDominoes(s));
    // pushDominoes(s);
    return 0;
}