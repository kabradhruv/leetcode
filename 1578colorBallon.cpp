#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int res = 0;
        for (int i = 0; i < colors.length(); i++)
        {
            if (colors[i] == colors[i-1])
            {
                res+=min(neededTime[i-1],neededTime[i]);
                neededTime[i]=max(neededTime[i-1],neededTime[i]);
            }
        }
        return res;
    }
};

int main()
{
    // string colors = "aabaa";vector <int> neededTime{1,2,3,4,1};
    string colors = "abc";vector <int> neededTime{1,2,3};
    // string colors = "abaac";vector <int> neededTime{1,2,3,4,5};
    // string colors = "aaabbbabbbb";vector<int> neededTime{3,5,10,7,5,3,5,5,4,8,1}; // 8+8+8+1
    // string colors = "bbbaaa";vector <int> neededTime{4,9,3,8,8,9};
    Solution s;
    int res = s.minCost(colors, neededTime);
    cout << res << endl;
    return 0;
}