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
    int length = 10;
    char temp[100];
    for (int i = 0; i < (length - 1); i++)
    {
        int j_min = i;
        // checking for i  and j
        for (int j = (i + 1); j < length; j++)
        {
            if (strcmp(strings[j], strings[j_min]) < 0)
            {
                j_min = j;
            }
        }
        printf("j_min = %s and i =%s\n", strings[j_min], strings[i]);
        if (j_min != i)
        {
            strcpy(temp, strings[i]);
            strcpy(strings[i], strings[j_min]);
            strcpy(strings[j_min], temp);
        }
    }
    // output the array of strings so we can see it is now sorted
    for (int i = 0; i < length; i++)
    {
        printf("%c\n", strings[i][i]);
    }

    return 0;
}
