#include <iostream>
#include <vector>
using namespace std;

void printTwoDVector(vector<vector<int>> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res(numRows);
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> col(i, 1);
            if(i >= 3)
            {
                for (int j = 1; j < i - 1; j++) // 3
                {
                    col[j] = res[i - 2][j - 1] + res[i - 2][j];
                }
            }
            res[i-1] = col;
        }
        return res;
    }
};

int main()
{
    int numRows = 50;
    Solution s;
    vector<vector<int>> res = s.generate(numRows);
    printTwoDVector(res);

    return 0;
}