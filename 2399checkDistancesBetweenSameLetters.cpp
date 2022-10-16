#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // bool checkDistances(string s, vector<int> &distance)
    // {
    //     char c1 = 'a';
    //     for (int i = 0; i < 26; i++)
    //     {
    //         if (s[i] > c1)
    //         {
    //             c1 = s[i];
    //         }
    //     }
    //     // int c = c1- 96;
    //     // cout<<c<<endl;
    //     int i = 0;
    //     int ind = 97;
    //     int dist;
    //     while (i < s.length() && ind <= (96 + c1))
    //     {
    //             dist = distance[ind - 97];
    //         if (s[i] == ind)
    //         {
    //             if (s[i] != s[i + dist + 1])
    //             {
    //                 // cout<<dist<<endl;
    //                 // cout<<i<<endl;
    //                 return false;
    //             }
    //             ind++;
    //         }
    //         i++;
    //     }
    //     return true;
    // }

    // bool checkDistances(string s, vector<int> &distance)
    // {
    //     int n=s.length();
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i+1; j < n; j++)
    //         {
    //             if (s[i]==s[j] && s[i] != s[i+(distance[s[i]-'a']+1)])
    //             {
    //                 return false;
    //             }
                
    //         }
            
    //     }
    //     return true;
    // }
bool checkDistances(string s, vector<int>& distance) {
        int n =s.length();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(s[i]==s[j])
                    if(j-i-1 != distance[s[i]-'a']) return false;
        return true;
    }

};

int main()
{
    // string s = "abaccb";
    // vector<int> distance{1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string s = "aa";
    vector<int> distance{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Solution d;
    bool res = d.checkDistances(s, distance);
    cout << res;
    return 0;
}