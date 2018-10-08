#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
#define PT printf

//https://leetcode.com/problems/merge-two-sorted-lists/
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ret = NULL;
    struct ListNode *p = NULL;
    while(NULL != l1 || NULL != l2){
        struct ListNode *l = NULL;
        if (NULL == l1) {
            l = l2;
            l2 = l2->next;
        }else if (NULL == l2){
            l = l1;
            l1 = l1->next;
        }else if (l1->val > l2->val) {
            l = l2;
            l2 = l2->next;
        }else{
            l = l1;
            l1 = l1->next;
        }
        if (NULL == ret){
            ret = l;
            p = l;
        }else{
            p->next = l;
            p = l;
        }
    }
    return ret;   
}

int main(){
    return 0;
}