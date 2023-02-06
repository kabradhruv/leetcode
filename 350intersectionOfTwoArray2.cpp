#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;

        // it = to check if the element is present in the nums2 array 
        vector<int>::iterator it;

        for (auto i : nums1)
        {
            it = find(nums2.begin(), nums2.end(), i);
            if (it != nums2.end())
            {
                nums2.erase(it);
                res.push_back(i);
            }
        }
        return res;
    }
};


int main()
{
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2};
    vector<int> res;
    Solution s;
    res=s.intersect(nums1, nums2);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}