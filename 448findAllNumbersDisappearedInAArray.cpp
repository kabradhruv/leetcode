#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();

        sort(nums.begin(),nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums.at(i) == nums.at(i-1)) 
            {
                nums.at(i) = INT_MAX; 
            }
        }
        sort(nums.begin(),nums.end());

        for (int i = 0,j=1;j<=n;)
        {
            if (i<nums.size() && nums.at(i) != j) 
            {
                res.push_back(j);j++;
            }else{
                i++;j++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    // vector<int> nums{1, 1};
    vector<int> res = s.findDisappearedNumbers(nums); 
    for (auto i : res)
    {
        cout << i << endl;
    }
    return 0;
}