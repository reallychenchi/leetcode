#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/container-with-most-water/
int maxArea(int* height, int heightSize){
    int a = 0;
    for(int i = 0; i < heightSize; ++i){
        for(int j = i; j < heightSize; ++j){
            int r = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
            if (r > a){
                a = r;
            }
        }
    }

    return a;
}

int maxArea1(int* height, int heightSize){
    int a = 0;
    int *p1 = height;
    int *p2 = height + heightSize - 1;
    while(p1 != p2){
        int r = (p2 - p1) * (*p1 > *p2 ? *p2 : *p1);
        if (r > a){
            a = r;
        }
        if (*p1 < *p2){
            p1++;
        }else{
            p2--;
        }
    }
    return a;
}

void checkResult(int *height, int sz, int r){
    int b = maxArea1(height, sz);
    if (r == b){
        printf("PASS: %d\n", b);
    }else{
        printf("Failed: %d - %d\n", r, b);
    }
}

int main(){
    int h[] = {1,8,6,2,5,4,8,3,7};
	checkResult(h, 9, 49);
    return 0;
}