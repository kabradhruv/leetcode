#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int max, ind = 0, k = 0,i,j;
        vector<string> res(score.size(),"x");
        vector<string> words{"Gold Medal", "Silver Medal", "Bronze Medal"};

        for (i = 0; i < score.size(); i++)
        {
            max = 0;
            for (j = 0; j < score.size(); j++)
            {
                if (score.at(j) >= max)
                {
                    max = score.at(j);
                    ind = j;
                }
            }
            // cout<<max<<" and ind = "<<ind<<endl;
            // cout<<"break"<<endl;
            score.at(ind) = INT_MIN;
            // score.erase(score.begin() + ind);
            if (k <= 2)
            {
                res.at(ind) = words.at(k);
                k++;
            }
            else{
                // cout<<ind<<" and k = "<<k+1<<endl;
                res.at(ind) = to_string(k+1);
                k++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> score{5,4,3,2,1};
    // vector<int> score{10,3,8,9,4};
    // vector<int> score{123123,11921,1,0,123};
    vector<string> res=s.findRelativeRanks(score);

    for(auto i:res){
        cout<<i<<endl;
    }

    return 0;
}