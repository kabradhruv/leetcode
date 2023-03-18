#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int arrangeCoins(int n) {
        int i=0;
        for (i = 1; i <= n; i++)
        {
            n-=i;
        }
        return i-1;
    }
};


int main(){
    Solution s;
    cout<<s.arrangeCoins(8)<<endl;
    return 0;
}