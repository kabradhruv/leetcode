#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


class Solution {
public:
    // Keep dividing p / q
    int Divide(int p, int q) {
        while (p % q == 0) {
            p /= q;
        }
        return p;
    }
    bool isUgly(int n) {
        // A negative integer cannot be ugly
        if (n <= 0) {
            return false;
        }

        // Factorization by 2 3 5
        for (auto fact : {2, 3, 5}) {
            n = Divide(n, fact);
        }
        
        // Check if the integer is reduced to 1 or not.
        return (n == 1);
    }
};


int main(){
    Solution s;
    int n=6;
    cout<<s.isUgly(n)<<endl;
    return 0;
}