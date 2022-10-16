#include <iostream>
using namespace std;

// Definition for singly-linked list structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//making the traversal function
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
//making the insertion function where we will need a pointer to where insert the next
ListNode *insertNext(ListNode *ptr, int value)
{
    ListNode *lnew = new ListNode(value);
    ptr->next = lnew;
    return lnew;
}

class Solution
{
public:
    void insertLast(ListNode *ptr, int value)
    {
        ListNode *lnew = new ListNode(value);
        ListNode *copy = ptr;
        while (copy->next != nullptr)
        {
            copy = copy->next;
        }
        copy->next = lnew;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        int carry = 0;
        int sum = 0;

        if (l1 == nullptr && l2 == nullptr)
            return (res = res->next);

        // when both have values
        while (l1 != nullptr && l2 != nullptr)
        {
            if ((l1->val + l2->val + carry) > 9)
            {
                sum = ((l1->val + l2->val + carry) % 10);
                carry = 1;
            }
            else
            {
                sum = (l1->val + l2->val + carry);
                carry = 0;
            }
            insertLast(res, sum);
            // incrementing
            l1 = l1->next;
            l2 = l2->next;
        }

        // when only one have the values left
        // 1. for l1
        while (l1 != nullptr)
        {
            if ((l1->val + carry) > 9)
            {
                insertLast(res, ((l1->val + carry) % 10));
                carry = 1;
            }
            else
            {
                insertLast(res, (l1->val + carry));
                carry = 0;
            }
            l1 = l1->next;
        }
        // 1. for l2
        while (l2 != nullptr)
        {
            if ((l2->val + carry) > 9)
            {
                insertLast(res, ((l2->val + carry) % 10));
                carry = 1;
            }
            else
            {
                insertLast(res, (l2->val + carry));
                carry = 0;
            }
            l2 = l2->next;
        }
        // if carry is still there then we will add it to the last
        if (carry)
        {
            insertLast(res, 1);
        }
        return res->next;
    }
};


int main()
{
    // first linked list
    ListNode *head = new ListNode(9);
    ListNode *l2 = insertNext(head, 9);
    // ListNode *l3 = insertNext(l2, 3);
    // ListNode *l4 = insertNext(l3, 6);
    // ListNode *l5 = insertNext(l4, 7);
    // insertLast(head, 8);
    // insertLast(head, 9);

    // second linked list
    ListNode *head1 = new ListNode(9);
    ListNode *r2 = insertNext(head1, 9);
    ListNode *r3 = insertNext(r2, 9);
    ListNode *r4 = insertNext(r3, 9);
    // ListNode *r7 = insertNext(r4, 7);

    // ListNode *headxx=new ListNode();
    // ListNode *head1xx=new ListNode();
    Solution s;
    // ListNode *res = s.addTwoNumbers(headxx, head1xx);
    ListNode *res = s.addTwoNumbers(head, head1);
    traverse(res);
    return 0;
}