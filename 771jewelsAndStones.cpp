#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int countChar(char c,string s){
        int count=0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == c)
            {
                count++;
            }
        }
        return count;
    }

    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        for (int i = 0; i < jewels.length(); i++)
        {
            count+=countChar(jewels.at(i) , stones);
        }
        return count;
    }
};


int main(){
    // string jewels = "aA", stones = "aAAbbbb";
    string jewels = "z", stones = "ZZ";
    Solution s;
    cout<<s.numJewelsInStones(jewels,stones);
    return 0;
}