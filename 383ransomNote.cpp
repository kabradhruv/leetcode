#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // declaration 
        vector<int> mag(26,0);

        //adding the values from magazine string to mag vector
        for (int i = 0; i < magazine.length(); i++)
        {
            mag.at(magazine.at(i) - 97)++;
        }

        //checking that ransomeNote string can be made from mag vector which was previously constructed from magazine
        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (mag.at(ransomNote.at(i) - 97) == 0)
            {
                return false;
            }
            else{
                mag.at(ransomNote.at(i) - 97)--;
            }
        }
        return true;
    }
};


int main(){
    string ransomNote = "a", magazine = "b";
    // string ransomNote = "aa", magazine = "aab";

    Solution s;
    cout<<s.canConstruct(ransomNote,magazine);
    return 0;
}