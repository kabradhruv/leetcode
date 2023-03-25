#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for (int i = 0; i < moves.length(); i++)
        {
            switch (moves.at(i))
            {
            case 'U':
                x++;
                break;
            case 'D':
                x--;
                break;
            case 'L':
                y++;
                break;
            case 'R':
                y--;
                break;
            }
        }
        return (x==0 && y==0);
    }
};


int main(){
    Solution s;
    string moves="UDLR";
    cout<<s.judgeCircle(moves);
    return 0;
}