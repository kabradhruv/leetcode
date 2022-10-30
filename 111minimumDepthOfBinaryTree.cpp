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
    int minDepth(TreeNode *root)
    {

        if (root == nullptr)
        {
            return 0;
        }
        if ((root->left == nullptr) && (root->right == nullptr))
        {
            return 1;
        }
        int minDepthOfTree = 0;
        int minDepthOfLeft = minDepth(root->left);
        int minDepthOfRight = minDepth(root->right);
        if ((root->left != nullptr) && (root->right != nullptr))
        {
        return min(minDepthOfLeft, minDepthOfRight)+1;
        }
        
        // minDepthOfTree = min(minDepthOfLeft, minDepthOfRight)+1;
        return minDepthOfLeft!=0?minDepthOfLeft+1:minDepthOfRight+1;
    }
};

int main()
{
    // trial one
    // TreeNode *root = new TreeNode(1);
    // TreeNode *p1 = new TreeNode(2);
    // TreeNode *p2 = new TreeNode(2);
    // TreeNode *p3 = new TreeNode(3);
    // TreeNode *p4 = new TreeNode(4);
    // root->left = p1;
    // root->right = p2;
    // p1->left = p3;
    // p1->right = p4;
    // TreeNode *p5 = new TreeNode(4);
    // TreeNode *p6 = new TreeNode(3);
    // p2->left = p5;
    // p2->right = p6;

    // new tree for trial two
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(3);
    root->left = p1;
    root->right = p2;
    p1->right = p4;
    TreeNode *p6 = new TreeNode(3);
    TreeNode *p7 = new TreeNode(3);
    TreeNode *p8 = new TreeNode(3);
    p2->right = p6;
    p4->left = p7;
    p7->left = p8;

    Solution s;
    cout << s.minDepth(root);
    return 0;
}