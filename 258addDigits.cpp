#include<iostream>
using namespace std;


class Solution {
public:
    int addDigits(int num) {
        int r=0,sum=0;

        // checking if number is only 1 digits 
        if (num<=9)
        {
            return num;
        }
        while (num >= 10)
        {
            sum=0;
            while (num!=0)
            {
                r=num%10;
                sum+=r;
                num/=10;
            }
            num=sum;
        }
        return sum;
    }
};


int main(){
    // int n=38;
    int n=123;
    Solution s;
    cout<<s.addDigits(n);
    return 0;
}