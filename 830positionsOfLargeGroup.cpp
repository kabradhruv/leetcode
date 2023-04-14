#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        int start = 0, end = 0;
        vector<vector<int>> res;
        vector<int> r;

        for (int i = 0; i < s.length(); i++)
        {
            start = 0;
            end = 1;
            while (i < s.length()-1 && s.at(i) == s.at(i + 1))
            {
                end++;
                i++;
            }
            if (end - start >= 3)
            {
                r.clear();
                r.push_back((i - end)+1);
                r.push_back(i);
                res.push_back(r);
            }
        }
        return res;
    }
};

int main()
{
    string s = "abbxxxxzzy";
    Solution t;
    vector<vector<int>> res = t.largeGroupPositions(s);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res.at(i).size(); j++)
        {
            cout<<res.at(i).at(j)<<" ";
        }
        cout<<endl;
    }

    return 0;
}