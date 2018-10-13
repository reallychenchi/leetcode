#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
#define PT printf


//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int ret = 1;
    int delta = 0;
    int lastNum = nums[0];
    while(ret + delta < numsSize)
    {
        if (nums[ret + delta] == lastNum)
        {
            delta++;
        }
        else
        {
            nums[ret] = nums[ret + delta];
            lastNum = nums[ret];
            ret++;
        }
    }
    return ret;
}

int main(){
    int *data = malloc(sizeof(int) * 10);
    for(int i = 0; i < 5; ++i){
        data[i*2] = i;
        data[i*2 + 1] = i;
    }
    int r = removeDuplicates(data, 1);
    for(int i = 0; i < r; ++i){
        PT("%d, ", data[i]);
    }
    PT("\n");
    return 0;
}
 