#include <iostream>
using namespace std;

/*
single word= 26 posibilites
double = (single word) + (26*26=676)  totol = 702 posibilites
triple = (single word) + (26*26=676) + (26*26*26 = 17576)  totol = 18278 posibilites
abc=731     --> 3 + (26*2) + (26*26*1)
multiply 26 ot the power n and start from the last second
*/

class Solution
{
public:
    int titleToNumber(string n)
    {
        int len = n.length() - 1;
        int res;
        long con = 26;
        res = n[len] - 64;
        len--;

        while (len >= 0)
        {

            res += (((n[len] - 64) * con));
            con *= 26;
            len--;
        }

        return res;
    }
};

int main()
{
    // string cn = "ZY";
    // string cn = "A";
    // string cn = "AB";
    string cn = "FXSHRXW";
    Solution s;
    int res = s.titleToNumber(cn);
    cout << res;
    return 0;
}