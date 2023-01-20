#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int i = 0, j = n;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (isBadVersion(mid) == true && isBadVersion(mid - 1) == false)
            {
                return mid;
            };
            else if (isBadVersion(mid) == false)
            {
                i = mid + 1;
            };
            else
            {
                j = mid - 1;
            };
        }
        return -1;
    }
};

int main()
{
    int version = 6;
    Solution s;
    cout << s.firstBadVersion(version);
    return 0;
}