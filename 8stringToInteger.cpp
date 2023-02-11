#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.length(), signCount = 0;
        bool isNeg = true;
        long long res = 0;

        // checking is there is any length
        if (n==0)
        {
            return 0;
        }
        
        // checking the satrting parts
        while ( i<n && (s.at(i) < 48 || s.at(i) > 57) && signCount < 1)
        {
            // checking for whitespace
            if (s.at(i) == 32)
            {
                i++;
                continue;
            }
            
            // checking for positive sign
            if (s.at(i) == 43)
            {
                signCount++;
                i++;
                continue;
            }

            // checking for negative sign
            if (s.at(i) == 45)
            {
                signCount++;
                i++;
                isNeg = false;
                continue;
            }
            return 0;
        }

        // different loop for digits
        while (i < n && res<=INT_MAX)
        {
            // if its a number
            if (s.at(i) >= 48 && s.at(i) <= 57)
            {
                res *= 10;
                res += s.at(i) - 48;
            }
            else
            {
                break;
            }
            i++;
        }

        if (!isNeg)
        {
            res = res - (res * 2);
        }
        if (res > INT_MAX)
        {
            return INT_MAX;
        }
        if (res < INT_MIN)
        {
            return INT_MIN;
        }
        return res;
    }
};


int main()
{
    // string  s = "42";
    // string  s = "+";
    // string  s = "    -42";
    // string  s = "4193 with words";
    // string  s = "words and 987";
    // string s = "-91283472332";
    // string s = "3.14159";
    // string s = "+-12";
    // string s = "  -0012a42";
    string s = "20000000000000000000";
    Solution x;
    cout << x.myAtoi(s);
    return 0;
}