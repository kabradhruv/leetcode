#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int numberOfOnes(int n){
        int count=0;
        while(n>=2){
            if (n%2==1)
            {
                count++;
            }
            n/=2;
        }
        return (count+n);
    }

    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            res.push_back(numberOfOnes(i));
        }
        return res;
    }
};


int main(){
    int n=2;
    Solution s;
    vector<int> res;
    res=s.countBits(n);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}