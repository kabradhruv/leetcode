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

struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *p, *q;
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }

    q = head;

    while (q != NULL)
    {
        if (q->val == val)
        {
            p->next = q->next;
        }
        else
        {
            p = q;
        }
        q = q->next;
    }
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

    // link second and third
    second->val = 2;
    second->next = third;

    // link third and NULL
    third->val = 2;
    third->next = fourth;

    // link third and NULL
    fourth->val = 3;
    fourth->next = fifth;

    // link third and NULL
    fifth->val = 4;
    fifth->next = NULL;

    int v = 2;

    // printf("Before Traversal - ");
    // Traversal(head);
    // printf("\n");
    head = removeElements(head, v);
    printf("After Traversal - ");
    Traversal(head);

    return 0;
}