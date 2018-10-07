#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
#define INT_MAX __INT_MAX__
typedef int bool;
#define PT printf

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
char getLetter(char c, char now){
    char head = (c - '2') * 3 + 'a';
    if (c > '7') head++;

    if (0 == now) return head;
    else {
        char ret = now + 1;
        if (ret - head == (c == '9' || c =='7' ? 4 : 3)) return 0;
        else return ret;
    }
}

void writeLetter(char ** data, char * digits, int s, int e, int idx){
    char digit = *digits;
    if (digit == 0) return;

    char now = getLetter(digit, 0);
    int ss = s;
    int se = (e - s) / (digit == '9' || digit == '7' ? 4 : 3);
    do{
        for(int i = 0; i < se; ++i){
            data[i + ss][idx] = now;
        }
        writeLetter(data, digits + 1, ss, ss + se, idx + 1);
        now = getLetter(digit, now);
        ss += se;
    }while(now != 0);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    int totalLen = 0;
    int strLen = 0;
    char *p = digits;
    while(*p != 0){
        strLen++;
        if (totalLen == 0) totalLen = 1;
        if (*p == '9' || *p == '7'){
            totalLen *= 4;
        }else{
            totalLen *= 3;
        }
        p++;
    }  
    char ** ret = malloc(totalLen * sizeof(char *));
    for(int i = 0; i < totalLen; ++i){
        ret[i] = malloc((strLen + 1) * sizeof(char));
        ret[i][strLen] = 0;
    }
    *returnSize = totalLen;
    writeLetter(ret, digits, 0, totalLen, 0);
    return ret;
}

void checkResult(char *digits){
    int rs = 0;
    char ** ret = letterCombinations(digits, &rs);
    PT("\nCHECK:\t%d, %s\n", rs, digits);
    for(int i = 0; i < rs; ++i){
        PT("%s, ", ret[i]);
    }
    PT("\n");
}

int main(){
	checkResult("23");
	checkResult("234");
	checkResult("92");
	checkResult("9");
	checkResult("7");
    return 0;
}