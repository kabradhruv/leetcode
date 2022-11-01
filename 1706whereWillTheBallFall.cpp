#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int r = grid.size();    // rows
        int c = grid[0].size(); // columns

        // defining the result vector 
        vector<int> res(c, -1);

        for (int j = 0; j < c; j++) // columns
        {
            int a = j; // columns
            int i = 0; // rows
            while (i < r)
            {
                if (a < 0 || a > c - 1)
                {
                    break;
                }
                if (a != (c - 1) && grid[i][a] == 1 && grid[i][a + 1] == 1) // for right
                {
                    i++;
                    a++;
                }
                else if (a != 0 && grid[i][a] == -1 && grid[i][a - 1] == -1) //for left
                {
                    i++;
                    a--;
                }
                else
                {
                    break;
                }
            }
            if (i >= r)
            {
                res.at(j) = a;
            }
        }
        return res;
    }
};


int main()
{
    vector<vector<int>> grid{
        {1, 1, 1, -1, -1},
        {1, 1, 1, -1, -1},
        {-1, -1, -1, 1, 1},
        {1, 1, 1, 1, -1},
        {-1, -1, -1, -1, -1}};

    vector<vector<int>> grid2{
        {1, 1, 1, 1, 1, 1},
        {-1, -1, -1, -1, -1, -1},
        {1, 1, 1, 1, 1, 1},
        {-1, -1, -1, -1, -1, -1},
    };

    Solution s;
    vector<int> res;
    res = s.findBall(grid2);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}