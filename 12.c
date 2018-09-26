#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/integer-to-roman/

int intToRomanDig(int n, char i, char v, char x, char* ret){
    int sz = 0;
    if (n == 0){
        return sz;
    }else if (n < 4){
        sz = n;
        ret = ret - sz;
        memset(ret, i, n);
    }else if (n < 5){
        sz = 2;
        ret = ret - sz;
        ret[0] = i;
        ret[1] = v;
    }else if (n == 5){
        sz = 1;
        ret = ret - sz;
        ret[0] = v;
    }else if (n < 9){
        sz = n - 5 + 1;
        ret = ret - sz;
        ret[0] = v;
        memset(ret + 1, i, n - 5);
    }else if (n == 9){
        sz = 2;
        ret = ret - sz;
        ret[0] = i;
        ret[1] = x;
    }
    return sz;
}

char* intToRoman(int num) {
    char * ret = malloc(21);
    ret[20] = 0;
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    n1 = intToRomanDig(num % 10, 'I', 'V', 'X', ret + 20);
    num = num / 10;
    n2 = intToRomanDig(num % 10, 'X', 'L', 'C', ret + 20 - n1);
    num = num / 10;
    n3 = intToRomanDig(num % 10, 'C', 'D', 'M', ret + 20 - n1 - n2);
    num = num / 10;
    n4 = intToRomanDig(num % 10, 'M', 'Z', 'Y', ret + 20 - n1 - n2 - n3);
    return ret + 20 - n1 - n2 - n3 - n4;
}

void checkResult(int num, char *r){
    char* a = intToRoman(num);
    if (strcmp(a, r) == 0){
        printf("PASS: %d: %s\n", num, a);
    }else{
        printf("Failed: %d : %s - %s\n", num, r, a);
    }
}

int main(){
	checkResult(3, "III");
	checkResult(4, "IV");
	checkResult(5, "V");
	checkResult(9, "IX");
	checkResult(58, "LVIII");
	checkResult(1994, "MCMXCIV");
	checkResult(80, "LXXX");
	checkResult(808, "DCCCVIII");
    return 0;
}