#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

/*
if two sign then 0
starting 0 and white spaces can be ignored
signs in between = 0
*/

// int myAtoi(char *s)
// {
//     int i = 0;          // for iterating the character
//     int isNegative = 0; // for checking if the umber is negative
//     int signCount = 0;  // counting if signs are more than 1 then res will be 0
//     long long res = 0;  // for result

//     // checking for signs
//     // to check fif sign is in the first
//     int varCount = 0; // to count variable in this loop
//     while (s[i] != '\0')
//     {
//         if (s[i] == '-' || s[i] == '+')
//         {
//             signCount++;
//         }
//         else if (s[i] != ' ')
//         {
//             varCount++;
//         }

//         if ((s[i] == '-' || s[i] == '+') && varCount > 0)
//         {
//             return 0;
//         }

//         if ((s[i] == ' ') && varCount > 0)
//         {
//             return 0;
//         }
//         i++;
//     }
//     // printf("Sign Count=%d\n",signCount);
//     i = 0;

//     while (s[i] != '\0')
//     {
//         if (48 <= s[i] && s[i] <= 57)
//         {
//             res = (res * 10) + (s[i]) - 48;
//         }

//         else if (s[i] == '-')
//         {
//             isNegative = 1;
//         }
//         else if (s[i] == ' ' || s[i] == '+')
//         {
//             ;
//         }
//         else
//         {
//             break;
//         }
//         i++;
//     }
//     // printf("Res=%d\n",res);
//     // checling for negative
//     if (isNegative)
//     {
//         res *= -1;
//     }

//     // checking the size
//     if (res <= INT_MIN)
//     {
//         return INT_MIN;
//     }
//     else if (res >= INT_MAX)
//     {
//         return INT_MAX;
//     }

//     return (signCount > 1 ? 0 : res);
// }

int myAtoi(char *s)
{
    int max = INT_MAX;
    int min = -INT_MIN;
    while (*s == ' ')
        s++;    
    int isNegative = *s == '-';
    if (*s == '-' || *s == '+')
        s++;
    int result = 0;

    while (*s)
    {
        int value = *s - '0';
        if (value < 0 || value > 9)
            break;
        // since result is an int it will overflow if this check is not done
        // alternatively make result wider and check if it is > or < the max or min.
        if (result > (max / 10) || (result == (max / 10) && value >= 8))
            return max;
        if (result < (min / 10) || (result == (min / 10) && value >= 9))
            return min;
        result *= 10;
        result += (isNegative ? -value : value);
        s++;
    }
    return result;
}

int main()
{
    // char a[] = "-91283472332";
    // char a[] = "   -42";
    // char a[] = "+-12";
    // char a[] = "00000-42a1234";
    char a[] = "   +0 123";
    printf("==%d\n", myAtoi(a));
    // printf("==%lld\n", INT_MAX);
    return 0;
}