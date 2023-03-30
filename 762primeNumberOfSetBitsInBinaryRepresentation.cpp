#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    /*
    Steps :
        1.start loop from left to <= right
        2.convert the i to bits
        3.count the One's and store in x
        4.Check if x is prime and if it then count++
        5.return count
    */

    int convertCheck(int n){
        vector<int> bitSet;
        int count=0;
        
        // saving bits in bitSet 
        while (n!=1)
        {
            bitSet.push_back(n%2);
            n/=2;
        }

        // for the correct order we have to reverse it but we just want the ones
        // bitSet.push_back(1); and for the right set we hav to add 1 but I am not because I will add it later

        for(auto j:bitSet){
            if (j==1)
            {
                count++;
            }
        }

        return count+1; //because we did't add it before        
    }

    bool isPrime(int n){

        if (n<=1)
        {
            return false;
        }
        

        for (int i = 2; i < n; i++)
        {
            if (n%i == 0)
            {
                return false;   
            }
        }

        return true;

    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            if (isPrime(convertCheck(i)))
            {
                count++;
            }
        }
        
        return count;
    }
};


int main(){
    Solution s;
    // int left = 6, right = 10;
    int left = 10, right = 15;
    cout<<s.countPrimeSetBits(left,right);
    return 0;
}