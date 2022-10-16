#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// 1st approach mine failes due to memory error
/*
class Solution {
public:
    string addBinary(string a, string b) {
        int n1=0,n2=0;
        int base=0;
        
        // for converting string a to n1
        for (int i = a.size()-1; i >= 0; i--)
        {
            n1+=pow(2,base)*(a[i]-'0');
            // base*=2;
            base++;
        }
        base=0;
        // for converting string b to n2
        for (int i = b.size()-1; i >= 0; i--)
        {
            n2+=pow(2,base)*(b[i]-'0');
            // base*=2;
            base++;
        }

        // adding the decimal value
        int n3=n1+n2;
        if(n3==0)return "0";
        // int n3=5;
        // cout<<n1<<"--"<<n3<<endl;

        // making the result into a binary string
        string res;
        string r="0";
        while (n3)
        {
            r=(n3%2)+48;
            n3/=2;
            res.insert(0,r);
        }

        
        cout<<res<<endl;
        return res;
    }
};
*/
// 2nd approach accepted from leetcode solution

class Solution {
public:
string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string ans;
        int carry = 0;
        
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry += a[i] - '0';
                i--;
            }
            if(j>=0){
                carry += b[j] - '0';
                j--;
            }
            
            ans += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};


int main(){
    // string a = "1", b = "11";
    string a = "1010", b = "1011";
    // string a = "0", b = "0";
    Solution s;
    string res=s.addBinary(a,b);
    cout<<res;
    return 0;
}