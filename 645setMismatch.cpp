#include <iostream>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

// First element shouldbe the number that occurs twice
//  and second number should be that is missing

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> res;
        int ExpectedSumOfArray = ((nums.size()) * ((nums.size()) + 1)) / 2;//6
        int sumOfNumsWithDuplicate = accumulate(nums.begin(),nums.end(),0);//7
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int sumOfSortedSetWithNoDuplicate=accumulate(s.begin(),s.end(),0);//4
        res.push_back(sumOfNumsWithDuplicate-sumOfSortedSetWithNoDuplicate);
        res.push_back(ExpectedSumOfArray-sumOfSortedSetWithNoDuplicate);
        return res;
    }
};

int main()
{
    // vector<int> nums{2, 2};
    // vector<int> nums{1,1};
    // vector<int> nums{1,2,2,4};
    // vector<int> nums{2, 3, 2};
    vector<int> nums{3, 3, 1};
    // vector<int> nums{3, 2, 2};
    vector<int> res;
    Solution s;
    res = s.findErrorNums(nums);
    for (auto i : res)
    {
        cout << i << endl;
    }

    return 0;
}