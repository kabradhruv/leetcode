#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> check(60,0);
        int check2 = 0,len=0,count=0;

        for (int i = 0; i < s.length(); i++)
        {
            check.at(s.at(i)-65)++;
        }
        
        for (int i = 0; i < check.size(); i++)
        {
            if (check.at(i) >=2)
            {
                count = (check.at(i)%2==0?check.at(i):check.at(i)-1);
                check.at(i)-=count;
                len+=count;
            }
            if (check.at(i) == 1 && check2 ==0)
            {
                check2 = 1;
                len++;
            }
        }
        return len;
    }
};


int main(){
    Solution s;
    // string x = "abccccdd";
    string x = "AAAAAA";
    cout<<s.longestPalindrome(x);
    return 0;
}