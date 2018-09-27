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

int search(int *nums, int s, int e, int k, bool findNear){
    if (s == e){
        if (nums[e] == k) return e;
        else {
            if (findNear) return e;
            else return -1;
        }
    }
    if (s >= e){
        if (findNear){
            return nums[e] > 0 ? s:e;
        }else{
            return -1;
        }
    }
    int m = (s + e) / 2;
    if (k > nums[m]){
        return search(nums, s, m - 1, k, findNear);
    }else if (k == nums[m]){
        return m;
    }else{
        return search(nums, m + 1, e, k, findNear);
    }
}

bool isExists(int *r, int** ret, int sz){
    for(int i = 0; i < sz; ++i){
        int *data = ret[i];
        int j = 0;
        for(; j < 3; ++j){
            if (r[j] != data[j]){
                break;
            }
        }
        if (j == 3) return true;
    }

    return false;
}

int** threeSum1(int* nums, int numsSize, int* returnSize) {
    int ** ret = malloc(numsSize * numsSize * sizeof(int *));
    *returnSize = 0;
    if (numsSize < 3) return ret;

    int *r = malloc(3 * sizeof(int));
    for(int i = 0; i < numsSize - 2; ++i){
        r[0] = nums[i];
        for(int j = i + 1; j < numsSize - 1; ++j){
            r[1] = nums[j];
            r[2] = 0 - r[0] - r[1];
            for(int k = j + 1; k < numsSize; ++k){
                sort(r, 0, 3);
                if (r[2] == nums[k] && !isExists(r, ret, *returnSize)){
                    ret[*returnSize] = r;
                    *returnSize = *returnSize + 1;
                    r = malloc(3 * sizeof(int));
                    r[0] = nums[i];
                    break;
                }else{
                    r[0] = nums[i];
                    r[1] = nums[j];
                    r[2] = 0 - r[0] - r[1];
                }
            }
        }
    }
    return ret;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int ** ret = malloc(numsSize * numsSize * sizeof(int *));
    *returnSize = 0;
    if (numsSize < 3) return ret;

    sort(nums, 0, numsSize);    
    int zeroIdx = search(nums, 0, numsSize, 0, true);
    if (zeroIdx < 0 || zeroIdx >= numsSize) return ret;
    int *r = malloc(3 * sizeof(int));
    for(int i = 0; i < zeroIdx; ++i){
        r[0] = nums[i];
        for(int j = numsSize - 1; j >= zeroIdx; --j){
            r[2] = nums[j];
            r[1] = 0 - r[2] - r[0];
            int r3Idx = search(nums, i + 1, j, r[1], false);
            if (r3Idx != -1 && !isExists(r, ret, *returnSize)){
                ret[*returnSize] = r;
                *returnSize = *returnSize + 1;
                r = malloc(3 * sizeof(int));
                r[0] = nums[i];
            }
        }
    }
    return ret;
}

void checkResult(int * a, int sz){
    PT("\nCHECK:\t");
    for(int i = 0; i < sz; ++i){
        PT("%d, ", a[i]);
    }
    PT("\n");

    int rsz1;
    int ** r1 = threeSum1(a, sz, &rsz1);
    int rsz = 0;
    int ** r = NULL;//threeSum(a, sz, &rsz);
    if (rsz1 != rsz){
        PT("FAILED: SZ %d, %d\n", rsz, rsz1);
        return;
    }
    for(int i = 0; i < rsz; ++i){
        if (!isExists(r[i], r1, rsz)){
            PT("FAILED: WRONG EXISTS %d, %d, %d\n", r[i][0], r[i][1], r[i][2]);
            return;
        }
    }

    for(int i = 0; i < rsz; ++i){
        if (!isExists(r1[i], r, rsz)){
            PT("FAILED: NOT FOUND %d, %d, %d\n", r1[i][0], r1[i][1], r1[i][2]);
            return;
        }
    }

    PT("PASS\n");
}

int main(){
    int a[] = {1, 3, 5, -1, 5, 7, -3, -2, 0, 98, -33};
	checkResult(a, 11);
    int b[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
	checkResult(b, 16);
    int c[] = {-1, 0, 1, 2, -1, -4};
	checkResult(c, 6);
    int d[] = {0, 0, 0};
	checkResult(d, 3);
    int e[] = {1, 0, -1};
	checkResult(e, 3);
    int f[] = {1,2,-2,-1};
	checkResult(f, 4);
    int g[] = {0, 0};
	checkResult(g, 2);
    int h[] = {1, 1, 1};
	checkResult(h, 3);
    int i[] = {1, 1, -2};
	checkResult(i, 3);
    int j[] = {-2,0,1,1,2};
	checkResult(j, 5);
    int k[] = {3,0,3,2,-4,0,-3,2,2,0,-1,-5};
	checkResult(k, 12);
    int l[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
	checkResult(l, 16);
    return 0;
}