#include<iostream>
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
/*
1->2->3->4->5
p ,q ,r
q->next =p
p=q
q=r
r=r->next
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if headd is null 
        if (head==nullptr)
        {
            return nullptr;
        }
        

        // if list is 1 return 1 
        if (head->next==nullptr)
        {
            return head;
        }
        

        // if list is 2 then 
        // p=head->next
        // p->next=head
        // head->next=nullptr
        // return p
        if (head->next->next==nullptr)
        {
            ListNode *temp=head->next;
            head->next=nullptr;
            temp->next=head;
            return temp;
        }
        

        // if list is bigger than 3 
        ListNode *low=head;
        ListNode *mid=head->next;
        ListNode *high=head->next->next;
        low->next=nullptr;
        while (high!=nullptr)
        {
        // cout<<"check"<<endl;
            mid->next=low;
            low=mid;
            // traverse(mid);
            mid=high;
            high=high->next;
        }
        mid->next=low;
        return mid;
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

    traverse(head);
    Solution s;
    head=s.reverseList(head);
    traverse(head);

    return 0;
}