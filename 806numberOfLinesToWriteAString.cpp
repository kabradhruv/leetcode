#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int nLines = 0,lpixel=0,temp=0,ch=0;
        vector<int> res(2,0);

        //for loop to iterate
        for (int i = 0; i < s.length(); i++)
        {
            ch=s.at(i)-'a';
            if (temp + widths.at(ch) > 100)
            {
                temp=0;
                nLines++;
            }
            temp+=widths.at(ch);
        }
        res.at(0)=nLines+1;
        res.at(1)=temp;
        return res;
    }
};


int main(){
    Solution s;
    vector<int> widths {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string x= "abcdefghijklmnopqrstuvwxyz";
    // vector<int> widths {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    // string x= "bbbcccdddaaa";
    vector<int> res=s.numberOfLines(widths,x);

    cout<<endl<<"Answer = "<<endl;
    for(auto i:res){
        cout<<i<<endl;
    }

    return 0;
}