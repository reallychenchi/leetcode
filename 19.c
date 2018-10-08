#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
#define PT printf

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode *p = head;
    while(p != NULL){
        p = p->next;
        len++;
    }

    if (len == n) return head->next;
    p = head;
    for(int i = 0; i < len - n - 1; ++i){
        p = p->next;
    }
    struct ListNode *np = p->next;
    if (NULL != np){
        p->next = np->next;
    }else{
        p->next = NULL;
    }
    
    return head;
}

void checkResult(int * a, int sz){
}

int main(){
    return 0;
}