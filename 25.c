#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
#define PT printf

//https://leetcode.com/problems/reverse-nodes-in-k-group/
struct ListNode
{
    int val;
    struct ListNode *next;
};

void reverseGroup(struct ListNode*s, struct ListNode* e)
{
    struct ListNode *i = s;
    struct ListNode *p = NULL;
    while(i != e)
    {
        struct ListNode *n = i->next;
        i->next = p;
        p = i;
        i = n;
    }
    e->next = p;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
    struct ListNode *ret = head;
    struct ListNode *p = NULL;
    struct ListNode *s = head;
    struct ListNode *e = head;
    int swap = k;
    while (NULL != e)
    {
        if (swap == 1)
        {
            swap = k;
            //Revert
            struct ListNode *n = e->next;
            reverseGroup(s, e);
            if (NULL == p){
                ret = e;
            }else{
                p->next = e;
            }
            s->next = n;
            p = s;
            s = p->next;
            e = p->next;
        }
        else
        {
            swap--;
            e = e->next;
        }
    }

    return ret;
}

int main()
{
    struct ListNode *h = NULL;
    struct ListNode *p = h;
    struct ListNode *q = h;
    for (int i = 0; i < 10; ++i)
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
    h = reverseKGroup(h, 1);

    p = h;
    while (p != NULL)
    {
        PT("%d, ", p->val);
        p = p->next;
    }
    PT("\n");
    return 0;
}