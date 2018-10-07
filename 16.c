#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
#define INT_MAX __INT_MAX__
typedef int bool;
#define PT printf

//https://leetcode.com/problems/3sum-closest/
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

int searchNear(int *nums, int s, int e, int k){
    int m;
    while(s < e){
        m = (s + e) / 2;
        if (k > nums[m]){
            e = m;
        }else if (k == nums[m]){
            return m;
        }else{
            s = m + 1;
        }
    }
    if (s == e){
        return e;
    }
    return -1;
}

int search(int *nums, int s, int e, int k){
    int m;
    while(s < e){
        m = (s + e) / 2;
        if (k > nums[m]){
            e = m;
        }else if (k == nums[m]){
            return m;
        }else{
            s = m + 1;
        }
    }

    return -1;
}

bool isExists(int *r, int** ret, int sz){
    sort(r, 0, 3);
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

int threeSumClosest(int* nums, int numsSize, int target) {
    int ret = 0;
    int ret_delta = INT_MAX;
    if (numsSize < 3) return 0;

    int sum = 0;
    for(int i = 0; i < numsSize - 2; ++i){
        for(int j = i + 1; j < numsSize - 1; ++j){
            for(int k = j + 1; k < numsSize; ++k){
                sum = nums[i] + nums[j] + nums[k];
                int delta = sum - target;
                if (delta < 0) delta = 0 - delta;
                if (delta < ret_delta){
                    ret_delta = delta;
                    ret = sum;
                }
            }
        }
    }
    return ret;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int target) {
    int ** ret = malloc(numsSize * numsSize * sizeof(int *));
    *returnSize = 0;
    if (numsSize < 3) return ret;

    sort(nums, 0, numsSize);    
    int zeroIdx = searchNear(nums, 0, numsSize, 0);
    if (zeroIdx < target || zeroIdx >= numsSize) return ret;//TODO
    int zeroIdxI = zeroIdx;
    while(nums[zeroIdxI] == 0 && zeroIdxI > 0){zeroIdxI--;}
    zeroIdxI++;
    int zeroIdxJ = zeroIdx;
    while(nums[zeroIdxJ] == 0 && zeroIdxJ < numsSize){zeroIdxJ++;}
    zeroIdxJ--;
    
    int *r = malloc(3 * sizeof(int));

    if (zeroIdxJ - zeroIdxI >= 2){
        memset(r, 0, 3 * sizeof(int));
        ret[*returnSize] = r;
        *returnSize = *returnSize + 1;
        r = malloc(3 * sizeof(int));
    }
    for(int i = 0; i < zeroIdxI; ++i){
        r[0] = nums[i];
        for(int j = numsSize - 1; j >= zeroIdxJ; --j){
            r[2] = nums[j];
            r[1] = 0 - r[2] - r[0];
            int r3Idx = search(nums, i + 1, j, r[1]);
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

void checkResult(int * a, int sz, int target, int ret){
    PT("\nCHECK:\t");
    for(int i = 0; i < sz; ++i){
        PT("%d, ", a[i]);
    }
    PT("\n");

    int r = threeSumClosest(a, sz, target);
    if (r == ret){
        PT("PASS %d\n", r);
    }else{
        PT("FAIL %d, %d\n", ret, r);
    }
}

int main(){
    int a[] = {1, 1, 1, 0};
	checkResult(a, 4, 100, 3);
    return 0;
}