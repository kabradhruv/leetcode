#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void traverse(ListNode *head)
{
    ListNode *p = head;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

bool check(vector<int> &v,int start,int end){
    if (start>=end)
    {
        return true;
    }
    
    return ((v[start]==v[end]) && check(v,start+1,end-1));
}

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // if headd is null
        if ((head == nullptr))
        {
            return false;
        }

        // making a vector
        vector<int> ip;
        while (head != nullptr)
        {
            ip.push_back(head->val);
            head = head->next;
        } 
        return check(ip,0,ip.size()-1);
    }
};

// 2nd approach from leet code 
/*
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};
*/

int main()
{
    ListNode *head = new ListNode(1);

    ListNode *l2 = new ListNode(2);
    head->next = l2;

    ListNode *l3 = new ListNode(3);
    l2->next = l3;

    ListNode *l4 = new ListNode(2);
    l3->next = l4;

    ListNode *l5 = new ListNode(1);
    l4->next = l5;

    traverse(head);
    Solution s;
    cout<<s.isPalindrome(head);
    // traverse(head);
    return 0;
}