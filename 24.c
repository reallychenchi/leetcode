#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
#define PT printf

//https://leetcode.com/problems/swap-nodes-in-pairs/
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode *ret = head;
    struct ListNode *p = NULL;
    struct ListNode *s1 = head;
    while (NULL != s1)
    {
        struct ListNode *s2 = s1->next;
        if (s2 == NULL)
        {
            break;
        }
        struct ListNode *n = s2->next;
        s1->next = n;
        s2->next = s1;
        if (NULL != p)
        {
            p->next = s2;
        }
        else
        {
            ret = s2;
        }
        p = s1;
        s1 = n;
    }

    return ret;
}

int main()
{
    struct ListNode *h = NULL;
    struct ListNode *p = h;
    struct ListNode *q = h;
    for (int i = 0; i < 1; ++i)
    {
        p = malloc(sizeof(struct ListNode));
        p->val = i;
        p->next = NULL;
        if (NULL == h) h = p;
        if (NULL != q)
        {
            q->next = p;
        }
        q = p;
    }

    p = h;
    while (p != NULL)
    {
        PT("%d, ", p->val);
        p = p->next;
    }
    PT("\n");
    h = NULL;
    h = swapPairs(h);

    p = h;
    while (p != NULL)
    {
        PT("%d, ", p->val);
        p = p->next;
    }
    PT("\n");
    return 0;
}