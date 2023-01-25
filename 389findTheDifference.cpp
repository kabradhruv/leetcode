#include<iostream>
#include<map>
#include<vector>
using namespace std;


class Solution {
public:
    char findTheDifference(string s, string t) {

        // intializing variables and unorganised set <char,int>
        vector<int> r(26,0);
        int i;
        char k;

        // filling set with the string t
        for (int i = 0; i < t.length(); i++)
        {
            r.at(t.at(i)-97)++;
        }

        // comparing the vector with different string s
        for (i = 0; i < s.length(); i++)
        {  
            r.at(s.at(i)-97)--; 
        }

        // checking for i in the vector
        for (i = 0; i < 26; i++)
        {   
            if (r.at(i) == 1)
            {
                break;
            }
        }

        // returning the values 
        k=i+97;
        return k;
    }
};


int main(){
    string s="";
    string t="y";
    // string s="abcd";
    // string t="abcde";
    Solution z;
    cout<<z.findTheDifference(s,t);
    return 0;
}