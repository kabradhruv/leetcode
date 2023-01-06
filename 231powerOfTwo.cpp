#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 1)
        {
            return true;
        }
        if (n==0 || n<0)
        {
            return false;
        }
        while (n != 2)
        {
            if (n % 2 != 0)
            {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};

int main()
{
    // 1 2 4 8 16 32 64 128 256                1048576
    Solution s;
    int num = 6;
    cout << s.isPowerOfTwo(num);
    return 0;
}