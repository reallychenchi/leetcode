#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
#define PT printf

//https://leetcode.com/problems/4sum/
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
    sort(r, 0, 4);
    for(int i = 0; i < sz; ++i){
        int *data = ret[i];
        int j = 0;
        for(; j < 4; ++j){
            if (r[j] != data[j]){
                break;
            }
        }
        if (j == 4) return true;
    }

    return false;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int ** ret = malloc(numsSize * numsSize * sizeof(int *));
    *returnSize = 0;
    if (numsSize < 4) return ret;

    int *r = malloc(4 * sizeof(int));
    for(int i = 0; i < numsSize - 3; ++i){
        r[0] = nums[i];
        for(int j = i + 1; j < numsSize - 2; ++j){
            r[1] = nums[j];
            for(int k = j + 1; k < numsSize - 1; ++k){
                r[2] = nums[k];
                r[3] = target - r[2] - r[1] - r[0];
                for(int l = k + 1; l < numsSize; ++l){
                    if (r[3] == nums[l] && !isExists(r, ret, *returnSize)){
                        ret[*returnSize] = r;
                        *returnSize = *returnSize + 1;
                        r = malloc(4 * sizeof(int));
                        r[0] = nums[i];
                        r[1] = nums[j];
                        break;
                    }else{
                        r[0] = nums[i];
                        r[1] = nums[j];
                        r[2] = nums[k];
                        r[3] = target - r[2] - r[1] - r[0];
                    }
                }
            }
        }
    }
    return ret;
}

int main(){
    return 0;
}