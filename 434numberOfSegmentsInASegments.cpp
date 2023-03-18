#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int countSegments(string s) {
        int count = 0;

        // checking of empty
        if (s.length() == 0)
        {
            return 0;
        }
        s.push_back(' ');
                
        for (int i = 0; i < s.length()-1; i++)
        {
            if (s.at(i) != ' ' && s.at(i+1) == ' ')
            {
                count++;
            }
        }

        return count;
    }
};


int main(){
    string x = "Hello, my name is John";
    // string x = "         ";
    Solution s;
    cout<<s.countSegments(x);
    return 0;
}