#include<iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int num) {
        string a,b;
        while (num>26)
        {
            num%26==0?b="Z":b=(num%26)+64;
            num%26==0?(num=(num/26)-1):num/=26;
            a=b+a;
        }
        if (num<27){
            b=num+64;
            a=b+a;
        }
        return a;
    }
};

int main(){
    // int cn=702;
    // int cn=78;
    // int cn=52;
    // int cn=2147483647;
    int cn=18278;
    // int cn=731;
    Solution s;
    string res=s.convertToTitle(cn);
    cout<<res;
    return 0;
}