#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int s = 0;
        while (x != 0)
        {
            if (s*10 > INT32_MAX || s*10 < INT32_MIN)
            {
                return 0;
            }
            s = (s * 10) + (x % 10);
            x /= 10;
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(321);
    return 0;
}