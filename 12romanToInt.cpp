#include <iostream>
#include <vector>
using namespace std;

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        vector<int> varn{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> vara{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int p = 0, i = varn.size() - 1;

        // Inserting the values in the string
        while (i >= 0)
        {
            // we are checking if the number is greater than the integer at i and inserting some string while its true
            while ((num >= varn.at(i)) && (num / varn.at(i) <= 3))
            {
                num -= varn.at(i);
                res+=vara.at(i);
                p++;
            }
            i--;
        }
        return res;
    }
};

int main()
{
    Solution s;
    // int n=49;
    int n=9;
    // int n=58;
    // int n = 1994;
    cout << s.intToRoman(n)<<"--";
    return 0;
}