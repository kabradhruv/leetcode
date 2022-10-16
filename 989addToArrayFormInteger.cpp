#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1st approach failed
/*
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int r = 0;
        int i = num.size() - 1; // for indexing purposes
        while (k > 0 || i >= 0)
        {
            r = k % 10;

            // if array is completed but the integer is longer than the array then we have inert element in the arra
            if (k != 0 && i < 0)
            {
                // cout << "here 2" << endl;
                num.insert(num.begin(), r);
            }
            k = k / 10;
            cout << k << " - " << r << " i=" << i << endl;

            if ((i>=0) && ((num.at(i) + r) > 9))
            {
                num[i] = (num[i] + r) % 10;
                if (i != 0)
                {
                    // cout << "herre" << endl;
                    num[i - 1]++;
                }
                else
                {
                    num.insert(num.begin(), 1);
                }
            }
            else if((i>=0) && ((num.at(i) + r) <= 9 && (num.at(i) + r) >= 0))
            {
                // cout << "here 1" << endl;
                num.at(i) += r;
            }

            i--;
        }
        return num;
    }
};
*/

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int r = 0; // for remainder
        // adding the element
        for (int i = num.size() - 1; i >= 0; i--)
        {
            r = k % 10;
            k /= 10;
            num.at(i) += r;
        }
        // adding the remaining element in the biginning
        while (k != 0)
        {
            r = k % 10;
            k /= 10;
            num.insert(num.begin(), r);
        }
        // iterating the array and converting them from 2 digits to 1
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if (i>0 && num.at(i)>9)
            {
                num.at(i)%=10;
                num.at(i-1)++;
            }
            else if (i==0 && num.at(i)>9)
            {
                num.at(i)%=10;
                num.insert(num.begin(),1);
            }
            
        }

        return num;
    }
};

int main()
{
    // vector<int> num{9};int k=1;
    // vector<int> num{2, 4, 3, 1, 9, 9};
    // vector<int> num{2, 4, 3, 1, 5, 8};int k = 4245; // 247403
    // vector<int> num{6};int k = 809;//247403
    // vector<int> num{0};
    // int k = 10000; // 247403
    // vector<int> num{9, 9, 9, 9, 9, 9, 9, 9, 9};
    // int k = 1;
    vector<int> num{0};
    int k = 23;

    vector<int> res;
    Solution s;
    res = s.addToArrayForm(num, k);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}