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

void Traversal(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    cout<<endl;
}

void insert(ListNode *head,int val){
    ListNode *ptr=head;
    ListNode *newNode = new ListNode(val);
    while (ptr->next !=nullptr){
        ptr=ptr->next;
    }
    ptr->next=newNode;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return head;
        ListNode *prev=head;
        ListNode *ptr=head->next;
        int value=head->val;
        while (ptr!=nullptr)
        {
            cout<<value<<endl;
            if (ptr->val == value)
            {
                prev->next=ptr->next;
            }
            else
            {
                prev=prev->next;
                value=ptr->val;
            }
            ptr=ptr->next;
        }
        return head;
    }
};

int main(){
    ListNode *head=new ListNode(1);
    // insert(head,2);
    // insert(head,2);
    // insert(head,3);
    // insert(head,3);
    // insert(head,3);
    // insert(head,3);
    // insert(head,4);
    // insert(head,4);
    // insert(head,4);
    // insert(head,4);
    // insert(head,5);
    Traversal(head);
    Solution s;
    head=s.deleteDuplicates(head);
    Traversal(head);
    return 0;
}