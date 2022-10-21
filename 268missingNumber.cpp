#include<iostream>
#include<vector>
using namespace std;

/*
starting a loop from 0 till n for i
mid_val=i
check=true
for loop to iterate the whole array and to check that i is present or not
if i is present than check = false
inner loop over
now check if check==true then return the i
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool check;
        for (int i = 0; i <= nums.size(); i++)
        {
            check=true;
            for(auto j:nums){
                if (j==i)
                {
                    check=false;
                }
            }
            if (check==true) return i;
            
        }//[1,2,3] 
        return 0; 
    }
};

int main(){
    vector <int> vec1 {3,0,1};
    vector <int> vec2 {0,1};
    vector <int> vec3 {5,3,1,2,4};
    Solution s;
    cout<<"Result is = "<<s.missingNumber(vec3);

    return 0;
}