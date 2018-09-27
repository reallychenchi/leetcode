#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PT printf
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/3sum/
void swap(int *l, int *r){
    if (l == r) return;
    int t = *l;
    *l = *r;
    *r = t;
}

void sort(int *nums, int s, int e){
    if (e - s <= 1) return;

    int *pv = nums + (s + e) / 2;
    int v = *pv;
    swap(nums + e - 1, pv);

    int idx = s;
    int *ps = nums + s;
    int *pe = nums + e - 2;
    while(ps < pe){
        if (*ps >= v){
            ps++;
            idx++;
            continue;
        }
        if (*pe < v){
            pe--;
            continue;
        }
        swap(ps, pe);
    }
    if (nums[e - 1] > nums[idx]){
        swap(nums + e - 1, nums + idx);
    }else{
        idx = e - 1;
    }
    sort(nums, s, idx);
    sort(nums, idx + 1, e);
}

int search(int *nums, int s, int e, int k){
    if (s >= e){
        return -1;
    }
    int m = (s + e) / 2;
    if (k > nums[m]){
        return search(nums, s, (s + e) / 2 - 1, k);
    }else if (k == nums[m]){
        return m;
    }else{
        return search(nums, (s + e) / 2 + 1, e, k);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int ** ret = malloc(numsSize * numsSize * sizeof(int *));
    *returnSize = 0;
    sort(nums, 0, numsSize);    
    for(int i = 0; i < numsSize / 2; ++i){
        int r1 = nums[i];
        int r2 = 0;
        int r3 = 0;
        for(int j = numsSize - 1; j >= numsSize / 2; --j){
            r2 = nums[j];
            r3 = 0 - r2 - r1;
            int r3Idx = search(nums, i + 1, j, r3);
            if (r3Idx != -1){
                ret[*returnSize] = malloc(3 * sizeof(int));
                ret[*returnSize][0] = r1;
                ret[*returnSize][1] = r2;
                ret[*returnSize][2] = r3;
                *returnSize = *returnSize + 1;
            }
        }
    }
    return ret;
}

void checkResult(int * a, int sz){
    int rsz;
    int ** r = threeSum(a, sz, &rsz);
    PT("CHECK\n");
    for(int i = 0; i < rsz; ++i){
        PT("Result %d, %d, %d\n", r[i][0], r[i][1], r[i][2]);
    }
}

int main(){
    int a[] = {1, 3, 5, -1, 5, 7, -3, -2, 0, 98, -33};
	checkResult(a, 11);
    int b[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
	checkResult(b, 16);
    int c[] = {-1, 0, 1, 2, -1, -4};
	checkResult(c, 6);
    return 0;
}