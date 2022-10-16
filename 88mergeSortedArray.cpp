#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i=m-1 , j=n-1 , k=m+n-1;
        while (i>=0 && j>=0){
            if (nums1[i] > nums2[j])
            {
                nums1[k--]=nums1[i--];
            }else
            {
                nums1[k--]=nums2[j--];
            }
        }
        while(i>=0){
            nums1[k--] = nums1[i--];
            }
        while(j>=0){
            nums1[k--] = nums2[j--];
            }
    }
};


int main()
{
    vector<int> arr1{1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> arr2{2, 5, 6};
    int n = 3;
    Solution s;
    s.merge(arr1, m, arr2, n);
    // vector<int>::iterator iter = arr1.begin();
    // arr1.pop_back();
    // arr1.insert(iter,1,12);
    // arr1.pop_back();
    // arr1.insert(iter,1,12);
    // arr1.pop_back();
    // arr1.insert(iter,1,12);
    // // arr1.insert(iter+1,1,13);
    // for (int i = 0; i < arr1.size(); i++)
    // {
    //     cout << arr1[i] << " ";
    // }

    return 0;
}