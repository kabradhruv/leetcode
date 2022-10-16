#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int check(int x,int y){
        
    }

    int mySqrt(int x) {
        vector<int> temp;
        for (int i = x/2; i >= 2; i--)
        {
            temp.push_back(i);
        }
        for (int i = 0; i < temp.size()-1; i++)
        {
            /* code */
        }
        
        // for(auto i : temp){
        //     cout<<i<<endl;
        // }
        
        return 9999;
    }
};

int main(){
    Solution s;
    int res=s.mySqrt(9);
    cout<<res;
    return 0;
}