#include<iostream>
#include<set>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
void traverse(ListNode *head){
    ListNode *p=head;
    while (p!=nullptr)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

// my approach 
/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<string> us;

        // making an set for head A
        ListNode *p=headA;
        while (p!=nullptr)
        {
            ListNode *q=headB;
            while (q!=nullptr)
            {
                if (p->val==q->val)
                {
                    if (p==q)
                    {
                        return p;
                    }
                }
                
                q=q->next;
            }
            p=p->next;
        }
        return NULL;
    }
};
*/

// leetcode solution approach 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }
        return a;
    }
};

int main(){
    ListNode *head=new ListNode(1);
    ListNode *l2=new ListNode(2);
    head->next=l2;
    ListNode *l3=new ListNode(3);
    l2->next=l3;
    ListNode *l4=new ListNode(4);
    l3->next=l4;
    ListNode *l5=new ListNode(5);
    l4->next=l5;

    ListNode *head2=new ListNode(8);
    ListNode *h1=new ListNode(7);
    head2->next=h1;
    ListNode *h2=new ListNode(6);
    h1->next=h2;
    ListNode *h3=l3;
    h2->next=h3;
    ListNode *h4=l4;
    h3->next=h4;
    ListNode *h5=l5;
    h4->next=h5;

    // traverse(head);
    // traverse(head2);

    Solution s;
    ListNode *res;
    res=s.getIntersectionNode(head,head2);
    cout<<res->val<<endl;

    
    return 0;
}