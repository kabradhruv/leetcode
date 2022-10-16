#include <stdio.h>
#include <stdlib.h>


struct ListNode
{
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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    // to get the length
    int len = 0;
    struct ListNode *p = head;
    struct ListNode *q = head->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }

    // to terminate function if len is 1
    if (len == 1)
    {
        free(head);
        return NULL;
    }

    p = head;
    // functionality to handle if n=len meaning we have to delete the first node
    if (len == n)
    {
        head = head->next;
        free(p);
        return head;
    }

    // to delete if reached till here
    len = len - n;
    for (int i = 0; i < len - 1; i++)
    {
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);

    return head;
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
    // head->next = NULL;

    // link second and third
    second->val = 2;
    second->next = third;
    // second->next = NULL;

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
    head = removeNthFromEnd(head, 2);
    printf("After Traversal - ");
    Traversal(head);

    return 0;
}