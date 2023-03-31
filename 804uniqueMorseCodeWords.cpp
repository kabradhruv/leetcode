#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*
    Steps :
        1. Initialise the morse code vector
        2. Make a functin which takes a word and return the morse code
        3. Use that function to make an string vector of morse code associating to the words
        4. make a function which takes string vector of morse code as input and return the unique ones
    */

    string wordToMorse(string n)
    {
        vector<string> morseCode = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        string temp = "";

        for (int i = 0; i < n.length(); i++)
        {
            temp += morseCode.at(n.at(i) - 97);
        }
        return temp;
    }

    int uniqueCode(vector<string> &m)
    {
        vector<string>::iterator it;
        sort(m.begin(), m.end());
        it = unique(m.begin(), m.end());
        return (it - m.begin());
    }

    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> inMorse;
        for (int i = 0; i < words.size(); i++)
        {
            inMorse.push_back(wordToMorse(words.at(i)));
        }

        return uniqueCode(inMorse);
    }
};

int main()
{
    Solution s;
    // vector<string> words {"gin","zen","gig","msg"};
    vector<string> words{"zocd", "gjkl", "hzqk", "hzgq", "gjkl"};
    cout << s.uniqueMorseRepresentations(words);
    return 0;
}