#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp = "";
        int p=0 ; // for patten index
        vector<string> vect;

        //inserting every word in vector
        for (int i = 0; i <= s.length(); i++)
        {
            if (i==s.length() || isspace(s.at(i))){
                vect.push_back(temp);
                temp = "";
            }
            else{
                temp += s.at(i);
            }
        }

        //checking if vector size > then s.size or vice versa
        if (vect.size() != pattern.size())
        {
            return false;
        }
        // Now the main Checking Loop
        for (int i = 0; i < vect.size(); i++)
        {
            for (int j = 0; j < vect.size(); j++)
            {
                if ((vect.at(i) == vect.at(j) || pattern.at(i) == pattern.at(j)) && j!=i)
                {
                    if (vect.at(i) != vect.at(j) || pattern.at(i) != pattern.at(j)){
                        return false;
                    }
                }
                
            }
        }
        return true;
    }
};
int main()
{
    // string pattern = "abba", s = "dog cat cat dog";
    string pattern = "abba", s = "dog cat cat fish";
    // string pattern = "aaa", s = "aa aa aa aa";
    Solution x;
    cout << x.wordPattern(pattern, s);
    return 0;
}