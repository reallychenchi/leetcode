#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/palindrome-number/

bool isPalindrome(int x) {
    if (x < 0) return false;
    int r = 0;
    int r0 = x;
    while(x > 0){
        r *= 10;
        r += x % 10;
        x /= 10;
    }
    return r == r0;
}

void checkResult(int a, bool r){
    if (r == isPalindrome(a)){
        printf("PASS: %d\n", a);
    }else{
        printf("Failed: %d\n", a);
    }
}

int main(){
	checkResult(121, true);
	checkResult(-121, false);
	checkResult(10, false);
    return 0;
}