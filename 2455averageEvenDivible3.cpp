#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int tnum=0;
        int tsum=0;
        for(auto i:nums){
            if (i%6==0)
            {
                tnum++;
                tsum+=i;
            }   
        }
        return (tsum==0?0:tsum/tnum);
    }
};

int main(){
    Solution s;
    vector<int> nums{1,3,6,10,12,15};
    vector<int> nums1{1,2,4,7,10};
    cout<<s.averageValue(nums)<<endl;
    return 0;
}
