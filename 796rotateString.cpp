#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    bool rotateString(string s, string goal) {
        char temp;

        for(int i=0;i<s.length() && s!=goal;i++)
        {
            temp=s.at(0);
            s.erase(s.begin());
            s+=temp;
            // cout<<s<<endl;
        }
        
        if (s==goal)
        {
            return true;
        }

        return false;
        
    }
};


int main(){
    string s = "abcde", goal = "cdeab";
    // string s = "abcde", goal = "abced";
    Solution sol;
    cout<<sol.rotateString(s,goal);
    return 0;
}