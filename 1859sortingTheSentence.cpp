#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;


class Solution
{
public:
    string sortSentence(string s)
    {
        string temp="";
        vector<string> pos(10);
        for (int i = 0; i < s.size(); i++)
        {
            if (!isdigit(s[i]))
            {
                temp+=s[i];
            }
            else
            {
                pos[s[i]-'0']=temp+" ";
                temp="";
                i++;
            }
            cout<<temp<<endl;
        }
        
        for(auto i:pos){
            // cout<<i<<"-"<<endl;
            temp+=i;
        }
        temp.pop_back();
        return temp;
    }


};



int main()
{
    string s = "is2 sentence4 This1 a3";
    Solution q;
    string res=q.sortSentence(s);
    cout<<res;
    return 0;
}