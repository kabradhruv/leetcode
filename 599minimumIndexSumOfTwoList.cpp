#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        vector<pair<int,int>> choices;
        int min=INT_MAX,ind=0;
        vector<string> :: iterator it;

        // from this loop i get all the index of the same string ans save them in vector choices
        // and I also got the minimum index which is there
        for (int i = 0; i < list1.size(); i++)
        {
            //finding the element in list2
            it = find(list2.begin(),list2.end(),list1.at(i));
            if (it!=list2.end())
            {
                ind = it - list2.begin();
                if (ind+i < min)
                {
                    min = ind+i;
                }
                choices.push_back(make_pair(i,ind));
            }
        }

        //To insert the string into res whose sum is equal to min
        for (int i = 0; i < choices.size(); i++)
        {
            if (choices.at(i).first + choices.at(i).second == min)
            {
                res.push_back(list1.at(choices.at(i).first));
            }
        }
        return res;
    }
};


int main(){
    Solution s;
    // vector<string> list1{"Shogun","Tapioca Express","Burger King","KFC"};
    // vector<string> list2{"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    vector<string> list1{"happy","sad","good"};
    vector<string> list2{"sad","happy","good"};
    vector<string> res;
    res=s.findRestaurant(list1,list2);

    for(auto i:res){
    cout<<i<<endl;
    }
    return 0;
}