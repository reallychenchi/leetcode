#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
#define PT printf

//https://leetcode.com/problems/valid-parentheses/
struct StackNode{
    char c;
    struct StackNode *next;
};

void pushStack(char c, struct StackNode **s){
    struct StackNode *p = NULL;
    p = malloc(sizeof(struct StackNode));
    p->c = c;
    p->next = *s;
    *s = p;
}

char popStack(struct StrackNode **s){
    if (NULL == *s) return 0;
    struct StackNode *p = *s;
    *s = p->next;
    char ret = p->c;
    free(p);
    return ret;
}

bool isValid(char* s) {
    struct StackNode *stack = NULL;
    while(*s != 0){
        if (*s == '(' || *s == '[' || *s == '{'){
            pushStack(*s, &stack);
        }else{
            char c = popStack(&stack);
            switch(c){
                case '(':
                    if (*s != ')') return false;
                    break;
                case '[':
                    if (*s != ']') return false;
                    break;
                case '{':
                    if (*s != '}') return false;
                    break;
                default:
                    return false;
            }
        }
        s++;
    }

    return stack == NULL;
}
void checkResult(char * a, bool ret){
    if (isValid(a) == ret){
        PT("PASS: %s, %d\n", a, ret);
    }else{
        PT("FAIL: %s, %d\n", a, ret);
    }
}

int main(){
    checkResult("()", true);
    checkResult("({})", true);
    checkResult("({[]})", true);
    checkResult("({[]}){", false);
    checkResult("(]", false);
    return 0;
}