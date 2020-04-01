#include<stdio.h>
#include<stdlib.h>

int isParenthesisValid(char *s, int size);

int main (void) {

    char *sptr;
    size_t maxlen = 1000;
    int ssize = 0;

   while (ssize != -1) {
       sptr = (char *) malloc(sizeof(char)*maxlen);
       ssize = getline(&sptr, &maxlen, stdin);
       
       if (ssize == -1)
           return 0;
       else if (isParenthesisValid(sptr, ssize) == 1)
           printf("VALID");
       else
           printf("NOT VALID");
    }
   free(sptr);
    return 0;
}

int isParenthesisValid(char *s, int size) {
    char *arr;
    arr = (char *) malloc(sizeof(char)*size);
    int cnt = 0;
    int i = 0;

    for (i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            arr[cnt] = s[i];
            cnt++;
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (cnt == 0) {
                return 0;
            }
            else {
                if (arr[cnt-1] == '(' && s[i] == ')') {
                    cnt--;
                }
                else if (arr[cnt-1] == '[' && s[i] == ']') {
                    cnt--;
                }
                else if (arr[cnt-1] == '{' && s[i] == '}') {
                    cnt--;
                }
                else {
                    return 0;
                }
            }
        }
    }
    free(arr);
    if (cnt > 0) {
        return 0;
    }
    else
        return 1;
}
