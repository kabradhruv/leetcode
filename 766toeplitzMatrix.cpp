#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size()-1; i++)
        {
            for (int j = 0; j < matrix[i].size()-1; j++)
            {
                if (matrix[i][j]!=matrix[i+1][j+1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// 9508874472
int main()
{
    vector<vector<int>> vect{
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}};

    vector<vector<int>> vect2{
        {1, 4},
        {5, 3}};

    vector<vector<int>> vect3{
        {7,8,9},
        {6,7,8},
        {5,6,7}
    };
    Solution s;
    cout << s.isToeplitzMatrix(vect3) << endl;
    return 0;
}