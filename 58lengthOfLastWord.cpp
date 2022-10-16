#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        //to get the index of last character
        int index=0;
        int lstcheck=0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]==' ')
            {
                lstcheck=0;
            }
            else if (s[i]!=' ' && lstcheck == 0)
            {
                index=i;
                lstcheck=1;
            }
        }
        // to geth the length
        int len=0;
        while ((s[index]!=' ') && (index!=s.length()))
        {
            len++;            
            index++;
        }
        cout<<"Check"<<endl;
        
        return len;
    }
};


//alternative approach from leetcode 
/*
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i] == ' ' && ans > 0) return ans;
            if(s[i] != ' ') ans++;
        }
        return ans;
    }
};
*/


int main(){
    Solution res;
    // string s="Hello World";
    // string s="luffy is still joyboy";
    string s="   fly me   to   the moon  ";
    cout<<res.lengthOfLastWord(s)<<endl;
    return 0;
}