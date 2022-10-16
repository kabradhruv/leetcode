#include <stdio.h>
#include <stdbool.h>
bool isPalindrome(int x)
{
    int r = 0, s = 0, m = x;

    while (m > 0)
    {
        r = m % 10;
        m = m / 10;
        s = (s * 10) + r;
    }
    if (x == s)
    {
        return true;
    }
    return false;
}

int main()
{
    bool x=isPalindrome(123454321);
    if (x==true)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    
    return 0;
}
