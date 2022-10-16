#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// first approach
/*
class Solution
{
public:
    vector<int> incre(vector<int> &digits, int len)
    {
        if (len == 0)
        {
            // if no nmber then we have to add before it
            digits[len] = 0;
            vector<int>::iterator iter = digits.begin();
            digits.insert(iter, 1, 1);
        }
        else if (digits.at(len-1) != 9 && len != 0)
        {
            // if there is number before it which is not 9
            digits[len] = 0;
            digits[len - 1]++;
        }
        else if (digits[len - 1] == 9)
        {
            // if the last number is again 9
            digits[len] = 0;
            digits = incre(digits, len - 1);
        }
        else
        {
            cout << "Something else occures" << endl;
        }
        return digits;
    }

    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.back() != 9)
        {
            digits.back()++;
        }
        else
        {
            digits = incre(digits, digits.size() - 1);
        }
        return digits;
    }
};
*/

//second failed approach to convert the vector to integer then increment then convert it back to vector
/*
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // convert vector into integer
        long long num = digits[0];
        for (int i = 1; i < digits.size(); i++)
        {
            num = (num * 10) + digits[i];
            // cout<<num<<endl;
        }
        // increment the integer
        num++;
        // convert integer into vector
        vector<int> res;
        int r = 0;
        for (int i = 0; num>0; i++)
        {
            r = num % 10;
            num = num / 10;
            res.push_back(r);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
*/


// third approach according to leet code 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1;i >= 0;i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};

int main()
{
    vector<int> digits{9};
    // vector<int> digits{2, 4, 3, 1, 9, 9};
    // vector<int> digits{2,4,3,1, 5, 8};
    // vector<int> digits{9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<int> res;
    Solution s;
    res = s.plusOne(digits);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}