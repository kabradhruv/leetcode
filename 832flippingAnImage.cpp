#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> reverseVec(vector<int> img)
    {
        vector<int> temp;
        for (int i = 0; i < img.size(); i++)
        {
            temp.push_back(img.at(i));
        }

        reverse(temp.begin(), temp.end());

        // inverting the vector
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp.at(i) == 0)
            {
                temp.at(i) = 1;
            }else
            {
                temp.at(i) = 0;
            }
        }

        return temp;
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        vector<int> temp;

        for (int i = 0; i < image.size(); i++)
        {
            // copying the vector in temp
            for (int j = 0; j < image.at(i).size(); j++)
            {
                temp.push_back(image.at(i).at(j));
            }

            temp = reverseVec(temp);

            for (int j = 0; j < image.at(i).size(); j++)
            {
                image.at(i).at(j) = temp.at(j);
            }
        }

        return image;
    }
};

int main()
{
    vector<vector<int>> image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    Solution s;
    vector<vector<int>> res = s.flipAndInvertImage(image);

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image.at(i).size(); j++)
        {
            cout << image.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}