#include <iostream>
#include <vector>
using namespace std;

/*
Bitwise XOR Operator(^) has three properties:

a^a = 0
0^a = a
XOR is associative just like addition, multiplication, etc which means that -> a^b^c = a^(b^c) = (a^b)^c = (a^c)^b
So, when we XOR all the numbers in the list, all the numbers that occur 2 times become 0 as a^a = 0. At the end,
we will be left with an expression like 0^n, where n is the only number occurring once. Using second property
0^a = a :- 0^n = n. Hence, we get the unique number.
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int a : nums)
            {res ^= a;}
        return res;
    }
};

int main()
{
    vector<int> vec1{4, 1, 2, 1, 2};
    vector<int> vec2{2, 2, 1};
    vector<int> vec3{1};
    vector<int> vec4{1, 0, 1};
    Solution s;
    cout << "Result is = " << s.singleNumber(vec1);
    return 0;
}