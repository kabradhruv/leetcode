#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:

    char check(char a){
        if (a == '}')
        {
            return '{';
        }
        if (a == ']')
        {
            return '[';
        }
        if (a == ')')
        {
            return '(';
        } 
        return '-';
    }


    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            {
                stack.push(s[i]);
            }

            else if ((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))
            {
                if (stack.empty())
                {
                    return false;
                }
                
                if ((stack.top()) != check(s[i]))
                {
                    return false;
                }
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        if (!stack.empty())
        {
            return false;
        }
        return true;
    }
};



int main(){
    // string s="()[{[()[({[()]})][]]}]{}";
    string s="(";
    Solution res;
    cout<<res.isValid(s)<<endl;
    return 0;
}