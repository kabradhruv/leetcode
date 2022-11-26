#include <iostream>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string r;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]) || isalpha(s[i]))
            {
                r.push_back(tolower(s[i]));
            }
        }
        for (int i = 0, j = r.length() - 1; i < j; i++, j--)
        {
            if (r[i] != r[j])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    // string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    // string s = "0P";
    // string s= "ab2a";
    string s = "v' 5:UxU:5 v'";
    Solution r;
    cout << r.isPalindrome(s);
    return 0;
}