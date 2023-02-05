#include <iostream>
#include <vector>
using namespace std;

// Solution algorithm by - CoderrrMan
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i=0,j=height.size()-1,maxArea=0,minLength;
        while (i<j)
        {
            minLength = height.at(i)>height.at(j)?height.at(j):height.at(i);

            if (minLength * (j-i) > maxArea)
            {
                maxArea = minLength * (j-i);
            }

            if (height.at(i) < height.at(j))
            {
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<int> height {1,8,6,2,5,4,8,3,7};
    // vector<int> height {1,1};
    cout<<s.maxArea(height);
    return 0;
}