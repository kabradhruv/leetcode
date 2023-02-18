#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0,k=0;
        for (int i = 0; i < nums.size();)
        {
            if (i==nums.size()-k && nums.at(i) == 0)
            {
                break;
            }
            
            if (nums.at(i)==0)
            {
                k++;
                j=i;
                while(j<nums.size()-1){
                    nums.at(j)=nums.at(j+1);
                    nums.at(j+1)=0;
                    j++;
                }
            }
            else{
                i++;
            }
        }
    }
};


int main(){
    // vector<int> nums{0,1,0,3,12};
    vector<int> nums{0,0,1};
    Solution s;
    s.moveZeroes(nums);
    for(auto i:nums){
        cout<<i<<endl;
    }
    return 0;
}