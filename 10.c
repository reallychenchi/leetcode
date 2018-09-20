#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

bool isMatch(char* s, char* p) {
    bool isAny = false;
    char * pre = NULL;
    while(*s != 0 && *p != 0){
        if (*s == *p || *p == '.'){
            if (*(p + 1) == '*'){
                if (isMatch(s, p + 2)){
                    return true;
                }
            }
            pre = s;
            isAny = (*p == '.');
            s++;
            p++;
        }else if (*p == '*'){
            if (NULL == pre){
                p++;
                continue;
            }
            if (*s == *pre || isAny){
                s++;
            }else{
                for(int i = 1; i < s - pre; ++i){
                    if (isMatch(pre + i, p + 1)){
                        return true;
                    }
                }
                p++;
                continue;
            }
        }else if (*(p + 1) == '*'){
            p += 2;
            pre = NULL;
            isAny = false;
        }else{
            return false;
        }
    }
    char *pCheck = p;
    while(*s == 0 && *pCheck != 0){
        if (*pCheck == '*'){
            pCheck++;
        }else if (*(pCheck + 1) == '*'){
            pCheck++;
        }else{
            break;
        }
    }
    bool ret = *s == 0 && *pCheck == 0;
    if (ret){
        return true;
    }else if (*p == '*' && pre != NULL){
        for(int i = 1; i < s - pre; ++i){
            if (isMatch(pre + i, p + 1)){
                return true;
            }
        }
    }
    return false;
}

void checkResult(char * a, char * p, bool r){
    if (r == isMatch(a, p)){
        printf("PASS: %s, %s\n", a, p);
    }else{
        printf("Failed: %s - %s\n", a, p);
    }
}

int main(){
	checkResult("abc", "abc", true);
	checkResult("abc", "a*", false);
	checkResult("abc", "a*c", false);
	checkResult("abc", "a.*c", true);
	checkResult("abcbcbc", "a*c", false);
	checkResult("abd", "abc", false);
	checkResult("add", "a*c", false);
	checkResult("abcbcbb", "a*c", false);
	checkResult("abcbcbb", "a*c*", false);
	checkResult("abcbcbb", "*", false);
	checkResult("a", ".*", true);
	checkResult("a", "*", false);
	checkResult("z", ".", true);
	checkResult("zb", ".", false);
	checkResult("zb", "..", true);
	checkResult("acb", "a*c*b.", false);
	checkResult("b", "c*a*b", true);
	checkResult("mississippi", "mis*is*p*.", false);
	checkResult("aa", "*a", false);
	checkResult("aaac", "a*ac", true);
	checkResult("aaaaac", "a*aac", true);
	checkResult("aaaaac", "aa*aac", true);
	checkResult("aaaaac", "aaa*aac", true);
	checkResult("aaaaac", "aa*aaac", true);
	checkResult("aaaaac", "aaa*aaac", false);
	checkResult("ab", ".*", true);
	checkResult("a", "ab*", true);
	checkResult("a", "a.*", true);
	checkResult("abdxac", ".*ac", true);
	checkResult("xyabdxac", "xy.*ac", true);
	checkResult("xyabdxac", "xy.*ac", true);
	checkResult("xyabdxac", "xy.*bd.*ac", true);
	checkResult("xyabdxacbdacbdac", "xy.*bd.*ac", true);
	checkResult("a", "a*a", true);
	checkResult("a", "b*a", true);
	checkResult("bbbba", ".*a*a", true);
	checkResult("bbbba", ".*a*a*a", true);
    return 0;
}