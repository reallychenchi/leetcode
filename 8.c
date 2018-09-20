#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/string-to-integer-atoi/
#define PT

int myAtoi(char* str) {
    int s = 1;
    int ret = 0;
    
    while(*str == 0x20){
        str++;
    }
    
    if (*str == '-'){
        s = -1;
        str++;
    }else if (*str == '+'){
        str++;
    }
    
    while(*str != 0){
        int n = *str - '0';
        PT("%d, %c\n", n, *str);
        if (n < 0 || n > 9){
            break;
        }
        if (s > 0){
            if (INT_MAX / 10 < ret)
                return INT_MAX;
        }else{
            if (INT_MIN / 10 > 0 - ret)
                return INT_MIN;
        }
        ret *= 10;

        if (s > 0){
            if (INT_MAX - n < ret)
                return INT_MAX;
        }else{
            if (INT_MIN + n > 0 - ret)
                return INT_MIN;
        }
        ret += n;
        str++;
    }
    
    return ret * s;
}

void checkResult(char * s, int a){
    int b = myAtoi(s);
    if (a == b){
        printf("PASS: %s\n", s);
    }else{
        printf("Failed: %s, %d\n", s, b);
    }
}

int main(){
	checkResult("42", 42);
	checkResult("-121", -121);
	checkResult("23423635235434", INT_MAX);
	checkResult("-23423635235434", INT_MIN);
    return 0;
}