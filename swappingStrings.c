#include <stdio.h>
#include <string.h>

void swap(char *str1, char *str2)
{
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int main()
{
    char strings[][100] = {"demonstration", "apple", "joyful", "friends", "battle", "incredible", "example", "great", "happy", "city"};
    printf("\nBefore Swapping\n");
    printf("at 0 = %s \n",strings[0]);
    printf("at 1 = %s \n",strings[1]);
    swap(strings[0],strings[1]);
    printf("\nAfter Swapping\n");
    printf("at 0 = %s \n",strings[0]);
    printf("at 1 = %s \n",strings[1]);


    return 0;
}
