#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:

    string checkStr(string s,int c){
        char temp;

        if (s.at(0) == 'a' || s.at(0) == 'e' || s.at(0) == 'i' || s.at(0) == 'o' || s.at(0) == 'u' || s.at(0) == 'A' || s.at(0) == 'E' || s.at(0) == 'I' || s.at(0) == 'O' || s.at(0) == 'U')
        {
            // if first letter is vowel 
            s.push_back('m');
            s.push_back('a');
        }
        else
        {
            // if first character is consonant 
            temp = s.at(0);
            s.erase(s.begin());
            s.push_back(temp);
            s.push_back('m');
            s.push_back('a');
        }
        for (int i = 0; i < c; i++)
        {
            s.push_back('a');
        }
        return s;
    }

    string toGoatLatin(string sentence)
    {
        /*
        i = is index
        start = is the index starting character and end is the length of the word
        acount = is the number if word to put 'a' in the end
        */
        int i=0 , start = 0, len=0 , acount=0;
        string temp;

        while (i < sentence.length() - 1)
        {        
            // we are checking 2 condition
            // 1. is i+1 is space and i is not meaning a word completion
            // 2. i+2 -- sentence length means last word
            if ((sentence.at(i + 1) == ' ' && sentence.at(i) != ' ') || (i + 2 == sentence.length()))
            {
                acount++;

                // is last word then i+2-start else i+1-start
                len = i + 2 == sentence.length()?(i + 2)-start:(i + 1)-start;

                temp = sentence.substr(start, len);
                sentence.replace(start,len,checkStr(temp,acount));

                // we are making a new start by adding len of the word + 3 = 2 for 'ma' 
                // and 1 because len is not complete and also acount for the number of 'a'
                start = start + len + 3 + acount ;

                // and we are also incrementing i because when we replace the word with 
                // the new word it will again point at new word ending
                i+=acount+2;
            }
            i++;
        }
        return sentence;
    }
};

int main()
{
    // string sentence = "I speak Goat Latin";
    string sentence = "The quick brown fox jumped over the lazy dog";
    Solution s;
    sentence = s.toGoatLatin(sentence);

    cout<<sentence<<endl;
    return 0;
}