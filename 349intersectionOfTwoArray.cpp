#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        vector<int>::iterator it;
        vector<int>::iterator ip;
        // std::find function call
        for (auto i : nums1)
        {
            it = find(nums2.begin(), nums2.end(), i);
            ip = find(res.begin(), res.end(), i);
            if (ip == res.end() && it != nums2.end())
            {
                // cout << "Element " << i << " found at position : ";
                // cout << it - res.begin() << " (counting from zero) \n";
                res.push_back(i);
            }
        }

        // now removing the duplicate characters 

        // // Using std::unique
        // it = std::unique(res.begin(), res.end());
        // // Now v becomes {1 3 10 1 3 7 8 * * * * *}
    
        // // Resizing the vector so as to remove the undefined terms
        // res.resize(std::distance(res.begin(), it));

        // sorting the vector for removing the duplicates
        // sort(res.begin(),res.end());
        return res;
    }
};

int main()
{
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    vector<int> res;
    Solution s;
    res=s.intersection(nums1, nums2);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}