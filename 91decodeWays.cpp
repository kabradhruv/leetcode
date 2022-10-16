#include <iostream>
#include <vector>

using namespace std;

/*
I have to make 2 function
first to check if every single number is not 0 and if not then --- +1
then i will check if the number can be grouped by two digits for this - pseudo code will be (n=index)
--check if first digit is 0then skip this iteratin by i++;
if (n<=9){
    (n+1<=6) -> then they can be grouped if they are then i+=2;
    else n can be taken as and one digit and the i++;
}


*/

class Solution
{

public:
    int numDecodings(string s)
    {
        vector<int> dp(s.length() + 1, -1);
            ///////////////////////////////////////////////////

        dp[s.length()] = 1;
        if (s[s.length() - 1] == '0')
        {
            dp[s.length() - 1] = 0;
        }
        else
        {
            dp[s.length() - 1] = 1;
        }
            ///////////////////////////////////////////////////

        for (int i = s.length() - 2; i >= 0; i--)
        {
            //226    i=1
            if (s[i] == '0')
            {
                dp[i] = 0;
            }
            else if (s[i] < '2')
            {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else if (s[i] == '2' && s[i + 1] <= '6')
            {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else
            {
                dp[i] = dp[i + 1];
            }
        }

    ///////////////////////////////////////////////////

        for (auto it : dp)
        {
            cout << it << " ";
        }
            ///////////////////////////////////////////////////

        cout << endl;
        return dp[0];
    }
};

int main()
{
    string s = "226";
    Solution q;
    q.numDecodings(s);
    return 0;
}