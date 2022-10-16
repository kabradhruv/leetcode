#include <stdio.h>
#include <stdbool.h>

bool areNumbersAscending(char *s)
{
    int q = 0; // for the while loop
    int lstNum = 0;
    int res = 0; // for 2 bit var
    while (s[q] != '\0')
    {
        if (s[q] >= '0' && s[q] <= '9')
        {
            res = s[q] - '0'; // declaring for every time

            if ((s[q + 1] >= '0' && s[q + 1] <= '9'))
            {
                res = 0;
                res += (s[q] - '0');
                q++;
                res *= 10;
                res += (s[q] - '0');
            }

            if (res <= lstNum)
            {
                return false;
            }
            else
            {
                lstNum = res;
            }
        }
        q++;
    }
    return true;
}


int main()
{
    char *s = "1 box has 3 blue 4 red 6 green and 12 yellow 13 marbles 20";
    printf("%d", areNumbersAscending(s));
    return 0;
}