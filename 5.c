#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;

//https://leetcode.com/problems/longest-palindromic-substring/submissions/
int judge(char* check, char* current){
    int max = 1;
    char* left = current; 
    char* right = current;
    do{
        right++;
        max++;
    }while(*right == *left && *right != 0);
    right--;
    max--;

    while(left != check && *right != 0){
        left--;
        right++;
        
        if (*right == *left){
            max += 2;
        }else{
            left++;
            break;
        }
    }
    if (left == check){
        return max;
    }else{
        return -1;
    }
}

char* longestPalindrome(char* s) {
    char* current = s;
    char* max = s;
    int maxLen = 1;
    while(*current != 0){
        char* check = s;
        do{
            int len = judge(check, current);
            if (len > maxLen){
                maxLen = len;
                max = check;
                break;
            }
        }while(check++ != current);
        current++;
    }
    
    max[maxLen] = 0;
    return max;
}

int main(){
    return 0;
}
