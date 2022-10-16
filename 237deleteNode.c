#include <stdio.h>
#include<stdlib.h>

/*
We are given a node ehich is to be deleted there is no previous node 
given node is not the last node that is for sure
to do this what I will do is say the given node is s1 and the next is s2,s3
1. i will put the value of s2 in s1 and pointe s1-> next to s3
so in reallity s2 is removed but the data for s2 is remained
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

void Traversal(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}

void deleteNode(struct ListNode* node) {
   node->val=node->next->val; 
   node->next=node->next->next; 
}

int main()
{
     // to making pointers for strcuture
    struct ListNode *head;
    struct ListNode *second;
    struct ListNode *third;
    struct ListNode *fourth;
    struct ListNode *fifth;

    // allocate memory  for ListNodes in the the heap
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    second = (struct ListNode *)malloc(sizeof(struct ListNode));
    third = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth = (struct ListNode *)malloc(sizeof(struct ListNode));
    fifth = (struct ListNode *)malloc(sizeof(struct ListNode));

    // link first and second
    head->val = 1;
    head->next = second;

    // link second and third
    second->val = 2;
    second->next = third;

    // link third and NULL
    third->val = 3;
    third->next = fourth;

    // link third and NULL
    fourth->val = 4;
    fourth->next = fifth;

    // link third and NULL
    fifth->val = 5;
    fifth->next = NULL;

    printf("Before Traversal - ");
    Traversal(head);
    printf("\n");
    deleteNode(fourth);
    printf("After Traversal - ");
    Traversal(head);

 return 0;
}