#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> res;
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int y = 0; y < nums.size(); y++)
            {
                if (nums[i] + nums[y] == target)
                {
                    res.push_back(i);
                    res.push_back(y);
                    return res;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{2, 7, 11, 15};
    Solution s;
    vector<int> res;
    res = s.twoSum(nums, 9);
    for (int i : res)
    {
        cout<<"array is - " ;
        cout<<i<<endl;
    }
    
    return 0;
}