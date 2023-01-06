#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> charSet;
        set<int> charLen;
        int check = 0;
        int last = 0;
        int sameCheck=0;
        if (s.length()==1)
        {
            return 1;
        }
        
        for (int i = 0; i < s.length();)
        {
            if (charSet.find(s[i]) != charSet.end())
            {   
                sameCheck=1;
                for(auto i:charSet){
                    cout<<i<<" ";
                }
                cout<<endl;
                cout<<i<<" is i and char = "<<s[i]<<" and check = "<<check<<" last = "<<last<<endl;
                charLen.insert(i-last);
                charSet.clear();
                check = 0;
                i = last + 1;
                last = 0;
                cout<<i<<" is i and char = "<<s[i]<<" and check = "<<check<<" last = "<<last<<endl;
                continue;
            }
            if (check == 0)
            {
                last = i;
                check = 1;
                sameCheck=0;
            }
            // cout<<i<<" is i and char = "<<s[i]<<" and check = "<<check<<" last = "<<last<<endl;
            cout<<"Inserting -->"<<s[i]<<endl;
            charSet.insert(s[i]);
            i++;
        }
        if (sameCheck==0)
        {
            charLen.insert(charSet.size());
        }
        
        check=0;
        for(auto i:charLen){
            if (i>check)    
            {
                check=i;
            }
        }
        return check;
    }
};



int main()
{
    Solution s;
    // string r = "bbbb";
    string r = "abcabcbb";
    // string r = "aab";
    int res=s.lengthOfLongestSubstring(r);
    cout<<res;
    return 0;
}