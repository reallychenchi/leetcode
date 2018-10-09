#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
#define PT printf

//https://leetcode.com/problems/merge-k-sorted-lists
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* getMinNode(struct ListNode** l1, int listsSize) {
    struct ListNode * ret = NULL;
    int idx = -1;
    for(int i = 0; i < listsSize; ++i){
        struct ListNode *ln = l1[i];
        if (NULL == ln) continue;
        if (NULL == ret || ln->val < ret->val){
            ret = ln;
            idx = i;
        }
    }
    if (ret != NULL) l1[idx] = l1[idx]->next;

    return ret;
}

struct ListNode* mergeKLists1(struct ListNode** lists, int listsSize) {
    struct ListNode *ret = NULL;
    struct ListNode *p = getMinNode(lists, listsSize);
    while(p != NULL){
        if (NULL == ret){
            ret = p;
        }else{
            struct ListNode *l = getMinNode(lists, listsSize);
            p->next = l;
            p = l;
        }
    }
    return ret;   
}

void swap(struct ListNode** l, int a, int b){
    struct ListNode *t = l[a];
    l[a] = l[b];
    l[b] = t;
}

//e is inclueded
void sort(struct ListNode** l, int s, int e) {
    if (s >= e) return;

    int m = (s + e) / 2;
    int v = l[m]->val;
    swap(l, m, e);
    int sIdx = s; 
    int eIdx = e - 1;
    while(sIdx < eIdx){
        if (l[sIdx]->val <= v)
        {
            sIdx++;
            continue;
        }
        if (l[eIdx]->val > v)
        {
            eIdx--;
            continue;
        }
        swap(l, sIdx, eIdx);
    }
    if (l[e]->val < l[sIdx]->val){
        swap(l, sIdx, e);
    }else{
        sIdx = e;
    }
    sort(l, s, sIdx - 1);
    sort(l, sIdx + 1, e);
}

int searchNear(struct ListNode **l, int s, int e, int k){
    int end = e;
    while(s < e){
        int m = (s + e) / 2;
        if (k > l[m]->val){
            s = m + 1;
        }else if (k == l[m]->val){
            return m;
        }else{
            e = m - 1;
        }
    }
    while(l[s]->val < k && s < e){
        s++;
    }

    return s;
}

struct ListNode* getMinNodeSort(struct ListNode** l, int * listsSize) {
    if (*listsSize == 0) return NULL;
    struct ListNode * ret = l[0];
    if (ret != NULL) l[0] = l[0]->next;
    else return ret;
    int j = 0;
    if (l[0] == NULL) {
        for(int i = 1; i < *listsSize && l[i] != NULL; ++i){
            swap(l, j, i);
            j = i;
        }
        *listsSize = *listsSize - 1;
    }else{
        for(int i = 1; i < *listsSize && l[i] != NULL; ++i){
            if (l[j]->val > l[i]->val){
                swap(l, j, i);
                j = i;
            }
        }
    }
    return ret;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int storeIdx = listsSize - 1;
    int nullIdx = 0;
    while(lists[storeIdx] == NULL && storeIdx >= 0){
        storeIdx--;
    }
    if (-1 == storeIdx) return NULL;

    for(int i = 0; i < listsSize && storeIdx > i; ++i){
        if (lists[i] == NULL){
            swap(lists, i, storeIdx);
            while (lists[storeIdx] == NULL && storeIdx > 0){
                storeIdx--;
            }
        }
    }
    listsSize = storeIdx + 1;
    sort(lists, 0, listsSize - 1);
    struct ListNode * ret = getMinNodeSort(lists, &listsSize);
    struct ListNode * p = ret;
    while(p != NULL){
        struct ListNode *l = getMinNodeSort(lists, &listsSize);
        p->next = l;
        p = l;
    }

    return ret;
}

//[[-7,-7,-6,-4,-4,1,1],[-10,-9,-8,-7,-7,-5,-2,2],[-10,3],[-5,-4,-4,-4,-1,-1,4],[-10,-5,-3,-1,1,2],[-10,-9,-5,-4,-3,-1,-1],[],[],[]]
int main(){
    struct ListNode **l = malloc(sizeof(struct ListNode *) * 50);
    srand(300);
    for(int i = 0; i < 50; ++i){
        l[i] = malloc(sizeof(struct ListNode));
        l[i]->val = rand() % 20;
        l[i]->next = NULL;
    }
    sort(l, 0, 49);
    for(int i = 0; i < 50; ++i){
        PT("%d(%d), ", l[i]->val, i);
    }
    PT("\n%d\n", searchNear(l, 0, 49, 15));
    struct ListNode * r = mergeKLists(l, 50);
    while(r != NULL){
        PT("%d, ", r->val);
        r = r->next;
    }
    PT(" *\n");
    l[0] = malloc(sizeof(struct ListNode) * 3);
    l[1] = malloc(sizeof(struct ListNode) * 3);
    l[4] = malloc(sizeof(struct ListNode) * 2);
    l[0][0].val = 1;
    l[0][0].next = l[0] + 1;
    l[0][1].val = 4;
    l[0][1].next = l[0] + 2;
    l[0][2].val = 5;
    l[0][2].next = NULL;
    l[0] = NULL;
    l[1][0].val = 1;
    l[1][0].next = NULL;
    l[1][1].val = 3;
    l[1][1].next = l[1] + 2;
    l[1][2].val = 4;
    l[1][2].next = NULL;
    l[4][0].val = 3;
    l[4][0].next = l[4] + 1;
    l[4][1].val = 6;
    l[4][1].next = NULL;
    l[2] = NULL;
    l[3] = NULL;
    /*
    r = mergeKLists(l, 5);
    while(r != NULL){
        PT("%d, ", r->val);
        r = r->next;
    }
    PT("*\n");
    */
    return 0;
}