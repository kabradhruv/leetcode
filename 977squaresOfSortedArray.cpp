#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            nums.at(i) = nums.at(i) * nums.at(i);
        }
        sort(nums.begin() , nums.end());
        return nums;
    }
};


int main(){
    vector<int> nums = {-4,-1,0,3,10};
    Solution s;
    vector<int> res = s.sortedSquares(nums);

    for(auto j:res){
        cout<<j<<endl;
    }

    return 0;
}