#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/reverse-integer/
bool isOverflowPlus(int a, int b, int s){
    if (s > 0){
        return INT_MAX - b < a;
    }else{
        return INT_MIN - b > a;
    }
}

bool isOverflowMulti(int a, int b){
    return INT_MAX / b < a;
}

int reverse(int x) {
    int r = 0;
    int s = x > 0 ? 1 : -1;
    while(x / 10 * s > 0){
        if (isOverflowPlus(r, x % 10, s)) return 0;
        r += x % 10;
        if (isOverflowMulti(r, 10)) return 0;
        r *= 10;
        if (r * s < 0) return 0;
        x /= 10;
    }
    return r + x % 10;
}

int main(){
    return 0;
}
