#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int canEat = candyType.size() / 2;
        int typesOfCandies = 1;

        // calculating Types Of Candies
        sort(candyType.begin(), candyType.end());
        for (int i = 1; i < candyType.size(); i++)
        {
            if (candyType.at(i) != candyType.at(i - 1))
            {
                typesOfCandies++;
            }
        }

        if (typesOfCandies > canEat)
        {
            // if alice has many types of candies which are greater than n/2 then she will try all
            return canEat;
        }
        else
        {
            // if alice can eat only n/2 but she has less variety she will eat only the number of types
            // if alice can eat n/2 can dies which are same sa types of candies then we can return anyone of them
            // else if (typesOfCandies <= canEat)
            return typesOfCandies;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> candyTypes{1, 1, 2, 2, 3, 3};
    cout << s.distributeCandies(candyTypes) << endl;
    return 0;
}