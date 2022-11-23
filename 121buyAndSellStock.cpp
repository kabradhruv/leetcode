#include <iostream>
#include <vector>
using namespace std;

// Code by = Himanshu Malik
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int lsf = INT_MAX;           // least so far
        int op = 0;                  // overall profit
        int pist = 0;                // profit if sold today

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < lsf)
            {                         // if we found new buy value which is more smaller then previous one
                lsf = prices[i];      // update our least so far
            }
            pist = prices[i] - lsf;   // calculating profit if sold today by, Buy - sell
            if (op < pist)
            {                         // if pist is more then our previous overall profit
                op = pist;            // update overall profit
            }
        }
        return op;                    // return op
    }
};

int main()
{
    // vector<int> v1{7, 1, 5, 3, 6, 4};
    // vector<int> v1{1,2};
    vector<int> v1{7, 6, 4, 3, 1};
    Solution s;
    int res = s.maxProfit(v1);
    cout << res;
    return 0;
}