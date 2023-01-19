#include<iostream>
#include<vector>
#include<string>  
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> st;
        string temp;
        for (int i = 1; i <= n; i++)
        {
            if (i%3 == 0 && i%5 == 0)
            {
                st.insert(st.end(),"FizzBuzz");
            }
            else if (i%3 == 0 && i%5 != 0)
            {
                st.insert(st.end(),"Fizz");
            }
            else if (i%3 != 0 && i%5 == 0)
            {
                st.insert(st.end(),"Buzz");
            }
            else if (i%3 != 0 && i%5 != 0)
            {
                temp= to_string(i);  
                st.insert(st.end(),temp);
            }
        }
        return st;
    }
};

int main(){
    Solution s;
    int n=15;
    vector<string> st=s.fizzBuzz(n);
    return 0;
}