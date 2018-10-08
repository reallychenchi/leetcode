#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
#define INT_MAX __INT_MAX__
typedef int bool;
#define PT printf

//https://leetcode.com/problems/generate-parentheses/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int addParentes(char **ret, int *idx, int len, int l, int r){
    char *s = ret[*idx];
    if (l == r){
        s[len] = '(';
        int rr = addParentes(ret, idx, len + 1, l - 1, r);
        PT("LEN_EQU %d, %d\n", *idx, rr);
        return rr;
    }else if (l == 0){
        while(r > 0){
            s[len++] = ')';
            r--;
        }
        PT("LEN_DONE %d, %s\n", *idx, s);
        return 1;
    }else{
        s[len] = '(';
        s[len + 1] = 0;
        int lRet = addParentes(ret, idx, len + 1, l -1, r);

        *idx = *idx + 1;
        ret[*idx] = malloc((len + l + r + 1) * sizeof(char));
        memcpy(ret[*idx], s, len + l + r + 1);
        s = ret[*idx];
        s[len] = ')';
        s[len + 1] = 0;
        PT("LEN_L %d, %d\n", lRet, *idx);
        int rRet = addParentes(ret, idx, len + 1, l, r - 1);
        PT("LEN_R %d, %d, %d\n", lRet, rRet, *idx);
        return rRet + lRet;
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char ** ret = malloc(sizeof(char *) * n * n * n * n);
    *returnSize = 0;
    ret[0] = malloc((2 * n + 1) * sizeof(char));
    ret[0][2 * n] = 0;
    *returnSize = addParentes(ret, returnSize, 0, n, n);
    return ret;
}

void checkResult(int n){
    int rs = 0;
    char ** ret = generateParenthesis(n, &rs);
    PT("\nCHECK:\t%d, %d\n", rs, n);
    for(int i = 0; i < rs; ++i){
        PT("%s, ", ret[i]);
    }
    PT("\n");
}

int main(){
	checkResult(7);
    return 0;
}