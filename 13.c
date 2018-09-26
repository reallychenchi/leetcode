#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/roman-to-integer/

char * ROMAN = "MDCLXVI";
int romanToIntDig(char roman){
    switch (roman){
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        case 0: return 0;
    }
    printf("IN CORRECT ROMAN %c\n", roman);
    return -1;//Incorrect case
}

int romanToInt(char* s) {
    int ret = 0;
    while(*s != 0){
        int a = romanToIntDig(*s);
        int b = romanToIntDig(*(s + 1));
        if (a >= b){
            ret += a;
            s++;
        }else{
            ret += (b - a);
            s += 2;
        }
    }

    return ret;
}

void checkResult(int num, char *r){
    int a = romanToInt(r);
    if (a == num){
        printf("PASS: %s: %d\n", r, a);
    }else{
        printf("Failed: %s : %d - %d\n", r, a, num);
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