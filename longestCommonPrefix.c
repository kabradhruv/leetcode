#include <stdio.h>
#include <stdlib.h>

int checkPrefix(char *s1, char *s2)
{
    int x = 0;
    while (s1[x] != '\0')
    {
        if (s1[x] != s2[x])
        {
            break;
        }
        x++;
    }
    return x;
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    // returning nothing if only 1 element
    if (strsSize==1)
    {
        return strs[0];
    }

    int num = 0;
    int num1 = 0; // to check the old one
    for (int i = 0; i < (strsSize - 1); i++)
    {
        num = checkPrefix(strs[i], strs[i + 1]); // 0-1,1-2
        if (num>num1 && i!=0)
        {
            num=num1;
        }
        
        num1=num;
        if (num == 0)
        {
            break;
        }
    }
    
    char *str = (char *)malloc(sizeof(char) * (num + 1));
    str[num] = '\0';
    
    if (num != 0)
    {
        for (int i = 0; i < num; i++)
        {
            str[i] = strs[0][i];
        }
    }
    return str;
}



int main()
{
    char *strs[3] = {"acc","aaa","aaba"};
    int strsSize = 3;
    // char *strs[1] = {"a"};
    // int strsSize = 1;
    // char *strs[3] = {"flower", "flow", "flight"};
    // int strsSize = 3;
    char *str=longestCommonPrefix(strs, strsSize);
    printf("str = %s\n",str);

    // Output: "fl"
    return 0;
}