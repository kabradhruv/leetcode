#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
1st I have briefed the two approaches
2nd code for two approaches
3rd in main function there are two tree both are for testing so while using one comment the other one
*/


/*
Approch one is that when i make a vector from pre order traversal of root-> left say its called p1
And when i make vector from Post order traversal of root-> right say its called p2
and reverse p2
then p1==p2
*/

/*
Approch Two
we recursively call the oppsoite direction roots and return by checking if their value is true or not
This approach is better and efficient then approach one
*/

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

// Approach one
/*
class Solution
{
public:
    vector<int> preOne;
    vector<int> postTwo;
    void preorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            preOne.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        else
        {
            preOne.push_back(0);
        }
    }

    void postorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            postTwo.push_back(root->val);
        }
        else
        {
            postTwo.push_back(0);
        }
    }

    bool isSymmetric(TreeNode *root)
    {
        preorderTraversal(root->left);
        postorderTraversal(root->right);

        reverse(postTwo.begin(), postTwo.end());
        // cout << endl
        //      << "Preone" << endl;
        // for (auto i : preOne)
        // {
        //     cout << i << " ";
        // }
        // cout << endl
        //      << "PostTwo" << endl;
        // for (auto i : postTwo)
        // {
        //     cout << i << " ";
        // }
        return (preOne == postTwo);
    }
};
*/

class Solution
{
public:
    bool checkTree(TreeNode *p1, TreeNode *p2)
    {
        if (p1 != nullptr && p2 != nullptr)
        {
            cout<<p1->val<<" - "<<p2->val<<endl;;
            return p1->val == p2->val && (checkTree(p1->left, p2->right)) && (checkTree(p1->right, p2->left));
        }
        else if((p1!=nullptr && p2==nullptr) || (p1==nullptr && p2!=nullptr)){
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        return checkTree(root->left, root->right);
    }
};

int main()
{
    // trial one 
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(3);
    p2->left = p5;
    p2->right = p6;
    
    // new tree for trial two
    // TreeNode *root = new TreeNode(1);
    // TreeNode *p1 = new TreeNode(2);
    // TreeNode *p2 = new TreeNode(2);
    // TreeNode *p4 = new TreeNode(3);
    // root->left = p1;
    // root->right = p2;
    // p1->right = p4;
    // TreeNode *p6 = new TreeNode(3);
    // p2->right = p6;

    Solution s;
    cout << s.isSymmetric(root);
    return 0;
}