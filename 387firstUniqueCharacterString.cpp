#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> num(26, 0);

        // filling num array and incrementing the place where the alphabet is 
        for (int i = 0; i < s.length(); i++)
        {
            num.at(s.at(i) - 97)++;
        }

        //now checking for letter.If the place for letter has 1 then return it
        for (int i = 0; i < s.length(); i++)
        {
            if (num.at(s.at(i)-97) == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    // string x="leetcode";
    // string x = "loveleetcode";
    string x="aabb";
    cout << s.firstUniqChar(x);
    return 0;
}