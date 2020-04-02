#include<stdio.h>
#include<stdlib.h>

int isParenthesisValid(char *s, int size);

int main (void) {
    char *sptr = NULL;
    size_t maxlen = 1000;
    int ssize = EOF+1;
    int isValid = 0;

   while (ssize != EOF) {
       sptr = (char *) malloc(sizeof(char)*maxlen);
       ssize = getline(&sptr, &maxlen, stdin);

       isValid = isParenthesisValid(sptr, ssize);

       if(ssize != EOF) {
           if (isValid == 1)
               printf("VALID");
           else if (isValid == 0)
               printf("NOT VALID");
       }
       free(sptr);
   }
   return 0;
}

int isParenthesisValid(char *s, int size) {
    char *arr = NULL;
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
                free(arr);
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
                    free(arr);
                    return 0;
                }
            }
        }
    }
    if (cnt > 0) {
        free(arr);
        return 0;
    }
    else {
        free(arr);
        return 1;
    }
}
