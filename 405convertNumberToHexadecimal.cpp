#include <iostream>
using namespace std;

class Solution
{
public:
    char giveChar(int n)
    {
        if (n >= 0 && n < 10)
        {
            return n + 48;
        }
        else if (n >= 10 && n < 16)
        {
            return n + 97 - 10;
        }
        return '0';
    }

    string toHex(int n)
    {
        int rem;
        int ans;
        unsigned int num = n;
        string res;
        if (num == 0)
        {
            res.insert(res.begin(), giveChar(rem));
            return res;
        }
        if (num < 16)
        {
            res.insert(res.begin(), giveChar(num));
            return res;
        }
        while (num >= 16)
        {
            rem = num % 16;
            ans = num / 16;
            num /= 16;
            if (rem >= 0 && rem < 10)
            {
                res.insert(res.begin(), giveChar(rem));
            }
            else if (rem >= 10 && rem < 16)
            {
                res.insert(res.begin(), giveChar(rem));
            }
        }
        res.insert(res.begin(), giveChar(ans));
        return res;
    }
};

int main()
{
    // int num = 26;
    // int num = 545517;
    // int num = 16;
    int num = 0;
    Solution s;
    cout << s.toHex(num);

    return 0;
}