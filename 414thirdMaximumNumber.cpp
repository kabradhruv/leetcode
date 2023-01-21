#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
        {
            return (nums.at(nums.size() - 1));
        }
        int last = nums.at(nums.size() - 1);
        int ind = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums.at(i) < last && ind < 3)
            {

                last = nums.at(i);
                ind++;
            }
            if (ind == 3)
            {

                return last;
            }
        }
        if (ind < 3)
        {
            return (nums.at(nums.size() - 1));
        }
        return 0;
    }
};

int main()
{
    // vector<int> x{3, 2, 1};
    // vector<int> x{21,43,53,28,93,14,37,29};
    // vector<int> x{1,2};
    // vector<int> x{1,1,2};
    // vector<int> x{2,2,3,1};
    Solution s;
    cout << s.thirdMax(x);
    return 0;
}