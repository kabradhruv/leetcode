#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++)
        {
            s.at(i)=tolower(s.at(i));
        }
        return s;
    }
};


int main(){
    Solution s;
    string x="Hello";
    cout<<s.toLowerCase(x);
    return 0;
}