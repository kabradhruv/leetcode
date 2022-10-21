#include <iostream>
#include <vector>
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // to check if one is null or not
        if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr)){return false;}

        if (p != nullptr && q != nullptr)
        {
            if(p->val != q->val){return false;}
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }

        return true;
    }
};

int main()
{
    TreeNode *empty;
    TreeNode *empty1;

    // 1st list
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(5);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    // 2nd list
    TreeNode *root1 = new TreeNode(1);
    TreeNode *r1 = new TreeNode(2);
    TreeNode *r2 = new TreeNode(3);
    TreeNode *r3 = new TreeNode(4);
    TreeNode *r4 = new TreeNode(5);
    root1->left = r1;
    root1->right = r2;
    r1->left = r3;
    r1->right = r4;

    Solution s;
    cout << s.isSameTree(root, root1);

    return 0;
}
