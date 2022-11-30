#include <iostream>
using namespace std;

class Solution
{
public:
    int mul(int n)//1
    {
        int a = 0;
        while (n != 0)
        {
            a += ((n % 10) * (n % 10));//9 13 14
            n /= 10;
        }
        return a;
    }
    bool isHappy(int n)
    {
        int a = 0, d = 0;
        while (a != 1)
        {
            a = mul(n);
            d++;
            n = a;
            if (d == 20)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    int n = 2;
    cout << s.isHappy(n) << endl;
    return 0;
}