#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // first checking the length
        if (s.length() != t.length())
        {
            return false;
        }

        // we use map to check for the pair checking

        // and we use set because we can't directly find element i.e. <key,element>
        // from set and we need to keep track of that also in the function

        map<char, char> m;
        set<char> set;

        for (int i = 0; i < s.length(); i++)
        {
            // check for the key -value pair if it is already there in map then return false

            // first checking if character from s is present
            if (m.find(s[i]) != m.end())
            {
                // now checking if character matched from t
                if (m[s[i]] != t[i])
                {
                    return false;
                }
            }
            // if it is not present
            else
            {
                // now we will check from set that any character from t is already there or not
                if (set.find(t[i]) != set.end())
                {
                    return false;
                }
                // everything is checked now we will add it in both map and check
                m[s[i]] = t[i];
                set.insert(t[i]);
            }
        }
        return true;
    }
};


int main()
{
    Solution sol;
    string s = "paper";
    string t = "title";
    cout << sol.isIsomorphic(s, t);
    return 0;
}