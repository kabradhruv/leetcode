#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};

int main(){
    Solution s;
    vector<char> r {'h','e','l','l','o'};
    s.reverseString(r);
    for(auto i:r){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}