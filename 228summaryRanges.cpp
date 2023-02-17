#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        vector<string> res;
        string temp = ""; // temproray string
        
        for(int i = 0; i < arr.size(); i++) // start traversing from the array
        {
            int j = i;
            temp = "";
            while(j + 1 < arr.size() && arr[j + 1] == arr[j] + 1)
            {
                j++;
            }

            if(j > i)
            {
                temp += to_string(arr[i]); 
                temp += "->";
                temp += to_string(arr[j]);
            }
            else
            {
                temp += to_string(arr[i]);
            }
            res.push_back(temp);
            i = j;
        }
        
        return res; 
    }
};

int main()
{
    Solution s;
    // vector<int> x{0, 1, 2, 4, 5, 7};
    vector<int> x{0,2,3,4,6,8,9};
    vector<string> res = s.summaryRanges(x);
    for (auto i : res)
    {
        cout << i << endl;
    }

    return 0;
}