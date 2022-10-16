#include <stdio.h>
#include <stdlib.h>

char toLower(char n)
{
    if ((n >= 'A') && (n <= 'Z'))
    {
        n = n + 32;
        return n;
    }

    return n;
}

int isContainCharacter(char k, char *ltr0, char *ltr1)
{
    k = toLower(k);
    int i = 0;
    while (ltr0[i])
    {
        if (k == ltr0[i])
        {
            return 0;
        }
        i++;
    }
    i = 0;
    while (ltr1[i])
    {
        if (k == ltr1[i])
        {
            return 1;
        }
        i++;
    }
    return 2;
}

int isContainString(char *str, char *ltr0, char *ltr1)
{
    int i = 0, checkForL0 = 0, checkForL1 = 0, checkForL2 = 0;
    // check in letter 1
    while (str[i])
    {
        if ((isContainCharacter(str[i], ltr0, ltr1)) == 0)
        {
            ;
        }
        else
        {
            checkForL0++;
        }

        i++;
    }
    // check in to letter 2
    i = 0;
    while (str[i])
    {
        if ((isContainCharacter(str[i], ltr0, ltr1)) != 1)
        {
            checkForL1++;
        }
        i++;
    }
    // check for letter 3
    i = 0;
    while (str[i])
    {
        if ((isContainCharacter(str[i], ltr0, ltr1)) != 2)
        {
            checkForL2++;
        }
        i++;
    }
    // Dhruv Madar chod he. gandu he
    // to check if all the chcks incremented means the string does'nt belong to any of them
    if (checkForL0 > 0 && checkForL1 > 0 && checkForL2 > 0)
    {
        // return 0 means the string does'nt belong to any of the letters
        return 0;
    }
    else if (checkForL0 == 0 && checkForL1 > 0 && checkForL2 > 0)
    {

        // return 1 means string belongs to letter 1
        return 1;
    }
    if (checkForL0 > 0 && checkForL1 == 0 && checkForL2 > 0)
    {
        // return 2 means string belongs to letter 2
        return 2;
    }
    if (checkForL0 > 0 && checkForL1 > 0 && checkForL2 == 0)
    {
        // return 3 means string belongs to letter 3
        return 3;
    }

    // return 4 means and error or bug occurs as it should supposed to
    return 4;
}

char **findWords(char **words, int wordsSize, int *returnSize)
{
    // memory allocation for string array include 2 malloc
    // 1. for allocating
    // 2.for allocating for each character in a string
    // Allocating the memory for strings
    int totalStrings = 10;
    int wordSize = 15;
    char **ptrForStrings = malloc(totalStrings * sizeof(char *));
    int i;
    for (i = 0; i < totalStrings; ++i)
    {
        ptrForStrings[i] = (char *)malloc(wordSize + 1);
    }
    // memory allocated for array of strings

    // making a 2D array for letters
    char letters[][11] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    int temp = 0;
    int result;
    i = 0;

    for (int p = 0; p < wordsSize; p++)
    {
        result = (isContainString(words[i], letters[0], letters[1]));
        if (result == 1)
        {
            ptrForStrings[temp] = words[i];
            temp++;
        }
        else if (result == 2)
        {
            ptrForStrings[temp] = words[i];
            temp++;
        }
        else if (result == 3)
        {
            ptrForStrings[temp] = words[i];
            temp++;
        }
        else if (result == 4)
        {
            printf("Unknown bug occured for string =  (((%s))) as the function isContainingString returns 4\n", words[i]);
        }
        else if (result == 0)
        {
            printf("Not matched to anythng = (((%s))) as the function isContainingString returns 0\n", words[i]);
        }
        else
        {
            printf("Gone to to else of the find words function\n");
        }
        i++;
    }

    *returnSize = temp;
    return ptrForStrings;
}

int main()
{
    char *words[8] = {"Hello", "Alaska", "Dad", "Peace","qwerty","asdfghjkl","zxcvbnm","dhruvkabara"};
    int wordsSize = 8;
    int rsize;
    int *returnSize = &rsize;
    char **str=findWords(words, wordsSize, &rsize);

    // output the array of strings so we can see it is now sorted
    for (int i = 0; i < rsize; i++)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}
