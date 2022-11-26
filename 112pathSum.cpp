#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)                                                         // Terminating Condition
        {
            return false;
        }                      
        sum = sum - root->val;                                             // Body
        if (sum == 0 && !root->left && !root->right)                       // Body
        {
            return true;
        }                                                                   
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum); // Propagation
    }
};

int main()
{
    TreeNode *empty;
    TreeNode *root = new TreeNode(5);
    TreeNode *p1 = new TreeNode(4);
    TreeNode *p2 = new TreeNode(8);
    TreeNode *p3 = new TreeNode(11);
    TreeNode *p4 = new TreeNode(7);
    TreeNode *p5 = new TreeNode(2);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p3->left = p4;
    p3->right = p5;

    TreeNode *p6 = new TreeNode(13);
    TreeNode *p7 = new TreeNode(4);
    TreeNode *p8 = new TreeNode(1);
    p2->left = p6;
    p2->right = p7;
    p7->right = p8;

    int targetSum = 22;

    Solution s;
    bool res = s.hasPathSum(root, targetSum);
    cout<<res;

    return 0;
}