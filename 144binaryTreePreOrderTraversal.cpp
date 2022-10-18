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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }
};

int main()
{
    TreeNode *empty;
    TreeNode *root=new TreeNode(1);
    TreeNode *p1=new TreeNode(2);
    TreeNode *p2=new TreeNode(3);
    TreeNode *p3=new TreeNode(4);
    TreeNode *p4=new TreeNode(5);
    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;

    TreeNode *p5=new TreeNode(6);
    TreeNode *p6=new TreeNode(7);
    p2->left=p5;
    p2->right=p6;



    vector<int> res;
    Solution s;
    res=s.preorderTraversal(root);
    for(auto i:res){
        cout<<i<<" ";
    }
    
    return 0;
}
