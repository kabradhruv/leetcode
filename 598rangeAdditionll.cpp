#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     int maxCount(int m, int n, vector<vector<int>> &ops)
//     {
//         // if ops is empty then return m*n
//         cout << ops.size() << endl;
//         if (ops.size() == 0)
//         {
//             return (m * n);
//         }

//         int final = 0;
//         // intializing empty vector
//         vector<vector<int>> res(
//             m,             // ROW_COUNT
//             vector<int>(n) // COLUMN_COUNT
//         );

//         // iterating ops
//         for (int i = 0; i < ops.size(); i++)
//         {
//             // incrementing the parts
//             // cout<<" m = "<<m<<", at 0 = "<<ops.at(i).at(0)<<" and at 1 = "<<ops.at(i).at(1)<<endl;
//             for (int j = 0; j < ops.at(i).at(0); j++)
//             {
//                 for (int k = 0; k < ops.at(i).at(1); k++)
//                 {
//                     // cout<<"j = "<< j <<" and k = "<<k;
//                     res.at(j).at(k) += 1;
//                     // cout<<" Complete"<<endl;
//                 }
//             }
//         }
//         // Checking how many times the greatest number (res.at(0).at(0) is occuring)
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (res.at(i).at(j) == res.at(0).at(0))
//                 {
//                     final++;
//                 }
//             }
//         }

//         // cout<<"Check"<<endl;
//         // for (int i = 0; i < m; i++)
//         // {
//         //     for (int j = 0; j < n; j++)
//         //     {
//         //         cout << res[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }

//         //
//         return final;
//     }
// };
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        // if ops is empty then return m*n
        // cout << ops.size() << endl;
        if (ops.size() == 0)
        {
            return (m * n);
        }

        int final = 0;
        // intializing empty vector
        vector<int> res(m * n);

        // iterating ops
        for (int i = 0; i < ops.size(); i++)
        {
            // incrementing the parts
            // cout<<" m = "<<m<<", at 0 = "<<ops.at(i).at(0)<<" and at 1 = "<<ops.at(i).at(1)<<endl;
            final = (ops.at(i).at(0)) * (ops.at(i).at(1));
            for (int j = 0; j < final; j++)
            {
                // cout<<"j = "<< j <<" and k = "<<k;
                res.at(j) += 1;
                // cout<<" Complete"<<endl;
            }
        }
        // Checking how many times the greatest number (res.at(0).at(0) is occuring)
        final = 0;
        for (int i = 0; i < res.size(); i++)
        {
            if (res.at(i) == res.at(0))
            {
                final++;
            }
        }

        // cout<<"Check"<<endl;
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << res[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        //
        return final;
    }
};

int main()
{
    int m = 3, n = 3;
    // vector<vector<int>> ve{
    //     {2,2},
    //     {3,3}
    // };
    // int m = 40000, n = 40000;
    // vector<vector<int>> ve{};
    vector<vector<int>> ve{
        {2,2},
        {3,3},
        {3,3},
        {3,3},
        {2,2},
        {3,3},
        {3,3},
        {3,3},
        {2,2},
        {3,3},
        {3,3},
        {3,3},
    };

    Solution s;
    cout << s.maxCount(m, n, ve);
    return 0;
}