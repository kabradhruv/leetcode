#include <iostream>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// Temporary guess fucntion for testing
/*
int guess(int n){
    if (n==6)
    {
        return 0;
    }
    if (n<6)
    {
        return 1;
    }
    if (n>6)
    {
        return -1;
    }
    
}
*/
class Solution
{
public:
    int guessNumber(int n)
    {
        int low = 1;
        long long int end = n,mid;
        while (low <= end)
        {
            mid = (low + end) / 2;
            if (guess(mid) == -1)
            {
                end = mid-1;
            }
            else if (guess(mid) == 1)
            {
                low = mid+1;
            }
            else
            {
                return mid;
            }
        }
        return mid;
    }
};

int main()
{
    Solution s;
    cout<<s.guessNumber(10)<<endl;
    return 0;
}