#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
        {
            return true;
        }
        for (int i = 0; i <= num / 2; i++)
        {
            if (i * i == num)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int num = 16;
    cout<<INT32_MAX;
    cout << s.isPerfectSquare(num) << endl;
    return 0;
}