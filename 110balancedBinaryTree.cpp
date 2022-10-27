#include <iostream>
#include <cstdlib>
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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int maxDepthOfLeft = maxDepth(root->left);
        int maxDepthOfRight = maxDepth(root->right);
        return (max(maxDepthOfLeft, maxDepthOfRight) + 1);
    }
    
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        int hl = maxDepth(root->left);
        int hr = maxDepth(root->right);
        return ((isBalanced(root->left)) && (isBalanced(root->right)) && (abs(hr-hl) > 1 ? false: true));
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
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p4 = new TreeNode(3);
    root->left = p1;
    root->right = p2;
    p1->right = p4;
    TreeNode *p6 = new TreeNode(3);
    TreeNode *p7 = new TreeNode(3);
    TreeNode *p8 = new TreeNode(3);
    p2->right = p6;
    p6->left = p7;
    p7->left = p8;

    Solution s;
    cout << s.isBalanced(root);
    return 0;
}