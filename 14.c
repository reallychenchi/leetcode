#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/longest-common-prefix/

char* longestCommonPrefix(char** strs, int strsSize) {
   int p = 0;
   char c = 0;
   if (strsSize > 0) {
       c = strs[0][0];
       p = -1;
   }
   while(c != 0){
       p++;
       c = strs[0][p];
       for(int i = 0; i < strsSize; ++i){
            if (strs[i][p] != c && c != 0){
                c = 0;
                break;
            }
        }
   }
   if (p == -1) p = 0;
   char *s = malloc(p + 1);
   memcpy(s, strs[0], p);
   s[p] = 0;
   return s;
}

void checkResult(char ** strs, int sz, char * r){
    char * s = longestCommonPrefix(strs, sz);
    if (strcmp(s, r) == 0){
        printf("PASS: %s\n", s);
    }else{
        printf("Failed: %s - %s\n", r, s);
    }
}

int main(){
    char * s[] = {"flew", "fleww", "flewww"}; 
	checkResult(s, 3, "flew");
	checkResult(s, 0, "");
    char * s1[] = {"xflew", "fleww", "flewww"}; 
	checkResult(s1, 3, "");
    char * s2[] = {"flew", "fleww", "xflewww"}; 
	checkResult(s2, 3, "");
    char * s3[] = {""};
	checkResult(s3, 1, "");
    return 0;
}