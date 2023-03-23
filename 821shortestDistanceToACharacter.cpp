#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> res;
        vector<int> charPos;

        int n = s.length(), ind = 0;

        for (int i = 0; i < n; i++)
        {
            if (s.at(i) == c)
            {
                charPos.push_back(i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (ind == charPos.size() - 1)
            {
                // ending
                res.push_back(abs(i - charPos.at(ind)));
            }
            else
            {
                if (abs(i - charPos.at(ind)) > abs(i - charPos.at(ind + 1)))
                {
                    ind++;
                    res.push_back(abs(i - charPos.at(ind)));
                }
                else
                {
                    res.push_back(abs(i - charPos.at(ind)));
                }
                
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string k="leetcode";
    char c='e';
    vector<int> res=s.shortestToChar(k,c);

    for(auto i:res){cout<<i<<endl;}
    return 0;
}