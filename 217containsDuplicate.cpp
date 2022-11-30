#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            if (set.find(nums[i])!=set.end())
            {
                // cout<<nums[i]<<" is checked"<<endl;
                return true;
            }
            set.insert(nums[i]);
            // for(auto i:set){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
        }
        return false;
    }
};

// another approach from set only 
// Set Approach

/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(),nums.end()).size();
    }
};
*/

int main(){
    // vector<int> m{1,1,1,3,3,4,3,2,4,2};
    vector<int> m{1,2,3,1};
    Solution s;
    cout<<s.containsDuplicate(m);
    
    return 0;
}