#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if(n==1){
            return true;
        }

        // 3 cases are there if any one is right we return true
        int i=0;

        // 1. case  - if all upper case
        while (i<n && (word.at(i)>=65 && word.at(i)<=90))
        {
            i++;
        }
        if (i==n)
        {
            return true;
        }

        // 2. case  -if only 1st upper case
        i=1;
        while (i<n && (word.at(i)>=97 && word.at(i)<=122))
        {
            i++;
        }
        if (i==n && (word.at(0)>=65 && word.at(0)<=90) )
        {
            return true;
        }

        // 3. case  - if all lower case
        i=0;
        while (i<n && (word.at(i)>=97 && word.at(i)<=122))
        {
            i++;
        }
        if (i==n)
        {
            return true;
        }

        return false;   
    }
};


int main(){
    Solution s;
    // string word="USA";
    // string word="leetcode";
    // string word="ggg";
    // string word="Google";
    // string word="GoogLe";
    cout<<s.detectCapitalUse(word);
    return 0;
}