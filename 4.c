#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/median-of-two-sorted-arrays/
int smallerCount(int * nums, int start, int end, int data){
    while(start != end){
        int midIdx = (start + end) / 2;
        int c = nums[midIdx];
        if (c > data){
            end = midIdx;
        }else if (c == data){
            return midIdx;
        }else{
            start = midIdx;
        }
    }
    
    if (nums[start] > data){
        if (start - 1 > 0){
            return start - 1; 
        }else{
            return 0;
        }
    }else{
        return start;
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    /*
    int median1, median2;
    int sum = nums1Size + nums2Size;
    if (sum %2 == 0){
        media1 = sum / 2;
        media2 = media1 - 1;
    }else{
        media1 = media2 = (sum + 1) / 2;
    }
    
    int idx = nums1Size / 2;
    int data = nums1[idx];
    int smaller = smallerCount(nums2, 0, nums2Size, data) + idx - 1;
    while(smaller != media1){
        idx += (media1 - smaller) / 2;   
        if (idx > nums1Size){
            data = nums2[idx];
        }else if (idx < 0){
            
        }
    }*/
    int sum = nums1Size + nums2Size;
    int * nums = malloc(sizeof(int) * sum);
    for(int i = 0; i < nums1Size; ++i){
        nums[i] = nums1[i];
    }
    
    for(int i = 0; i < nums2Size; ++i){
        nums[i + nums1Size] = nums2[i];
    }
    
    for(int i = 0; i < sum ; ++i){
        for(int j = 0; j < sum; ++j){
            if (nums[j] < nums[i]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    int m1, m2;
    if (sum %2 == 0){
        m1 = sum / 2;
        m2 = m1 - 1;
    }else{
        m1 = (sum - 1) / 2;
        m2 = m1;
    }
    return (nums[m1] + nums[m2]) / 2.0;
}

void checkResult(int *s1, int sz1, int *s2, int sz2, double a){
    double b = findMedianSortedArrays(s1, sz1, s2, sz2);
    if (a == b){
        printf("PASS: %f\n", a);
    }else{
        printf("Failed: %f - %f\n", a, b);
    }
}

int main(){
    int s1[] = {1, 3};
    int s2[] = {2};
	checkResult(s1, 2, s2, 1, 2.0);
    return 0;
}