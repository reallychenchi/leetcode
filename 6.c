#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/zigzag-conversion
int getIdx(int i, int r, int len){
    int u = r * 2 - 2;
    int uN = len / u;
    int x = i % u;
    int y = i / u;
    if (x == 0){//Top
        return y;
    }else if (x == r - 1){ 
        return (u - 1) * uN + y;
    }else if (x < r){//Left + y
        return uN + 2 * (x - 1) * uN + y * 2; 
    }else{//Right
        return  uN + 2 * (u - x - 1) * uN + y * 2 + 1; 
    }
}

char* convert(char* s, int numRows) {
    int len = strlen(s);
    int uLen = 2 * numRows - 2;
    if (0 == uLen) return s;//Sepcial case
    
    int fullLen = len + uLen - len % uLen;
    char * r = malloc(fullLen + 1);
    memset(r, 0, fullLen + 1);
    for(int i = 0; i < fullLen; ++i){
        int idx = getIdx(i, numRows, fullLen);
        if (i < len){
            r[idx] = s[i];
        }else{
            r[idx] = 0;
        }
    }
    int c = 0;
    for(int i = 0; i < fullLen; ++i){
        if (r[i] != 0){
            r[c++] = r[i];
        }
    }
    r[c++] = 0;
    
    return r;
}

int main(){
    return 0;
}
