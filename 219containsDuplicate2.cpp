#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {

            if (m.count(nums[i]))
            {
                {
                    if (abs(m[nums[i]] - i) <= k)
                    {
                        return true;
                    }
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    // vector<int> nums {1,2,3,1};
    // int k = 3;

    vector<int> nums{1, 2, 3, 1, 2, 3};
    int k = 2;
    Solution s;
    cout<<s.containsNearbyDuplicate(nums ,k);

    return 0;
}

