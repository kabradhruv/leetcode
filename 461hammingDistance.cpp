#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> inBits(int x){
        vector<int> res;
        int r=0;
        while (x!=0)
        {
            r=x%2;
            res.insert(res.begin(),x%2);
            x/=2;
        }
        reverse(res.begin(),res.end());
        return res;
    }

    int hammingDistance(int x, int y) {
        vector<int> ax=inBits(x);
        vector<int> ay=inBits(y);
        int i=0,res=0,len=0;
        len=max(ax.size(),ay.size());

        for (int i = 0; i < len ; i++)
        {
            if ((i<ax.size() && i<ay.size() && ax.at(i) != ay.at(i)) || ((i>=ax.size() && i<ay.size() && ay.at(i) == 1)) || (i<ax.size() && i>=ay.size() && ax.at(i) == 1))
            {
                res++;
            }
        }

        return res;
    }
};


int main(){
    Solution s;
    int res=s.hammingDistance(1,4);
    // int res=s.hammingDistance(3,1);
    cout<<res<<endl;
    return 0;
}